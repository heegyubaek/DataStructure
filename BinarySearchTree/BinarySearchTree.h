/*
 * BinarySearchTree.h
 *
 *  Created on: Aug 11, 2017
 *      Author: baekhg
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "Book.h"

typedef struct _Node Node;
struct _Node
{
    Book *book;
    Node *lch;
    Node *rch;
    Node *pa;
};

Node *New_Node(Book *data);
typedef struct _BinSearchTree BST;
struct _BinSearchTree
{
    Node *root;
    int count;
};

BST *New_BST();
void Delete_BST(BST *bst);
int BST_Insert(BST *bst, Book *book);
int BST_Remove(BST *bst, int num);
Book *BST_Find(BST *bst, int num);
void BST_List(BST *bst);



#endif /* BINARYSEARCHTREE_H_ */
