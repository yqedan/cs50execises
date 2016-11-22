/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool binarySearch(int value, int values[], int n);
bool linearSearch(int value, int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{   
    if(n < 1){
        return false;
    }
    //return linearSearch(value,values,n);
    return binarySearch(value,values,n);
}

bool linearSearch(int value, int values[], int n)
{
    for(int i = 0; i < n; i++){
        if(value == values[i]){
            return true;
        }
    }
    return false;
}

bool binarySearch(int value, int values[], int n)
{
    if(n==1){
        if(values[0] == value){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        bool rv;
        int half = n/2;
        // printf("half is %d\n",half);
        int odd = 0;
        if(n % 2 == 1){
            odd++;
            // printf("number is odd\n");
        }
        int* subset;
        if(value < values[half]){
            subset = malloc((half)*sizeof(int));
            // printf("reading left indexes %d - %d\n",0,half-1);
            for(int i = 0; i < half; i++){
               subset[i] = values[i];
            }
            // printf("subset list is: \n");
            // for(int i = 0; i < half; i++){
            //   printf("#%d in the list: %d\n",i,subset[i]);
            // }
            rv = binarySearch(value, subset, half);
            free(subset);
            return rv;
        }
        else{
            subset = malloc((half + odd)*sizeof(int));
            // printf("reading right indexes %d - %d\n",half,n-1);
            for(int i = half; i < (n + odd); i++){
               subset[i-half] = values[i];
            }
            // printf("subset list is: \n");
            // for(int i = 0; i < (half + odd); i++){
            //   printf("#%d in the list: %d\n",i,subset[i]);
            // }
            rv = binarySearch(value, subset, (half + odd));
            free(subset);
            return rv;
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{   
    bool sorted = false;
    int temp = 0;
    while(sorted == false){
        sorted = true;
        for(int i = 0; i < n-1; i++){
            // printf("looking at %d and %d\n",values[i],values[i+1]);
            if(values[i] > values[i+1]){
                sorted = false;
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
            }
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     printf("#%d in the list: %d\n",i,values[i]);
    // }
    return;
}