#pragma once
typedef struct ListNode {
	float coef;//���
	int expo;//����
	struct ListNode* link;
}listnode;

typedef struct ListHead {
	ListNode* head;
}ListHead;

ListHead* createLinkList();
void appendTerm(ListHead* L, float coef, int expo);
void addPoly(ListHead* A, ListHead* B, ListHead* C);
void printPoly(ListHead * L);
