#include <stdio.h>
#include "stackL.h"
#include "testpair.h"

int main(void) {
	const char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);
	if (testPair(express) == 1) printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�");
	else printf("\n\n ������ ��ȣ�� Ʋ�ǽ��ϴ�!");

	getchar(); return 0;
}