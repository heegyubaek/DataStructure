/*
 * Queue.c
 *
 *  Created on: Aug 10, 2017
 *      Author: baekhg
 */

#include <stdio.h>
#include <stdlib.h>

#define NEXT(index, QSIZE)  ((index + 1) % QSIZE)

typedef struct Queue
{
    int *buf;
    int qsize;
    int front;
    int rear;
    int count;
}Queue;

void InitQueue(Queue *queue, int qsize);
int IsFull(Queue *queue);
int IsEmpty(Queue *queue);
void Enqueue(Queue *queue, int data);
int Dequeue(Queue *queue);
void DisposeQueue(Queue *queue);

int main(void)
{
    int i;
    Queue queue;

    InitQueue(&queue, 10);
    for(i = 1; i <= 5; i++)
    {
        Enqueue(&queue, i);
    }

    while(!IsEmpty(&queue))
    {
        printf("%d", Dequeue(&queue));
    }
    printf("\n");
    return 0;
}

void InitQueue(Queue *queue, int qsize)
{
    queue->buf = (int *)malloc(sizeof(int) * qsize);
    queue->qsize = qsize;
    queue->front = queue->rear = 0;
    queue->count = 0;
}

int IsFull(Queue *queue)
{
    return queue->count == queue->qsize;
}

int IsEmpty(Queue *queue)
{
    return queue->count == 0;
}

void Enqueue(Queue *queue, int data)
{
    if(IsFull(queue))
    {
        printf("Queue Full! \n");
        return ;
    }
    queue->buf[queue->rear] = data;
    queue->rear = NEXT(queue->rear, queue->qsize);
    queue->count++;
}

int Dequeue(Queue *queue)
{
    int data = 0;
    if(IsEmpty(queue))
    {
        printf("Queue is empty! \n");
        return data;
    }
    data = queue->buf[queue->front];
    queue->front = NEXT(queue->front, queue->qsize);
    queue->count--;
    return data;
}

void DisposeQueue(Queue *queue)
{
    free(queue->buf);
}


