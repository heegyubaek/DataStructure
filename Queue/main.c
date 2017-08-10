/*
 * main.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include "EnhancedQueue.h"
#include "Book.h"

int main()
{
    EHQueue *ehq = 0;
    Book *book = 0;
    ehq = New_EHQueue();
    EHQueue_Put(ehq, New_Book("Romeo and Juliet", "Shakespeare", 10));
    EHQueue_Put(ehq, New_Book("Wing", "LeeSang", 20));
    EHQueue_Put(ehq, New_Book("Data Structure", "HongGilDong", 5));

    book = (Book *)EHQueue_Get(ehq);
    if(book)
    {
        Book_View(book);
        Delete_Book(book);
    }

    EHQueue_Put(ehq, New_Book("Algorithm", "LeeSunSin", 9));
    EHQueue_Put(ehq, New_Book("Design Pattern", "HeegyuBaek", 13));

    while(!EHQueue_IsEmpty(ehq))
    {
        book = (Book *)EHQueue_Get(ehq);
        if(book)
        {
            Book_View(book);
            Delete_Book(book);
        }
    }

    Delete_EHQueue(ehq);
    return 0;
}


