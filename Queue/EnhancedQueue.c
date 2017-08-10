/*
 * EnhancedQueue.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include "EnhancedQueue.h"

EHQueue *New_EHQueue()
{
    return New_LinkedList();
}

void Delete_EHQueue(EHQueue *ehq)
{
    Delete_LinkedList(ehq);
}

void EHQueue_Put(EHQueue *ehq, Element data)
{
    LinkedList_PushBack(ehq, data);
}

Element EHQueue_Get(EHQueue *ehq)
{
    Element element = 0;
    if(!EHQueue_IsEmpty(ehq))
    {
        Link first = LinkedList_Begin(ehq);
        element = first->data;
        LinkedList_Erase(ehq, first);
    }

    return element;
}

int EHQueue_IsEmpty(EHQueue *ehq)
{
    return ehq->usage == 0;
}


