/*******************************************************************************
 * File: Searching_algorithm_implementation.h
 * Author: Kariman Karam
 * Date: 2 July 2021
 * Version: 1
 * Description: Test Cases to test the functionality of binary search algorithm
 *******************************************************************************/

#include <stdlib.h>
#include "Searching_algorithm_header.h"

void Test_Sorted_Array(void)
{
    uint32_t arr[5] = {0,1,2,3,4};
    if(isSorted(arr, 5) == E_SORTED)          printf("Passed TC1\n");
    else if(isSorted(arr, 5) == E_NotSORTED)  printf("Failed TC1\n");
}

void Test_NotSorted_Array(void)
{
    uint32_t arr[5] = {10,2,0,50,9};
    if(isSorted(arr, 5) == E_NotSORTED)       printf("Passed TC2\n");
    else if(isSorted(arr, 5) == E_SORTED)     printf("Failed TC2\n");
}

void Test_Selection_Sort_For_Sorted_Array(void)
{
    uint32_t arr[5] = {0,1,2,3,4};
    if(selectionSort(arr, 5) == E_ERROR)         printf("Passed TC3\n");
    else if(selectionSort(arr, 5) == E_OK)       printf("Failed TC3\n");
}

void Test_Selection_Sort_For_NotSorted_Array(void)
{
    uint32_t arr[5] = {10,2,0,50,9};
    if(selectionSort(arr, 5) == E_OK)            printf("Passed TC4\n");
    else if(selectionSort(arr, 5) == E_ERROR)    printf("Failed TC4\n");
}

void Test_Binary_Search_For_Existing_Element(void)
{
    uint32_t arr[5] = {10,2,0,50,9};
    if(binarySearch(arr, 5, 50) < 255)           printf("Passed TC5\n");
    else if(binarySearch(arr, 5, 50) == -1)      printf("Failed TC5\n");
}

void Test_Binary_Search_For_NotExisting_Element(void)
{
    uint32_t arr[5] = {10,2,0,50,9};
    if(binarySearch(arr, 5, 20) == -1)          printf("Passed TC5\n");
    else if(binarySearch(arr, 5, 20) < 255)     printf("Failed TC5\n");
}

int main(void)
{
    Test_Sorted_Array();
    Test_NotSorted_Array();
    Test_Selection_Sort_For_Sorted_Array();
    Test_Selection_Sort_For_NotSorted_Array();
    Test_Binary_Search_For_Existing_Element();
    Test_Binary_Search_For_NotExisting_Element();
    return 0;
}
