/* queue.h -- interface for a queue */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

/* INSERT ITEM TYPE HERE */
/* FOR EXAMPLE, */
/* use the following for use_q.c */
/* typedef int Item; */
/* OR typedef struct item {int gumption; int charisma;} Item; */
/* use the following for mall.c */  
typedef struct item
{
    long arrive;      /* the time when a customer joins the queue   */
    int processtime;  /* the number of consultation minutes desired */
} Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;  /* pointer to front of queue  */
    Node * rear;   /* pointer to rear of queue   */
    int items;     /* number of items in queue   */
} Queue;

/* operation:        initialize the queue                       */
/* precondition:     pq points to a queue                       */
/* postcondition:    queue is initialized to being empty        */
void InitializeQueue(Queue * pq);

/* operation:        check if queue is full                     */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:   returns True if queue is full, else False  */
bool QueueIsFull(const Queue * pq);

/* operation:        check if queue is empty                    */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    returns True if queue is empty, else False */
bool QueueIsEmpty(const Queue *pq);

/* operation:        determine number of items in queue         */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    returns number of items in queue           */
int QueueItemCount(const Queue * pq);

/* operation:        add item to rear of queue                  */
/* precondition:     pq points to previously initialized queue */
/*                   item is to be placed at rear of queue      */
/* postcondition:    if queue is not empty, item is placed at   */
/*                   rear of queue and function returns         */
/*                   True; otherwise, queue is unchanged and    */
/*                   function returns False                     */
bool EnQueue(Item item, Queue * pq);

/* operation:        remove item from front of queue            */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    if queue is not empty, item at head of     */
/*                   queue is copied to *pitem and deleted from */
/*                   queue, and function returns True; if the   */
/*                   operation empties the queue, the queue is  */
/*                   reset to empty. If the queue is empty to   */
/*                   begin with, queue is unchanged and the     */
/*                   function returns False                     */
bool DeQueue(Item *pitem, Queue * pq);

/* operation:        empty the queue                            */
/* precondition:     pq points to previously initialized queue  */
/* postconditions:   the queue is empty                         */
void EmptyTheQueue(Queue * pq);

#endif
