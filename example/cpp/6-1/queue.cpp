#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueType* createQueue() {
    QueueType* Q;
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isEmpty(QueueType* Q) {
    if (Q->front == Q->rear) {
        printf(" Queue is empty! ");
        return 1;
    }
    else return 0;
}

int isFull(QueueType* Q) {
    if (Q->rear == Q_SIZE - 1) {
        printf(" Queue is full! ");
        return 1;
    }
    else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, element item) {
    if (isFull(Q)) return;  // ��ȭ �����̸�, ���� ���� �ߴ�
    else {
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

// ���� ť�� front���� ���Ҹ� �����ϴ� ����
element deQueue(QueueType* Q) {
    if (isEmpty(Q)) return;  // ���� �����̸�, ���� ���� �ߴ�
    else {
        Q->front++;
        return Q->queue[Q->front];
    }
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peek(QueueType* Q) {
    if (isEmpty(Q)) exit(1); // ���� �����̸� ���� �ߴ�
    else return Q->queue[Q->front + 1];
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printQ(QueueType* Q) {
    int i;
    printf(" Queue : [");
    for (i = Q->front + 1; i <= Q->rear; i++)
        printf("%3c", Q->queue[i]);
    printf(" ]");
}