#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

LQueueType* createLinkedQueue() {
    LQueueType* LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) {
        printf(" Linked Queue is Empty! ");
        return 1;
    }
    else return 0;
}

void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

element deQueue(LQueueType* LQ) {
    QNode* old = LQ->front;
    element item;
    if (isEmpty(LQ)) return 0;
    else {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        free(old);
        return item;
    }
}

element peek(LQueueType* LQ) {
    element item;
    if (isEmpty(LQ)) return 0;
    else {
        item = LQ->front->data;
        return item;
    }
}

void printLQ(LQueueType* LQ) {
    QNode* temp = LQ->front;
    printf("Linked Queue : [");
    while (temp) {
        printf("%3c", temp->data);
        temp = temp->link;
    }
    printf(" ] ");
}
