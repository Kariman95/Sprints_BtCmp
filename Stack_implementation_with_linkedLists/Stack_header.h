/****************************************************************************************************************
 * File: Stack_header.h                                                                                         *
 * Author: Kariman Karam                                                                                        *
 * Date: 2 July 2021                                                                                            *
 * Version: 1                                                                                                   *
 * Description: this is the header for prototypes, structs and preprocessor directives for stack data structure *
 ****************************************************************************************************************/

#ifndef _HEADER_H_
#define _HEADER_H_

#include "Data_Types.h"

#define MAXSTACKSIZE    100

enum E_STATUS {E_ERROR, E_OK, E_FULL_STACK, E_EMPTY_STACK};

/********************************************************************
 * struct for node that contains of data and a pointer to next node *
 ********************************************************************/
typedef struct node{
    uint8_t data;
    struct node* next;
}Node;

/************************
 * struct for the stack *
 ************************/
typedef struct stack{
    Node* top;
    int size;
}Stack;


/******************************************
 * this function to create an empty stack *
 ******************************************/
void             createEmptyStack(Stack *st);

/*********************************************************************
 * Description: this function inserts a node at the top of the stack *
 *********************************************************************/
enum E_STATUS    push(Stack* st, uint8_t   u8_data);

/**********************************************************
 * this function deletes a node from the top of the stack *
 **********************************************************/
enum E_STATUS    pull(Stack* st, uint8_t* u8_data);

/************************************
 * this function displays the stack *
 ************************************/
void            printStack(Stack* st);

/********************************************
 * this function to check if stack is empty *
 ********************************************/
enum E_STATUS  isEmpty(Stack* st);

/********************************************
 * this function to check if stack is Full *
 ********************************************/
enum E_STATUS  isFull(Stack* st);

#endif // HEADER_H_
