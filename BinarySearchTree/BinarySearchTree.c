/*
 * BinarySearchTree.c
 *
 *  Created on: Aug 11, 2017
 *      Author: baekhg
 */

#include "BinarySearchTree.h"
#include <malloc.h>

Node *New_Node(Book *data)
{
    Node *node = 0;
    node = (Node *)malloc(sizeof(Node));
    node->book = data;
    node->lch = node->rch = node->pa = 0;
    return node;
}

BST *New_BST()
{
    BST *bst = 0;
    bst = (BST *)malloc(sizeof(BST));
    bst->root = 0;
    bst->count = 0;
    return bst;
}

void BST_PostOrder(Node *sr);
void Delete_BST(BST *bst)
{
    BST_PostOrder(bst->root);
    free(bst);
}

void BST_PostOrder(Node *sr)
{
    if(sr)
    {
        BST_PostOrder(sr->lch);
        BST_PostOrder(sr->rch);
        Delete_Book(sr->book);
        free(sr);
    }
}

Node *BST_FindSeat(Node *sr, int num);
int BST_Insert(BST *bst, Book *book)
{
    Node *parent = 0;
    parent = BST_FindSeat(bst->root, book->num);
    if(parent)
    {
        Node *node = 0;
        int gap = parent->book->num - book->num;
        if(gap == 0)
        {
            return 0;
        }

        node = New_Node(book);
        node->pa = parent;
        if(gap > 0)
        {
            parent->lch = node;
        }
        else
        {
            parent->rch = node;
        }
    }
    else
    {
        bst->root = New_Node(book);
    }
    bst->count++;
    return 1;
}

Node *BST_FindSeat(Node *sr, int num)
{
    int gap = 0;
    if(sr == 0)
    {
        return 0;
    }

    gap = sr->book->num - num;
    if(gap == 0)
    {
        return sr;
    }
    if(gap > 0)
    {
        if(sr->lch)
        {
            return BST_FindSeat(sr->lch, num);
        }
        return sr;
    }
    if(sr->rch)
    {
        return BST_FindSeat(sr->rch, num);
    }
    return sr;
}

void BST_Disconnect(BST *bst, Node *node);
int BST_Remove(BST *bst, int num)
{
    Node *node = 0;
    node = BST_FindSeat(bst->root, num);
    if(node)
    {
        if(node->book->num == num)
        {
            BST_Disconnect(bst, node);
            free(node);
            bst->count--;
            return 1;
        }
    }
    return 0;
}

Node *BST_Change(Node *node);
void BST_Disconnect(BST *bst, Node *node)
{
    Node *pa = 0;
    Node *ch = 0;
    if(node->lch && node->rch)
    {
        node = BST_Change(node);
    }
    pa = node->pa;
    (ch = node->lch)||(ch = node->rch);

    if(pa)
    {
        ch->pa = pa;
    }
    else
    {
        bst->root = ch;
    }

    if(ch)
    {
        if(pa->lch == node)
        {
            pa->lch = ch;
        }
        else
        {
            pa->rch = ch;
        }
    }
}

Node *BST_Change(Node *node)
{
    Node *temp = node;
    while(temp->rch)
    {
        temp = temp->lch;
    }
    node->book = temp->book;
    return temp;
}

Book *BST_Find(BST *bst, int num)
{
    Node *node = 0;
    node = BST_FindSeat(bst->root, num);
    if(node)
    {
        if(node->book->num == num)
        {
            return node->book;
        }
    }
    return 0;
}

void BST_Inorder(Node *sr);
void BST_List(BST *bst)
{
    printf("Number of stored node: %d\n", bst->count);
    BST_Inorder(bst->root);
}

void BST_Inorder(Node *sr)
{
    if(sr)
    {
        BST_Inorder(sr->lch);
        Book_View(sr->book);
        BST_Inorder(sr->rch);
    }
}




