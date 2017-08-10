/*
 * EnhancedStack.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include "EnhancedStack.h"
#include <malloc.h>
#include <memory.h>

EHStack *New_EHStack()
{
    return New_LinkedList();
}

void Delete_EHStack(EHStack *ehs)
{
    Delete_LinkedList(ehs);
}

void EHStack_Push(EHStack *ehs, Element data)
{
    LinkedList_PushBack(ehs, data);
}

Element EHStack_Pop(EHStack *ehs)
{
    Element element = 0;
    if(!EHStack_IsEmpty(ehs))
    {
        Link last = LinkedList_End(ehs);
        last = last->prev;
        element = last->data;
        LinkedList_Erase(ehs, last);
    }
    return element;
}

int EHStack_IsEmpty(EHStack *ehs)
{
    return ehs->usage == 0;
}

