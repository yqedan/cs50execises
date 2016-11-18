#include <stdio.h>
#include <cs50.h>
#include <string.h>

char transform(char x, int k);

int main(int argc, string argv[]){
    if(argc < 2){
        printf("Usage: ./caesar [k]\n");
        return 1;
    }
    string x = GetString();
    for(int i = 0 ; i < strlen(x) ; i++){
        printf("%c", transform(x[i], atoi(argv[1])));
    }
    printf("\n");
    return 0;
}
char transform(char x, int k){
    int y = (int) x;
    int caps = 0;
    if( (y > 96 && y < 123) || (y > 64 && y < 91) ){ //is it a letter
        if(y >= 97){ //is it a lower case letter
            caps = 32;
        }
        y -= (65 + caps);
        y += k;
        y = y % 26;
        y += (65 + caps);
        x = (char) y;
    }
    return x;
}