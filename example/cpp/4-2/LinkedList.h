#pragma once
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listnode;

typedef struct {
	listnode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();//공백리스트 헤드(처음 주소값 받을거) 만들어주기
void freeLinkedList_h(linkedList_h* L);//메모리 전체 해제
void printList(linkedList_h* L);
void InsertFirstNode(linkedList_h* L, const char* x);//첫번째에 노드 삽입
void InsertMiddleNode(linkedList_h* L, listnode* pre, const char* x);//중간에 노드 삽입
void InsertLastNode(linkedList_h* L, const char* x);//마지막에 노드 삽입
void deleteNode(linkedList_h* L, listnode* p);//노드 지우기
listnode* searchNode(linkedList_h* L, const char* x);//노드 찾기
void reverse(linkedList_h* L);//역순