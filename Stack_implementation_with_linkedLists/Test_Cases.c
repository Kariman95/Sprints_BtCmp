/****************************************************************************************************************
 * File: Test_Cases.h                                                                                           *
 * Author: Kariman Karam                                                                                        *
 * Date: 2 July 2021                                                                                            *
 * Version: 1                                                                                                   *
 * Description: this file have test cases to test the functionality of the stack implementation                 *
 ****************************************************************************************************************/

#include <stdio.h>
#include "Stack_header.h"

void  Test_Empty_Stack(Stack* st)
{
    //enum E_STATUS status = isEmpty(&st);
    if(st->top == NULL)             printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}

void  Test_Full_Stack(Stack* st)
{
    enum E_STATUS status = isFull(&st);
    if(status == E_FULL_STACK)      printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}

void Test_Push_At_Stack(Stack* st)
{
    enum E_STATUS status = push(&st, 10);
    if(status == E_OK)              printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}

void Test_Pull_From_Stack(Stack* st)
{
    uint8_t u8_data;
    push(&st,5);
    enum E_STATUS status = pull(&st, &u8_data);
    if(status == E_OK)              printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}

void Test_Pull_From_Empty_Stack(void)
{
    uint8_t u8_data;
    Stack st;
    createEmptyStack(&st);

    enum E_STATUS status = pull(&st, &u8_data);
    if(status == E_EMPTY_STACK)     printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}

void Test_Push_To_Full_Stack(Stack* st)
{
    enum E_STATUS status = push(&st, 10);
    if(status == E_FULL_STACK)      printf("Passed Test Case\n");
    else                            printf("Failed Test Case\n");
}



int main(void)
{
    Stack st;
    createEmptyStack(&st);

	Test_Empty_Stack(&st);
	Test_Full_Stack(&st);
	Test_Push_At_Stack(&st);
	Test_Pull_From_Stack(&st);
	Test_Pull_From_Empty_Stack();
    Test_Push_To_Full_Stack(&st);
    return 0;
}
