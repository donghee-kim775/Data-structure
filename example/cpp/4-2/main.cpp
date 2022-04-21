#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h* L;
	listnode* p;
	L = createLinkedList_h();// 공백리스트생성
	
	printf("(1)리스트에 [월],[수],[일]노드 삽입하기!\n");
	InsertLastNode(L, "월");InsertLastNode(L, "수");InsertLastNode(L, "일");
	printList(L);

	printf("\n(2)리스트에서 [수] 노드 탐색하기!\n");
	p = searchNode(L, "수");
	if (p == NULL) printf("찾는데이터가 없습니다.\n");
	else printf("[%s]를 찾았습니다.\n", p->data);

	printf("\n(3)리스트의 [수] 뒤에 [금]노드 삽입하기!\n");
	InsertMiddleNode(L, p, "금");
	printList(L);

	printf("\n(4)리스트의 [일]노드 삭제하기!\n");
	p=searchNode(L, "일");
	deleteNode(L, p);
	printList(L);

	printf("\n(5)리스트 순서를 역순으로 바꾸기!\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();
	return 0;
}