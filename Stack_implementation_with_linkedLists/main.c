#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack_header.h"

uint8_t*    balancedParantheses(uint8_t* expression);

int main()
{
    uint8_t *str = "(1+1*{2*10)";
    uint8_t *check = balancedParantheses(str);
    printf("%s",check);
    return 0;
}

uint8_t*    balancedParantheses(uint8_t* expression)
{
    Stack st;
    uint8_t i, data, c1=0, c2=0, c3=0, c4=0;
    uint8_t u8_data[strlen(expression)];
    enum E_STATUS status;

    createEmptyStack(&st);

    while(expression[i] != '\0')
    {
        push(&st, expression[i]);
        i++;
    }
    while(st.top != NULL)
    {
        pull(&st, &data);
        if(data == '(')         c1++;
        else if(data == ')')    c2++;
        else if(data == '{')    c3++;
        else if(data == '}')    c4++;
    }
    if(c1 != c2 || c3 != c4)        return "Not Balanced";
    else if(c3 == c4 && c1 == c2)   return "Balanced";
}
