#include <stdio.h>
#include <cs50.h>

int main(void){
    int input;
    do{
        printf("Height:\t");
        input = GetInt();
        //scanf("%d",&input); GetInt() alternative if not using cs50.h
    }while(input < 0 || input > 23);
    for(int i = 1; i <= input; i++){
        for(int j = i; j < input; j++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("#");
        }
        printf("  ");
        for(int j = 0; j < i; j++){
            printf("#");
        }
        for(int j = i; j < input; j++){
            printf(" ");
        }
        printf("\n");
    }
}
