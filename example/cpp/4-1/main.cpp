#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedlist.h"

int main() {
	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1) ���� ����Ʈ �����ϱ�!\n");
	printList(L); getchar();

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�!\n");
	insertFirstNode(L, "��");
	printList(L);getchar;

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�!\n");
	insertLastNode(L, "��");
	printList(L);getchar();

	printf("(4) ����Ʈ ù��°�� [��] ��� �����ϱ�!\n");
	insertFirstNode(L, "��");
	printList(L);getchar();

	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
	freeLinkedList_h(L);
	printList(L);
	
	getchar();

}