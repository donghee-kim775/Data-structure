#pragma once
#ifndef __LQueue_H__
#define __LQueue_H__

typedef char element;
typedef struct QNode {
	element data;
	struct QNode* link;
}QNode;

typedef struct {
	QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue();

int isEmpty(LQueueType* LQ);

void enQueue(LQueueType* LQ, element item);

element deQueue(LQueueType* LQ);

element peek(LQueueType* LQ);

void printLQ(LQueueType* LQ);

#endif // !__LQueue_H__
