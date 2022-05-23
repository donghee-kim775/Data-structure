#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LQueue.h"

void main(void) {
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ****** ���� ť ���� ****** \n");
	printf("\n ���� A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n ���� B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n ���� C>>"); enQueue(LQ, 'C'); printLQ(LQ);
	data = peek(LQ);      printf(" peek item : %c \n", data);
	printf("\n ���� >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t\t���� ������ : %c", data);
	printf("\n ���� D>>"); enQueue(LQ, 'D'); printLQ(LQ);
	printf("\n ���� E>>"); enQueue(LQ, 'E'); printLQ(LQ);
	getchar();
}