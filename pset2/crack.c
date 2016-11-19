#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]){
    if(argc < 2){
        printf("Usage: ./crack [encrypted password]\n");
        return 1;
    }
    FILE *fp = fopen("/usr/share/dict/words", "r");
    char words[99170][29];
    char ch;
    string encPwd = argv[1];
    int i = 0;
    int found = 0;
    string guess;
    int w = 0; //word index
    int c = 0; //character index
    char salt[2];
    strncpy(salt, argv[1], 2);
    do{
        ch = getc(fp);
        words[w][c] = ch;
        c++;
        if(ch == '\n'){
            c = 0;
            w++;
        }
    }while(ch != EOF);
    fclose(fp);
    while(true){
        if(i == 99170){
            break;
        }
        guess = crypt(words[i],salt);
        if(strcmp(encPwd,guess) == 0){
            found = 1;
            break;
        }
        i++;
    }
    if(found == 1){
        printf("%s",words[i]);
    }else{
        printf("Password is too strong\n");
    }
}
