#include <stdio.h>
#include <cs50.h>

long long exponent(int x, int y){
    long long rv = 1;
    for(int i = 0; i < y; i++){
        rv *= x;
    }
    return rv;
}

int main(void){
    printf("Enter a card number\n");
    long long cardNumber = GetLongLong();
    //alternative to line 14 commented below for those that dont have cs50.h
    //scanf ("%lld",&cardNumber);
    int sum = 0;
    int firstDigit = 0;
    int secondDigit = 0;
    int currentDigit = 0;
    int previousDigit = 0;
    int currentEvenDigitOnes = 0;
    int cardNumberLength = 0;
    if(cardNumber > 1000000000000000LL){        //16 digit
        cardNumberLength = 16;
    }else if(cardNumber > 100000000000000LL){   //15 digit
        cardNumberLength = 15;
    }else{                                      //13 digit
        cardNumberLength = 13;
    }
    for(int i = (cardNumberLength-1); i >= 0 ;i--){
        cardNumber -= previousDigit*exponent(10,i+1);
        currentDigit = ((cardNumber - (cardNumber % exponent(10,i)))/exponent(10,i));
        previousDigit = currentDigit;
        if(i == (cardNumberLength-1)){
            firstDigit = currentDigit;
        }else if(i == (cardNumberLength - 2)){
            secondDigit = currentDigit;
        }
        if(i % 2 != 0){
            if((currentDigit * 2) > 9){
                currentEvenDigitOnes = (2 * currentDigit) - 10;
                sum += (currentEvenDigitOnes + 1);
            }else{
                sum += (currentDigit * 2);
            }
        }else{
            sum += currentDigit;
        }
    }
    if(sum % 10 == 0){
        if(firstDigit == 4){
            printf("VISA\n");  
        }else if(firstDigit == 5 && 
                (secondDigit == 1 || 
                 secondDigit == 2 || 
                 secondDigit == 3 || 
                 secondDigit == 4 || 
                 secondDigit == 5 )){
            printf("MASTERCARD\n");
        }else if(firstDigit == 3 && 
                (secondDigit == 4 || 
                 secondDigit == 7 )){
            printf("AMEX\n");
        }
    }else{
        printf("INVALID\n");
    }
}
