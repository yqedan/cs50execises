/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// constants
#define DIM_MIN 1
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// god mode
bool godMode = false;

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(string tile);
bool won(void);
int godMove();

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }
        char* tile = NULL;
        if(godMode)
        {
            //make move
            tile = malloc(sizeof(char));
            int tileInt = godMove();
            sprintf(tile, "%d", tileInt);
        }
        else
        {
            // prompt for move
            printf("Tile to move: ");
            tile = GetString();
        }
        
        // quit if user inputs 0 (for testing)
        if (strcmp(tile,"0") == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%s\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\n%s is an Illegal move.\n",tile);
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
        free(tile);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int x = d * d - 1;
    for(int row = 0; row < d ; row++)
    {
        for(int col = 0; col < d ; col++)
        {   
            if(d % 2 == 0 && x == 1 )
            {
                board[row][col] = 2;
                x--;
            }
            else if(d % 2 == 0 && x == 2 )
            {
                board[row][col] = 1;
                x--;
            }
            else
            {
                board[row][col] = x;
                x--;
            }
        }
    }
    //random moves are below
    srand48((long int) time(NULL));
    int tileInt = 0;
    char tile[1];
    for(int i = 0; i < 100000; i++)
    {
        tileInt = (int) (drand48() * d * d);
        sprintf(tile, "%d", tileInt);
        move(tile);
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int row = 0; row < d ; row++)
    {
        for(int col = 0; col < d ; col++)
        {   
            if(board[row][col] < 10)
            {
                if(board[row][col] == 0)
                {
                    printf(" %c ",'_');
                }
                else
                {
                    printf(" %i ",board[row][col]);
                }
            }
            else
            {
                printf("%i ",board[row][col]);
            }
        }
         printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(string tileString)
{
    if(strcmp(tileString,"GOD") == 0)
    {
        godMode = true;
        return true;
    }
    int tile = atoi(tileString);
    int row;
    int col;
    bool found = false;
    
    for(row = 0; row < d ; row++)
    {
        for(col = 0; col < d ; col++)
        {  
            if(board[row][col] == tile) //locate row and column of tile user entered
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            break;
        }
    }
    
    if(found)
    {
        if(row > 0 && board[row-1][col] == 0)           //above
        {
            //printf("moving above");
            board[row-1][col] = tile;
        }
        else if(col < (d-1) && board[row][col+1] == 0)  //right
        {
            //printf("moving right");
            board[row][col+1] = tile;
        }
        else if(row < (d-1) && board[row+1][col] == 0)  //below
        {    
            //printf("moving below");
            board[row+1][col] = tile;
        }
        else if(col > 0 && board[row][col-1] == 0)     //left
        {
            //printf("moving left");
            board[row][col-1] = tile;
        }
        else{
            return false;
        }
        board[row][col] = 0;    //zero out previous space
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    bool won = true;
    for(int row = 0; row < d ; row++)
    {
        for(int col = 0; col < d ; col++)
        {
            if(row == (d-1) && col == (d-1))    //special case for last tile that must be 0
            {   
                if(board[row][col] != 0)
                {
                    won = false;
                    break;  //quit looping if it is already proven the player did not win
                }
            }
            else
            {
                if(board[row][col] != (row * d + col + 1))  //all other tiles must equal this number calculated here
                {
                    won = false;
                    break;  //quit looping if it is already proven the player did not win
                }
            }
        }
        if(!won)    //quit looping if it is already proven the player did not win
        {
            break;
        }
    }
    return won;
}

int godMove()
{
    //god mode code will go here
    return (int) (drand48() * (d * d - 1)) + 1;
}