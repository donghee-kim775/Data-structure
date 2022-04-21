#pragma once
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createlinkedlist_h();
void printlist(linkedList_h* CL);
void insertFirstNode(linkedList_h* CL, const char* x);
void insertMiddleNode(linkedList_h* CL, listNode* pre, const char* x);
void deleteNode(linkedList_h* CL, listNode* old);
listNode* searchNode(linkedList_h* CL, const char* x);
