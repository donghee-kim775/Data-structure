#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h* L;
	listnode* p;
	L = createLinkedList_h();// ���鸮��Ʈ����
	
	printf("(1)����Ʈ�� [��],[��],[��]��� �����ϱ�!\n");
	InsertLastNode(L, "��");InsertLastNode(L, "��");InsertLastNode(L, "��");
	printList(L);

	printf("\n(2)����Ʈ���� [��] ��� Ž���ϱ�!\n");
	p = searchNode(L, "��");
	if (p == NULL) printf("ã�µ����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);

	printf("\n(3)����Ʈ�� [��] �ڿ� [��]��� �����ϱ�!\n");
	InsertMiddleNode(L, p, "��");
	printList(L);

	printf("\n(4)����Ʈ�� [��]��� �����ϱ�!\n");
	p=searchNode(L, "��");
	deleteNode(L, p);
	printList(L);

	printf("\n(5)����Ʈ ������ �������� �ٲٱ�!\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();
	return 0;
}