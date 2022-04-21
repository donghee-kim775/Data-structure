#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circularlinkedlist.h"
linkedList_h* createlinkedlist_h() {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));//head노드 할당
	CL->head = NULL;//공백이기에 NULL로 초기화
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
		CL->head = newnode;//헤드를 뉴노드에 저장하고
		newnode->link = newnode;//원형이니까 다시 돌아오게 자기자신을 링크 걸기
	}//HEAD가 없는경우
	else
	{
		p = CL->head;
		while (p->link!=CL->head)
			p = p->link;
		newnode->link = p->link;
		p->link = newnode;
		CL->head = newnode;
	}
}//노드 처음에 삽입


void insertMiddleNode(linkedList_h* CL, listNode* pre, const char* x) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy(newnode->data, x);
	if (CL->head==NULL)
	{
		CL->head = newnode;
		newnode->link = newnode;
	}//헤드가 없을때
	else
	{
		newnode->link = pre->link;//뉴노드 전에 노드 링크를 뉴노드 링크에 연결
		pre->link = newnode;//전에 노드를 뉴노드에 연결
	}
}

void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;
	if (CL->head == NULL) return;//노드가 없을때
	if (CL->head->link==CL->head)
	{
		free(CL->head);
		CL->head = NULL;
		return;
	}//노드가 헤드 하나일때
	else if (old==NULL) return;//삭제할 노드가 없을때
	else {
		pre = CL->head;
		while (pre->link!=old) pre = pre->link;//삭제할 노드 전까지 이동

		pre->link = old->link;//삭제할 노드 다음노드와 그전 노드연결

		if (old==CL->head) CL->head = old->link;//삭제할 노드가 헤드라면 헤드를 삭제할 다음링크로 옮겨줌
		free(old);
	}
}

listNode* searchNode(linkedList_h* CL, const char* x) {
	listNode* p;
	p = CL->head;
	if (p == NULL) return NULL;//노드가 없으면 NULL반환
	do
	{
		if (strcmp(p->data, x) == 0) return p;//비교해서 찾으면 바로 return p
		else p = p->link;//비교했는데 아니면 다음링크로
	} while (p!=CL->head);//한바퀴 돌때까지
	return NULL;//한바퀴 돌았는데 없으면 NULL반환
}