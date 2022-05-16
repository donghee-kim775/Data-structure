#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__
#define Q_SIZE 4

typedef char element;      // ť ����(element)�� �ڷ����� char�� ����
typedef struct {
	element queue[Q_SIZE];   // 1���� �迭 ť ����
	int front, rear;
} QueueType;

QueueType* createQueue();

int isEmpty(QueueType* Q);

int isFull(QueueType* Q);

void enQueue(QueueType* Q, element item);

element deQueue(QueueType* Q);

element peek(QueueType* Q);

void printQ(QueueType* Q);
#endif // !__QUEUE_H__
