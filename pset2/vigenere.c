#include <stdio.h>
#include <cs50.h>
#include <string.h>

char transform(char x, int k);
int transformCharToInt(char c);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./vigenere [k]\n");
        return 1;
    }
    int goodKeyWord = 1;
    string k = argv[1];
    for(int i = 0 ; i < strlen(k) ; i++){
        int y = (int) k[i];
        if( !((y > 96 && y < 123) || (y > 64 && y < 91)) ){ //is it not a letter
            goodKeyWord = 0;
        }
    }
    if(goodKeyWord == 1){
        string x = GetString();
        int j = 0;
        for(int i = 0 ; i < strlen(x) ; i++){
            printf("%c", transform(x[i], transformCharToInt(k[j])));
            int y = (int) x[i];
            if( (y > 96 && y < 123) || (y > 64 && y < 91) ){ //is it a letter
                if(j < (strlen(argv[1]) - 1)){
                    j++;            
                }else{
                    j = 0;
                }
            }
        }
        printf("\n");
    }else{
        printf("Bad keyword\n");
        return 1;
    }
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

int transformCharToInt(char x){
    int y = (int) x;
    int caps = 0;
    if( (y > 96 && y < 123) || (y > 64 && y < 91) ){ //is it a letter
        if(y >= 97){ //is it a lower case letter
            caps = 32;
        }
        y -= (65 + caps);
        x = (char) y;
    }
    return x;
}