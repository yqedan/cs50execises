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
    
    return false;
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
            printf("looking at %d and %d\n",values[i],values[i+1]);
            if(values[i] > values[i+1]){
                sorted = false;
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("#%d in the list: %d\n",i,values[i]);
    }
    return;
}