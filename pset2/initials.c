#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string x = GetString();
    for(int i = 0 ; i < strlen(x) ; i++){
        if(i == 0){ // am I the first character?
            if((char) x[0] < 97){ //am I upper case?
                printf("%c", x[0]);//print
            }else{ //convert it to upper case and print
                printf("%c", (char) (( (int) x[0] ) - 32));
            }
        }
        if((int) x[i] == 32){ // am I a space ?
            if(i+1 < strlen(x)){ // If I am look ahead to the next char if possible
                if((char) x[i+1] < 97){ //am I upper case?
                    printf("%c", x[i+1]); //print
                }else{ //convert it to upper case and print
                    printf("%c", (char) (( (int) x[i+1] ) - 32));
                }
            }
        }
    }
    printf("\n");
}