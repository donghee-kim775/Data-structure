#include <stdio.h>
#include "circularlinkedlist.h"

int main() {
	linkedList_h* CL;
	listNode* p;

	CL = createlinkedlist_h();
	printf("\n(1) 원형 연결 리스트 생성하기! \n");
	printlist(CL);

	printf("\n(2) 원형 연결 리스트에 [월] 노드 삽입하기\n");
	insertFirstNode(CL, "월");
	printlist(CL);

	printf("\n(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 삽입하기\n");
	p = searchNode(CL, "월"); insertMiddleNode(CL, p, "수");
	printlist(CL);

	printf("\n(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 삽입하기\n");
	p = searchNode(CL, "수"); insertMiddleNode(CL, p, "금");
	printlist(CL);

	printf("\n(5) 원형 연결 리스트에서 [수] 노드 삭제하기!\n");
	p = searchNode(CL, "수"); deleteNode(CL, p);
	printlist(CL);

	getchar();return 0;
}