#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string x = GetString();
    for(int i = 0 ; i < strlen(x) ; i++){
        if(i == 0){
            if((char) x[0] < 97){
                printf("%c", x[0]);
            }else{
                printf("%c", (char) (( (int) x[0] ) - 32));
            }
        }
        if((int) x[i] == 32){
            if(i+1 < strlen(x)){
                if((char) x[i+1] < 97){
                    printf("%c", x[i+1]);
                }else{
                    printf("%c", (char) (( (int) x[i+1] ) - 32));
                }
            }
        }
    }
    printf("\n");
}