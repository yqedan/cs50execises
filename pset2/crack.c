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
            found = 2;
            break;
        }
        i++;
    }
    
    char a;
    char test[9];
    //1 character
    if(found == 0){
        for(int j = 0;j < 95;j++){
            a = ((char) (32 + j));
            test[0] = a;
            guess = crypt(test,salt);
            if(strcmp(encPwd,guess) == 0){
                found = 1;
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
                    found = 1;
                    break;
                }
            }
            if(found == 1){
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
                        found = 1;
                        break;
                    }
                }
                if(found == 1){
                    break;
                }
            }
            if(found == 1){
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
                            found = 1;
                            break;
                        }
                    }
                    if(found == 1){
                        break;
                    }
                }
                if(found == 1){
                    break;
                }
            }
            if(found == 1){
                break;
            }
        }
    }
    
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
    //                             found = 1;
    //                             break;
    //                         }
    //                     }
    //                     if(found == 1){
    //                         break;
    //                     }
    //                 }
    //                 if(found == 1){
    //                     break;
    //                 }
    //             }
    //             if(found == 1){
    //                 break;
    //             }
    //         }
    //         if(found == 1){
    //             break;
    //         }
    //     }
    // }
    
    if(found == 1){
        printf("%s\n",test);
    }else if(found == 2){
        printf("%s",words[i]);
    }else if (found == 0){
        printf("Password is too strong\n");
    }
}
