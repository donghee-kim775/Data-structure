#include <stdio.h>
#include <stdlib.h>
#include "LinkedPoly.h"

ListHead* createLinkList() {
    ListHead* L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}

void appendTerm(ListHead* L, float coef, int expo) {
    listnode* newnode;
    newnode = (listnode*)malloc(sizeof(listnode));
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->link = NULL;

    if (L->head == NULL) {
        newnode = L->head;
        return;
    }
    else {
        listnode* p;
        p = L->head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = newnode;
    }
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {
    listnode* pa = A->head;
    listnode* pb = B->head;
    float sum;

    while (pa && pb) {
        if (pa->expo == pb->expo) {
            sum = pa->expo + pb->expo;
            appendTerm(C, sum, pa->expo);
            pa = pa->link; pb = pb->link;
        }//������ ���ٸ�
        else if (pa->expo > pb->expo) {
            appendTerm(C, pa->coef, pa->expo);
            pa = pa->link;
        }//pa�� ū������ �ִٸ� �־��ְ� pb�� ���� ������������ �״��� ��ũ�ɱ�
        else {
            appendTerm(C, pb->coef, pb->expo);
            pb = pb->link;
        }//pb�� ū������ �ִٸ� �־��ְ� pa�� ���� ������������ �״��� ��ũ�ɱ�
    }//�� ���׽Ŀ� ��尡 �ִ� ���� �ݺ�����

    //������ �����ִ� ��尡 �ִٸ�
    for (; pa != NULL; pa = pa->link)
        appendTerm(C, pa->coef, pa->expo);// ���� ���� �ִ� ��� �ݺ����� ������ �����ֱ�

    for (; pb != NULL; pb = pb->link)
        appendTerm(C, pb->coef, pb->expo);// ���� ���� �ִ� ��� �ݺ����� ������ �����ֱ�
}

void printPoly(ListHead* L) {
    listnode* p = L->head;
    for (; p; p=p->link){
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" + ");
    }//��� print�ϰ� �������� �ű�� �� print
}