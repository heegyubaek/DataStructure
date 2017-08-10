/*
 * EnhancedQueue.h
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#ifndef ENHANCEDQUEUE_H_
#define ENHANCEDQUEUE_H_

#include "LinkedList.h"

typedef LinkedList EHQueue;

EHQueue *New_EHQueue();
void Delete_EHQueue(EHQueue *ehq);
void EHQueue_Put(EHQueue *ehq, Element data);
Element EHQueue_Get(EHQueue *ehq);
int EHQueue_IsEmpty(EHQueue *ehq);


#endif /* ENHANCEDQUEUE_H_ */
