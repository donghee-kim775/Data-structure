#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;//공백이라 아직 가르키는 node없다고 NULL로 초기화
	return L;
}

void freeLinkedList_h(linkedList_h* L) {
	listnode* p;//해제할 메모리 담는곳
	while (L->head == NULL)
	{
		p = L->head;//첫 헤드 메모리 담는다
		L->head = p->link;//해제 하기전 헤드를 앞으로 옯긴다
		free(p);
	}
}

void printList(linkedList_h* L) {
	listnode* p;
	printf("L=(");
	p = L->head;//시작지점 담아주기
	while (p != NULL)//p에 값없을때까지
	{
		printf("%s", p->data);
		p = p->link;//다음으로 옮겨주기
		if (p != NULL)printf(", ");//한번더 실행하기전에 값있으면 (,)
	}
	printf(")\n");
}

void InsertFirstNode(linkedList_h* L, const char* x) {
	listnode* newnode;
	newnode = (listnode*)malloc(sizeof(listnode));
	strcpy(newnode->data, x);//데이터집어넣기
	L->head = newnode;//첫번째 노드 삽입이기에 헤드로 설정
	newnode->link = NULL;//그다음 노드는 정해지지않음 그래서 NULL로 초기화
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
	newnode->link = NULL;//마지막노드가 될거기에 그다음 링크는 NULL

	if (L->head == NULL) {
		L->head = newnode;
		return;//함수종료
	}//만약 헤드가 없고 처음 생성된거라면	

	p = L->head;
	while (p->link != NULL) p = p->link;
	p->link = newnode;
}

void deleteNode(linkedList_h* L, listnode* p) {
	listnode* pre;
	if (L->head == NULL)return;//노드가없을경우
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;//다시 NULL로 초기화
		return;
	}//노드가 하나일 경우
	else if (p == NULL)return;//삭제할 노드가 없다
	else
	{
		pre = L->head;
		while (pre->link!=p)//이다음 노드가 삭제할 노드면 중지
			pre = pre->link;//다음노드로 바꿔주기
		pre->link = p->link;//전링크를 이어주기
		free(p);
	}//삭제할 노드를 찾고 이어주기
}

listnode* searchNode(linkedList_h* L, const char* x) {
	listnode* p;
	p = L->head;
	while (p!=NULL)
	{
		if (strcmp(p->data, x) == 0)return p;//strcmp(문자열비교 같으면 0반환)를 통해 비교
		else p = p->link;//그다음 링크로 이동
	}
	return p;
}//원하는 데이터를 찾고싶을때 노드검색

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
		p = p->link;//그다음 노드로 이동
		q->link = r;
	}
	L->head = q;
}