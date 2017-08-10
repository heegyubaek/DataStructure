/*
 * EnhancedStack.h
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#ifndef ENHANCEDSTACK_H_
#define ENHANCEDSTACK_H_

#include "LinkedList.h"

typedef LinkedList EHStack;

EHStack *New_EHStack();
void Delete_EHStack(EHStack *ehs);
void EHStack_Push(EHStack *ehs, Element data);
Element EHStack_Pop(EHStack *ehs);
int EHStack_IsEmpty(EHStack *ehs);


#endif /* ENHANCEDSTACK_H_ */
