/***************************************************
 * File: Searching_algorithm_header.h
 * Author: Kariman Karam
 * Date: 2 July 2021
 * Version: 1
 * Description: Prototypes for binary searching algorithm
 **************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include "Data_Types.h"
#define MAXSIZE     255

enum E_STATUS {E_ERROR, E_OK};
enum E_IsSORTED {E_SORTED, E_NotSORTED};

uint8_t          binarySearch(uint32_t* arr, uint8_t size, uint32_t number);
enum E_IsSORTED  isSorted(uint32_t* arr, uint8_t size);
enum E_STATUS    selectionSort(uint32_t* arr, uint8_t size);
void             printArray(uint32_t* arr, uint8_t size);

#endif // HEADER_H_

