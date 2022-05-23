#include <stdio.h>
#include "CQ.h"

void main() {
	QueueType* cQ = createQueue();
	element data;
	printf(" \n ****** 원형 큐 연산 ****** \n");
	printf("\n 삽입 A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n 삽입 B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n 삽입 C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ);      printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t삭제 데이터 : %c", data);
	printf("\n 삽입 D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n 삽입 E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}
