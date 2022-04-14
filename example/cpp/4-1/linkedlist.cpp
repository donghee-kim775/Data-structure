#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}//공백 연결 리스트 생산

void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head!=NULL){
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
} 

void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf(")\n");
}

void insertFirstNode(linkedList_h* L, const char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, const char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
		if (L == NULL) {
			newNode->link = NULL;
			L->head = newNode;
		}

		else if (pre == NULL)
			L->head = newNode;

		else {
			newNode->link = pre->link;
			pre->link = newNode;
		}
		strcpy(newNode->data, x);
}

void insertLastNode(linkedList_h* L, const char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(ListNode));
		strcpy(newNode->data, x);
		newNode->link = NULL;
		if (L->head == NULL) {
			L->head = newNode;
			return;
		}
		temp = L->head;
		while (temp->link != NULL) temp = temp->link;
		temp->link = newNode;
}