#include <stdio.h>
#include "stackL.h"
#include "evalPostfix.h"

int main() {
	int result;
	char* express = (char *) "35*62/-";
	printf("����ǥ��� : %s", express);

	result = evalaPostfix(express);
	printf("\n\n������ => %d\n", result);

	getchar(); return 0;
}