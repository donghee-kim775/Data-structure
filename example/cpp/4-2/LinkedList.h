#pragma once
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listnode;

typedef struct {
	listnode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();//���鸮��Ʈ ���(ó�� �ּҰ� ������) ������ֱ�
void freeLinkedList_h(linkedList_h* L);//�޸� ��ü ����
void printList(linkedList_h* L);
void InsertFirstNode(linkedList_h* L, const char* x);//ù��°�� ��� ����
void InsertMiddleNode(linkedList_h* L, listnode* pre, const char* x);//�߰��� ��� ����
void InsertLastNode(linkedList_h* L, const char* x);//�������� ��� ����
void deleteNode(linkedList_h* L, listnode* p);//��� �����
listnode* searchNode(linkedList_h* L, const char* x);//��� ã��
void reverse(linkedList_h* L);//����