/*
 * main.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include "LinkedList.h"
#include "Book.h"

void View_LinkedList(LinkedList *linkedlist)
{
    Book *book = 0;
    Link seek = LinkedList_Begin(linkedlist);
    Link end = LinkedList_End(linkedlist);

    printf("--- List of books you have ---- \n");
    for( ; seek != end; seek = seek->next)
    {
        book = (Book *)(seek->data);
        if(book)
        {
            Book_View(book);
        }
    }
}

void SimulEnd(LinkedList *linkedlist)
{
    Book *book = 0;
    Link seek = LinkedList_Begin(linkedlist);
    Link end = LinkedList_End(linkedlist);

    for( ; seek != end; seek = seek->next)
    {
        book = (Book *)(seek->data);
        if(book)
        {
            Delete_Book(book);
        }
    }
    Delete_LinkedList(linkedlist);
}

void Simul_Find(LinkedList *linkedlist, const char *title)
{
    Book *book = 0;
    Link seek = LinkedList_Begin(linkedlist);
    Link end = LinkedList_End(linkedlist);

    for( ; seek != end; seek = seek->next)
    {
        book = (Book *)(seek->data);
        if(book && (Book_CompareTitle(book, title)== 0))
        {
            printf("Find result : ");
            Book_View(book);
            return;
        }
    }
    printf("<%s> Can not find. \n", title);
}

void Simul_Remove(LinkedList *linkedlist, const char *title)
{
    Book *book = 0;
    Link seek = LinkedList_Begin(linkedlist);
    Link end = LinkedList_End(linkedlist);

    for( ; seek != end; seek = seek->next)
    {
        book = (Book *)(seek->data);
        if(book && (Book_CompareTitle(book, title)==0))
        {
            LinkedList_Erase(linkedlist, seek);
            Delete_Book(book);
            printf("Delete success! \n");
        }
    }
    printf("<%s> Can not find. \n", title);
}

void Simul_Seq()
{
    LinkedList *linkedlist = New_LinkedList();
    LinkedList_PushBack(linkedlist, New_Book("Romeo and Juliet", "Shakespeare", 10));
    LinkedList_PushBack(linkedlist, New_Book("Wing", "LeeSang", 20));
    LinkedList_PushBack(linkedlist, New_Book("Data Structure", "HongGilDong", 5));
    LinkedList_PushBack(linkedlist, New_Book("Algorithm", "LeeSunSin", 9));
    LinkedList_PushBack(linkedlist, New_Book("Design Pattern", "HeegyuBaek", 13));

    View_LinkedList(linkedlist);

    Simul_Find(linkedlist, "Romeo and Juliet");
    Simul_Find(linkedlist, "Effective C++");
    Simul_Find(linkedlist, "Design Pattern");

    View_LinkedList(linkedlist);
    SimulEnd(linkedlist);
}

void Simul_OrderAdd(LinkedList *linkedlist, Book *book)
{
    Book *stored_book = 0;
    Link seek = LinkedList_Begin(linkedlist);
    Link end = LinkedList_End(linkedlist);

    for( ; seek != end; seek = seek->next)
    {
        stored_book = (Book *)(seek->next);
        if(stored_book && (Book_CompareAuthor(stored_book, book->author) >= 0))
        {
            break;
        }
    }
    LinkedList_Insert(linkedlist , seek, book);
}

void Simul_Order()
{
    LinkedList *linkedlist = New_LinkedList();

    Simul_OrderAdd(linkedlist, New_Book("Romeo and Juliet", "Shakespeare", 10));
    Simul_OrderAdd(linkedlist, New_Book("Wing", "LeeSang", 20));
    Simul_OrderAdd(linkedlist, New_Book("Data Structure", "HongGilDong", 5));
    Simul_OrderAdd(linkedlist, New_Book("Algorithm", "LeeSunSin", 9));
    Simul_OrderAdd(linkedlist, New_Book("Design Pattern", "HeegyuBaek", 13));

    View_LinkedList(linkedlist);

    Simul_Find(linkedlist, "Romeo and Juliet");
    Simul_Find(linkedlist, "Effective C++");
    Simul_Find(linkedlist, "Design Pattern");

    View_LinkedList(linkedlist);
    SimulEnd(linkedlist);
}

int main()
{
    Simul_Seq();
    Simul_Order();
    return 0;
}


