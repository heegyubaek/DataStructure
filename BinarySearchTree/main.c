/*
 * main.c
 *
 *  Created on: Aug 11, 2017
 *      Author: baekhg
 */

#include "BinarySearchTree.h"

int main()
{
    Book *book = 0;
    BST *bst = New_BST();

    BST_Insert(bst, New_Book("Romeo and Juliet", "Shakespeare", 10));
    BST_Insert(bst, New_Book("Wing", "LeeSang", 20));
    BST_Insert(bst, New_Book("Data Structure", "HongGilDong", 5));
    BST_Insert(bst, New_Book("Algorithm", "LeeSunSin", 9));
    BST_Insert(bst, New_Book("Design Pattern", "HeegyuBaek", 13));
    BST_Insert(bst, New_Book("Network Programming", "LeeHeeSun", 18));

    BST_List(bst);
    book = BST_Find(bst, 5);

    if(book)
    {
        printf("Success find book!\n");
        Book_View(book);
    }
    else
    {
        printf("Fail find book!\n");
    }

    BST_Remove(bst, 5);
    BST_List(bst);
    Delete_BST(bst);

    return 0;
}


