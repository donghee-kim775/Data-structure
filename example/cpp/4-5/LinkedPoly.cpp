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
        }//지수가 같다면
        else if (pa->expo > pb->expo) {
            appendTerm(C, pa->coef, pa->expo);
            pa = pa->link;
        }//pa의 큰차항이 있다면 넣어주고 pb랑 차수 같아질때까지 그다음 링크걸기
        else {
            appendTerm(C, pb->coef, pb->expo);
            pb = pb->link;
        }//pb의 큰차항이 있다면 넣어주고 pa랑 차수 같아질때까지 그다음 링크걸기
    }//두 다항식에 노드가 있는 동안 반복수행

    //그이후 남아있는 노드가 있다면
    for (; pa != NULL; pa = pa->link)
        appendTerm(C, pa->coef, pa->expo);// 항이 남아 있는 경우 반복으로 남은거 더해주기

    for (; pb != NULL; pb = pb->link)
        appendTerm(C, pb->coef, pb->expo);// 항이 남아 있는 경우 반복으로 남은거 더해주기
}

void printPoly(ListHead* L) {
    listnode* p = L->head;
    for (; p; p=p->link){
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" + ");
    }//노드 print하고 다음노드로 옮기고 또 print
}