#include <stdio.h>
#include <stdlib.h>
#include "LinkedPoly.h"

int main() {
	ListHead* A, * B, * C;
	A = createLinkList();
	B = createLinkList();
	C = createLinkList();//합저장공간

	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("\n A(X)=");
	printPoly(A);

	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	printf("\n B(X)=");
	printPoly(B);

	addPoly(A, B, C);
	printf("\n C(X)=");
	printPoly(C);
	getchar(); return 0;
}