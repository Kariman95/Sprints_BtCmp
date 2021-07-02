/***************************************************************************************************
 * File: Stack_implementation.c                                                                   *
 * Author: Kariman Karam                                                                           *
 * Date: 2 July 2021                                                                               *
 * Version: 1                                                                                      *
 * Description: this is the implementation file for function declarations for stack data structure *
 ***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack_header.h"

/******************************************
 * this function to create an empty stack *
 ******************************************/
void    createEmptyStack(Stack *st)
{
    st->top  = NULL;
    st->size = 0;
}

/*********************************************************************
 * Description: this function inserts a node at the top of the stack *
 *********************************************************************/
enum E_STATUS    push(Stack* st, uint8_t   u8_data)
{
    enum E_STATUS status = E_ERROR;
    //in case stack is full
    if(isFull(&st) == E_FULL_STACK)
    {
        return E_FULL_STACK;
    }
    else
    {
        status = E_OK;
        //first create a new node for the new data
        Node* pn = (Node*)malloc(sizeof(Node));
        //second make the node points to what top was pointing to
        pn->next = st->top;
        //third make this new node at the top of the stack
        st->top = pn;
        //fourth assign the incoming data to this new node
        pn->data = u8_data;
        //finally increase stack size
        st->size++;
    }
    return status;
}

/**********************************************************
 * this function deletes a node from the top of the stack *
 **********************************************************/
enum E_STATUS    pull(Stack* st, uint8_t* u8_data)
{
    enum E_STATUS status = E_ERROR;
    Node* currentNode = NULL;

    //in case stack is empty, nothing to pull
    if(st->top == NULL)
    {
        return E_EMPTY_STACK;
    }
    else
    {
        status = E_OK;
        //first save data of the top node at the stack
        *u8_data = st->top->data;
        //second save the current node address to free later
        currentNode = st->top;
        //third make the next node to be the top node of the stack
        st->top = currentNode->next;
        //fourth free the node
        free(currentNode);
        //finally decrease size of the stack by one
        st->size--;
    }
    return status;
}

/************************************
 * this function displays the stack *
 ************************************/
void    printStack(Stack* st)
{
    uint8_t u8_data;
    enum E_STATUS status;

    printf("Stack Data:\n");

    if(st->top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        while(st->top != NULL)
        {
            pull(st, &u8_data);
            printf("    %d\n",u8_data);
        }
    }
}

/********************************************
 * this function to check if stack is empty *
 ********************************************/
enum E_STATUS  isEmpty(Stack* st)
{
    //printf("empty");
    if(st->top == NULL)
    {
        printf("empty");
        return E_EMPTY_STACK;
    }
    else
    {
        return E_OK;
    }
}

/********************************************
 * this function to check if stack is Full *
 ********************************************/
enum E_STATUS  isFull(Stack* st)
{
    if(st->size == MAXSTACKSIZE)
    {
        return E_FULL_STACK;
    }
    else
    {
        return E_OK;
    }
}
