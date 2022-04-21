#include <stdio.h>
#include "circularlinkedlist.h"

int main() {
	linkedList_h* CL;
	listNode* p;

	CL = createlinkedlist_h();
	printf("\n(1) ���� ���� ����Ʈ �����ϱ�! \n");
	printlist(CL);

	printf("\n(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�\n");
	insertFirstNode(CL, "��");
	printlist(CL);

	printf("\n(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] �����ϱ�\n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printlist(CL);

	printf("\n(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] �����ϱ�\n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printlist(CL);

	printf("\n(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�!\n");
	p = searchNode(CL, "��"); deleteNode(CL, p);
	printlist(CL);

	getchar();return 0;
}