#include <stdio.h>
#include "stackL.h"
#include "evalPostfix.h"

int main() {
	int result;
	char* express = (char *) "35*62/-";
	printf("후위표기식 : %s", express);

	result = evalaPostfix(express);
	printf("\n\n연산결과 => %d\n", result);

	getchar(); return 0;
}