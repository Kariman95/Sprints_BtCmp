/***************************************************
 * File: Searching_algorithm_implementation.h
 * Author: Kariman Karam
 * Date: 2 July 2021
 * Version: 1
 * Description: Declarations for binary searching algorithm
 **************************************************/

#include "Searching_algorithm_header.h"

/**************************************************
 * this function to search for an element in arry *
 **************************************************/
uint8_t     binarySearch(uint32_t* arr, uint8_t size, uint32_t number)
{
    uint8_t start = 0;
    uint8_t end = size - 1;
    uint8_t mid = (start + end)/2;

    while (start <= end)
    {
        if (arr[mid] < number)
        {
            start = mid + 1;
        }
        else if (arr[mid] == number)
        {
            return mid;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return -1;  // =255 because it returns unsigned
}

/********************************************************
 * this function to check if the array is sorted or not *
 ********************************************************/
enum E_IsSORTED  isSorted(uint32_t* arr, uint8_t size)
{
    uint8_t i,j;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i] > arr[j])
            {
                return E_NotSORTED;
            }
        }
    }
    return E_SORTED;
}

/***************************************
 * private function to swap 2 elements *
 ***************************************/
static void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/***********************************
 * this function to sort the array *
 ***********************************/
enum E_STATUS    selectionSort(uint32_t* arr, uint8_t size)
{
    uint8_t i, j, min_idx;

    if(isSorted(arr, size) == E_SORTED)
    {
        return E_ERROR;
    }

    else
    {
        // One by one move boundary of unsorted subarray
        for (i=0; i<size-1; i++)
        {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j=i+1; j<size; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            // Swap the found minimum element with the first element
            swap(&arr[min_idx], &arr[i]);
        }
        return E_OK;
    }
}

void printArray(uint32_t* arr, uint8_t size)
{
    uint8_t i;

    for(i=0; i<size; i++)
    {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}
