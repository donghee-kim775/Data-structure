#include <stdio.h>
#include "CQ.h"

void main() {
	QueueType* cQ = createQueue();
	element data;
	printf(" \n ****** ���� ť ���� ****** \n");
	printf("\n ���� A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n ���� B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n ���� C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ);      printf(" peek item : %c \n", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t���� ������ : %c", data);
	printf("\n ���� D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n ���� E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}
