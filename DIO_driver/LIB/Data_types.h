/*
 * Data_types.h
 *
 *  Created on: Jul 8, 2021
 *      Author: Kariman
 */

#ifndef LIB_DATA_TYPES_H_
#define LIB_DATA_TYPES_H_

/*- DEFINES -----------------------------------------------*/
#define NULL_PTR 			( (void *) 0)

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef unsigned char           uint8_t;
typedef signed char             sint8_t;
//typedef unsigned int            uint32_t;
typedef signed int              sint32_t;
//typedef unsigned short int      uint16_t;
typedef signed short int        sint16_t;
typedef unsigned long long int  uint64_t;
typedef signed long long int    sint64_t;

typedef enum { E_ERROR, E_OK }enuErrorStatus_t;

#endif /* LIB_DATA_TYPES_H_ */
