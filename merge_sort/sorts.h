#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    return 0; // modify to return the index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    // todo: implement selection sort
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    // TODO: Implement insertion sort
    if(size < 2){
        if(print){
            printIntArray(array, size);
        }
        return;
    }
    for(unsigned int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--){
            if(array[j] < array[j - 1]){
                swap(&array[j], &array[j - 1]);
            }
        }
        if (print) {
            printIntArray(array, size);
        }
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // code generated from lab
    for(unsigned int i = 0; i < size; i++){
        for(unsigned int j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
        if(print){
            printIntArray(array, size);
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    //if arr is NULL or temp is NULL, end this function.
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    //Invalid rang ckeck.
    if (l > m || m + 1 > r)
        return;

    // i mean index for left to mid sorted subarray.
    // j mean index for mid + 1 right sorted subarray.
    int i = l;
    int j = m + 1;
    int start = l;

    //Marge if i <= mid or j <= right.
    // Compare current element array left and arr right.
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[start++] = arr[i++];
        }
        else{
            temp[start++] = arr[j++];
        }
    }

    // if there still has remaining element, just copy them.
    while(i <= m){
        temp[start++] = arr[i++];
    }
    while(j <= r){
        temp[start++] = arr[j++];
    }

    // Copy the merge result.
    for(int k = l; k <= r; k++){
        arr[k] = temp[k];
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l == r){ // base case (stop making smaller blocks to be merged when the blocks reach size 1)
        return; 
    } 
        int mid = (l + r) / 2; //find the middle
        merge_sort(arr, temp, l, mid); //recursivley call merge sort again on the left half
        merge_sort(arr, temp, mid+1,r); //recursivley call merge sort again on the right half

        merge(arr,temp, l, mid, r); //merge two sorted halves together
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL) //If array is empty exit
    {
        exit(1);
    }
    if (size <= 1) //If size is less than or = to 1 list does not need to be sorted return 
        return;

    int *temp = (int *)malloc(sizeof(int) * size); //Allocate space in memory for sorted array
    merge_sort(array, temp, 0, size - 1); //pass in initial array, pointer space in memory to work with, and start and end
    free(temp); //free extra memory when completed
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif