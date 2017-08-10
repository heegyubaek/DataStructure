/*
 * main.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include "EnhancedStack.h"
#include "Book.h"

int main()
{
    EHStack *ehs = 0;
    Book *book = 0;

    ehs = New_EHStack();
    EHStack_Push(ehs, New_Book("Romeo and Juliet", "Shakespeare", 10));
    EHStack_Push(ehs, New_Book("Wing", "LeeSang", 20));
    EHStack_Push(ehs, New_Book("Data Structure", "HongGilDong", 5));

    book = (Book *)EHStack_Pop(ehs);
    if(book)
    {
        Book_View(book);
        Delete_Book(book);
    }

    EHStack_Push(ehs, New_Book("Algorithm", "LeeSunSin", 9));
    EHStack_Push(ehs, New_Book("Design Pattern", "HeegyuBaek", 13));

    while(!EHStack_IsEmpty(ehs))
    {
        book = (Book *)EHStack_Pop(ehs);
        if(book)
        {
            Book_View(book);
            Delete_Book(book);
        }
    }

    Delete_EHStack(ehs);
    return 0;
}



