/*
 * Book.h
 *
 *  Created on: Jul 29, 2017
 *      Author: baekhg
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "common.h"
#define MAX_TIT_LEN 200
#define MAX_AUT_LEN 20

typedef struct _Book Book;
struct _Book
{
    char title[MAX_TIT_LEN+1];
    char author[MAX_AUT_LEN+1];
    int num;
};

Book *New_Book(const char *title, const char *author, int num);
void Delete_Book(Book *book);
void Book_View(Book *book);
int Book_CompareTitle(Book *book, const char *title);
int Book_CompareAuthor(Book *book, const char *author);
int Book_CompareNum(Book *book, int num);


#endif /* BOOK_H_ */
