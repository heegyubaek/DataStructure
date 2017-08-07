/*
 * main.c
 *
 *  Created on: Aug 2, 2017
 *      Author: baekhg
 */

#include "Array.h"
#include "Book.h"

void View_Array(Array *arr)
{
    Book *book = 0;
    Iterator seek = Array_Begin(arr);
    Iterator end = Array_End(arr);

    printf("--- List of books you have ----");

    for( ; seek!= end; seek++)
    {
        book = (Book *)(*seek);
        if(book)
        {
            Book_View(book);
        }
    }
}

void SimulEnd(Array *arr)
{
    Book *book = 0;
    Iterator seek = Array_Begin(arr);
    Iterator end = Array_End(arr);

    for( ; seek != end; seek++)
    {
        book = (Book *)(*seek);
        if(book)
        {
            Delete_Book(book);
        }
    }
    Delete_Array(arr);
}

void Simul_Find(Array *arr, const char *title)
{
    Book *book = 0;
    Iterator seek = Array_Begin(arr);
    Iterator end = Array_End(arr);

    for( ; seek != end; seek++)
    {
        book = (Book *)(*seek);
        if(Book && (Book_ComapareTitle(book, title) == 0))
        {
            printf("Find result : ");
            Book_View(book);
            return ;
        }
    }

    printf("<%s> Can not find. \n", title);
}

void Simul_Remove(Array *arr, const char * title)
{
    Book *book = 0;
    Iterator seek = Array_Begin(arr);
    Iterator end = Array_End(arr);

    for( ; seek != end; seek++)
    {
        book = (Book *)(*seek);
        if(book && (Book_CompareTitle(book, title) == 0))
        {
            Array_Erase(arr, seek);
            Delete_Book(book);
            printf("Delete success! \n");
            return ;
        }
    }

    printf("<%s> Can not find. \n", title);
}

void Simul_Seq()
{
    Array *arr = New_Array();
    Array_PushBack(arr, New_Book("Romeo and Juliet", "Shakespeare", 10));
    Array_PushBack(arr, New_Book("Wing", "LeeSang", 20));
    Array_PushBack(arr, New_Book("Data Structure", "HongGilDong", 5));
    Array_PushBack(arr, New_Book("Algorithm", "LeeSunSin", 9));
    Array_PushBack(arr, New_Book("Design Pattern", "HeegyuBaek", 13));

    View_Array(arr);
    Simul_Find(arr, "Romeo and Juliet");
    Simul_Find(arr, "Tell me what you want");
    Simul_Find(arr, "Data Structure");

    View_Array(arr);
    SimulEnd(arr);

}

void Simul_OrderAdd(Array *arr, Book *book)
{
    Book *stored_book = 0;
    Iterator seek = Array_Begin(arr);
    Iterator end = Array_End(arr);

    for( ; seek != end ; seek++)
    {
        stored_book = (Book *)(*seek);
        if(stored_book && (Book_CompareAuthor(stored_book, book->author) >= 0))
        {
            break;
        }
    }
    Array_Insert(arr, seek, book);
}

void Simul_Order()
{
    Array *arr = New_Array();

    Simul_OrderAdd(arr, New_Book("Romeo and Juliet", "Shakespeare", 10));
    Simul_OrderAdd(arr, New_Book("Wing", "LeeSang", 20));
    Simul_OrderAdd(arr, New_Book("Data Structure", "HongGilDong", 5));
    Simul_OrderAdd(arr, New_Book("Algorithm", "LeeSunSin", 9));
    Simul_OrderAdd(arr, New_Book("Design Pattern", "HeegyuBaek", 13));

    View_Array(arr);
    Simul_Find(arr, "Romeo and Juliet");
    Simul_Find(arr, "Tell me what you want");
    Simul_Find(arr, "Data Structure");

    View_Array(arr);
    SimulEnd(arr);
}

void Simul_FindNum(Array *arr, int bnum)
{
    Book *book = 0;
    book = (Book *)Array_GetAt(arr, bnum-1);

    if(book)
    {
        printf("Search result : ");
        Book_View(book);
    }
    else
    {
        printf("<%d>num's book can not find. \n", bnum);
    }
}

void Simul_RemoveNum(Array *arr, int bnum)
{
    Book *book = 0;
    book = (Book *)Array_GetAt(arr, bnum-1);

    if(book)
    {
        Delete_Book(book);
        Array_SetAt(arr, bnum-1, 0);
    }
    else
    {
        printf("<%d>num's book can not find. \n", bnum);
    }
}

void Simul_Index()
{
    Array *arr = New_Array();
    Array_SetSize(arr, 100, 0);

    Array_SetAt(arr, 9, New_Book("Romeo and Juliet", "Shakespeare", 10));
    Array_SetAt(arr, 19, New_Book("Wing", "LeeSang", 20));
    Array_SetAt(arr, 4, New_Book("Data Structure", "HongGilDong", 5));
    Array_SetAt(arr, 8, New_Book("Algorithm", "LeeSunSin", 9));
    Array_SetAt(arr, 12, New_Book("Design Pattern", "HeegyuBaek", 13));

    View_Array(arr);
    Simul_FindNum(arr, 20);
    Simul_FindNum(arr, 21);
    Simul_RemoveNum(arr, 9);
    View_Array(arr);
    SimulEnd(arr);
}

int main()
{
    Simul_Seq();
    Simul_Order();
    Simul_Index();

    return 0;
}

