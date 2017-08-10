/*
 * Book.c
 *
 *  Created on: Jul 29, 2017
 *      Author: baekhg
 */

#include "Book.h"

void Book_Book(Book *book, const char *title, const char *author, int num);

Book *New_Book(const char *title, const char *author, int num)
{
    Book *book = 0;
    book = (Book *)malloc(sizeof(Book));
    Book_Book(book, title, author, num);
    return book;
}

void Book_Book(Book *book, const char *title, const char *author, int num)
{
    memset(book, 0, sizeof(Book));
    strncpy(book->title, title, MAX_TIT_LEN);
    strncpy(book->author, author, MAX_AUT_LEN);
    book->num = num;
}

void Delete_Book(Book *book)
{
    free(book);
}

void Book_View(Book *book)
{
    printf("<%010d>:<%s>\n", book->num, book->title);
    printf("\t Author:%s\n", book->author);
}

int Book_CompareTitle(Book *book, const char *title)
{
    return strcmp(book->title, title);
}

int Book_CompareAuthor(Book *book, const char *author)
{
    return strncmp(book->author, author, strlen(author));
}

int Book_CompareNum(Book *book, int num)
{
    return book->num-num;
}


