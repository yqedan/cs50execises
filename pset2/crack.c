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
    char words[99170][29];      //used to hold words for word lookup
    string encPwd = argv[1];    //encoded password
    int found = 0;              //keeps track if password was found or not
    string guess;               //passowrd guesses
    int w = 0;                  //word index
    int c = 0;                  //character index
    char salt[2];               //the salt
    strncpy(salt, argv[1], 2);  //salt is just first 2 characters of encrypted password
    char test[9];               //Used to store brute force word
    
    //open file of words and store them in large words array
    char a;
    do{
        a = getc(fp);
        words[w][c] = a;
        c++;
        if(a == '\n'){
            c = 0;
            w++;
        }
    }while(a != EOF);
    fclose(fp);
    
    //word lookup
    int i = 0;
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
    
    //1 character
    if(found == 0){
        for(int j = 0;j < 95;j++){
            a = ((char) (32 + j));
            test[0] = a;
            guess = crypt(test,salt);
            if(strcmp(encPwd,guess) == 0){
                found = 2;
                break;
            }
        }
    }
    
    //2 characters
    if(found == 0){
        for(int j = 0;j < 95;j++){
            a = ((char) (32 + j));
            test[0] = a;
            for(int k = 0;k < 95;k++){
                a = ((char) (32 + k));
                test[1] = a;
                guess = crypt(test,salt);
                if(strcmp(encPwd,guess) == 0){
                    found = 2;
                    break;
                }
            }
            if(found == 2){
                break;
            }
        }
    }
    
    //3 characters
    if(found == 0){
        for(int j = 0;j < 95;j++){
            a = ((char) (32 + j));
            test[0] = a;
            for(int k = 0;k < 95;k++){
                a = ((char) (32 + k));
                test[1] = a;
                for(int l = 0;l < 95;l++){
                    a = ((char) (32 + l));
                    test[2] = a;
                    guess = crypt(test,salt);
                    if(strcmp(encPwd,guess) == 0){
                        found = 2;
                        break;
                    }
                }
                if(found == 2){
                    break;
                }
            }
            if(found == 2){
                break;
            }
        }
    }
    
    //4 characters
    if(found == 0){
        for(int j = 0;j < 95;j++){
            a = ((char) (32 + j));
            test[0] = a;
            for(int k = 0;k < 95;k++){
                a = ((char) (32 + k));
                test[1] = a;
                for(int l = 0;l < 95;l++){
                    a = ((char) (32 + l));
                    test[2] = a;
                    for(int m = 0;m < 95;m++){
                        a = ((char) (32 + m));
                        test[3] = a;
                        guess = crypt(test,salt);
                        if(strcmp(encPwd,guess) == 0){
                            found = 2;
                            break;
                        }
                    }
                    if(found == 2){
                        break;
                    }
                }
                if(found == 2){
                    break;
                }
            }
            if(found == 2){
                break;
            }
        }
    }
    
    //will take hours to run and not worth the time
    
    //5 characters
    // if(found == 0){
    //     for(int j = 0;j < 95;j++){
    //         a = ((char) (32 + j));
    //         test[0] = a;
    //         for(int k = 0;k < 95;k++){
    //             a = ((char) (32 + k));
    //             test[1] = a;
    //             for(int l = 0;l < 95;l++){
    //                 a = ((char) (32 + l));
    //                 test[2] = a;
    //                 for(int m = 0;m < 95;m++){
    //                     a = ((char) (32 + m));
    //                     test[3] = a;
    //                     for(int n = 0;n < 95;n++){
    //                         a = ((char) (32 + n));
    //                         test[4] = a;
    //                         guess = crypt(test,salt);
    //                         if(strcmp(encPwd,guess) == 0){
    //                             found = 2;
    //                             break;
    //                         }
    //                     }
    //                     if(found == 2){
    //                         break;
    //                     }
    //                 }
    //                 if(found == 2){
    //                     break;
    //                 }
    //             }
    //             if(found == 2){
    //                 break;
    //             }
    //         }
    //         if(found == 2){
    //             break;
    //         }
    //     }
    // }
    
    if(found == 1){
        printf("%s",words[i]);
    }else if(found == 2){
        printf("%s\n",test);
    }else if (found == 0){
        printf("Password is too strong\n");
    }
}
