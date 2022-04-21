#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circularlinkedlist.h"
linkedList_h* createlinkedlist_h() {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));//head��� �Ҵ�
	CL->head = NULL;//�����̱⿡ NULL�� �ʱ�ȭ
	return CL;
}

void printlist(linkedList_h* CL) {
	listNode* p;
	printf("(");
	p = CL->head;
	if (p == NULL) {
		printf(" )");
		return;
	}
	do
	{
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p!=CL->head);
	printf(")\n");
}

void insertFirstNode(linkedList_h* CL, const char* x) {
	listNode* newnode,*p;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy(newnode->data, x);
	if (CL->head == NULL) {
		CL->head = newnode;//��带 ����忡 �����ϰ�
		newnode->link = newnode;//�����̴ϱ� �ٽ� ���ƿ��� �ڱ��ڽ��� ��ũ �ɱ�
	}//HEAD�� ���°��
	else
	{
		p = CL->head;
		while (p->link!=CL->head)
			p = p->link;
		newnode->link = p->link;
		p->link = newnode;
		CL->head = newnode;
	}
}//��� ó���� ����


void insertMiddleNode(linkedList_h* CL, listNode* pre, const char* x) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy(newnode->data, x);
	if (CL->head==NULL)
	{
		CL->head = newnode;
		newnode->link = newnode;
	}//��尡 ������
	else
	{
		newnode->link = pre->link;//����� ���� ��� ��ũ�� ����� ��ũ�� ����
		pre->link = newnode;//���� ��带 ����忡 ����
	}
}

void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL->head == NULL) return;//��尡 ������
	if (CL->head->link==CL->head)
	{
		free(CL->head);
		CL->head = NULL;
		return;
	}//��尡 ��� �ϳ��϶�
	else if (old==NULL) return;//������ ��尡 ������
	else {
		pre = CL->head;
		while (pre->link!=old) pre = pre->link;//������ ��� ������ �̵�

		pre->link = old->link;//������ ��� �������� ���� ��忬��

		if (old==CL->head) CL->head = old->link;//������ ��尡 ����� ��带 ������ ������ũ�� �Ű���
		free(old);
	}
}

listNode* searchNode(linkedList_h* CL, const char* x) {
	listNode* p;
	p = CL->head;
	if (p == NULL) return NULL;//��尡 ������ NULL��ȯ
	do
	{
		if (strcmp(p->data, x) == 0) return p;//���ؼ� ã���� �ٷ� return p
		else p = p->link;//���ߴµ� �ƴϸ� ������ũ��
	} while (p!=CL->head);//�ѹ��� ��������
	return NULL;//�ѹ��� ���Ҵµ� ������ NULL��ȯ
}