#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;//�����̶� ���� ����Ű�� node���ٰ� NULL�� �ʱ�ȭ
	return L;
}

void freeLinkedList_h(linkedList_h* L) {
	listnode* p;//������ �޸� ��°�
	while (L->head == NULL)
	{
		p = L->head;//ù ��� �޸� ��´�
		L->head = p->link;//���� �ϱ��� ��带 ������ �����
		free(p);
	}
}

void printList(linkedList_h* L) {
	listnode* p;
	printf("L=(");
	p = L->head;//�������� ����ֱ�
	while (p != NULL)//p�� ������������
	{
		printf("%s", p->data);
		p = p->link;//�������� �Ű��ֱ�
		if (p != NULL)printf(", ");//�ѹ��� �����ϱ����� �������� (,)
	}
	printf(")\n");
}

void InsertFirstNode(linkedList_h* L, const char* x) {
	listnode* newnode;
	newnode = (listnode*)malloc(sizeof(listnode));
	strcpy(newnode->data, x);//����������ֱ�
	L->head = newnode;//ù��° ��� �����̱⿡ ���� ����
	newnode->link = NULL;//�״��� ���� ������������ �׷��� NULL�� �ʱ�ȭ
}

void InsertMiddleNode(linkedList_h* L, listnode* pre, const char* x) {
	listnode* newnode;
	newnode = (listnode*)malloc(sizeof(listnode));
	strcpy(newnode->data, x);
	if (L->head==NULL){
		newnode->link = NULL;
		L->head = newnode;
	}
	else if (pre == NULL) {
		newnode->link = L->head;
		L->head = newnode;
	}
	else{
		newnode->link = pre->link;
		pre->link = newnode;
	}
}

void InsertLastNode(linkedList_h* L, const char* x) {
	listnode* p;
	listnode* newnode;
	newnode = (listnode*)malloc(sizeof(listnode));
	strcpy(newnode->data, x);
	newnode->link = NULL;//��������尡 �ɰű⿡ �״��� ��ũ�� NULL

	if (L->head == NULL) {
		L->head = newnode;
		return;//�Լ�����
	}//���� ��尡 ���� ó�� �����ȰŶ��	

	p = L->head;
	while (p->link != NULL) p = p->link;
	p->link = newnode;
}

void deleteNode(linkedList_h* L, listnode* p) {
	listnode* pre;
	if (L->head == NULL)return;//��尡�������
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;//�ٽ� NULL�� �ʱ�ȭ
		return;
	}//��尡 �ϳ��� ���
	else if (p == NULL)return;//������ ��尡 ����
	else
	{
		pre = L->head;
		while (pre->link!=p)//�̴��� ��尡 ������ ���� ����
			pre = pre->link;//�������� �ٲ��ֱ�
		pre->link = p->link;//����ũ�� �̾��ֱ�
		free(p);
	}//������ ��带 ã�� �̾��ֱ�
}

listnode* searchNode(linkedList_h* L, const char* x) {
	listnode* p;
	p = L->head;
	while (p!=NULL)
	{
		if (strcmp(p->data, x) == 0)return p;//strcmp(���ڿ��� ������ 0��ȯ)�� ���� ��
		else p = p->link;//�״��� ��ũ�� �̵�
	}
	return p;
}//���ϴ� �����͸� ã������� ���˻�

void reverse(linkedList_h* L) {
	listnode* p;
	listnode* q;
	listnode* r;
	
	p = L->head;
	q = NULL;
	r = NULL;
	while (p!=NULL)
	{
		r = q;
		q = p;
		p = p->link;//�״��� ���� �̵�
		q->link = r;
	}
	L->head = q;
}