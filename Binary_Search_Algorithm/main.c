#include <stdio.h>
#include <stdlib.h>
#include "Searching_algorithm_header.h"

int main()
{
    uint32_t arr[10] = {5,1,9,3,4,0,6,2,8,7};
    printArray(arr, 10);
    selectionSort(arr, 10);
    printArray(arr, 10);
    if(binarySearch(arr, 10, 7) < 255)  printf("found\n");
    else printf("not found\n");
    return 0;
}
