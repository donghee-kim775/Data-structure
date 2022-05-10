#include <stdio.h>
#include "stackL.h"
#include "testpair.h"

int main(void) {
	const char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);
	if (testPair(express) == 1) printf("\n\n 수식의 괄호가 맞게 사용되었습니다");
	else printf("\n\n 수식의 괄호가 틀렷습니다!");

	getchar(); return 0;
}