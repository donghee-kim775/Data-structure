#include <stdio.h>
#include "traversalBT.h"
int main(void) {
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);//L: n6 R: n7�� ����
	treeNode* n2 = makeRootNode('*', n4, n5);//L: n4 R: n5�� ����
	treeNode* n1 = makeRootNode('-', n2, n3);//L: n2 R: n3�� ����


	printf("\n preorder : ");
	preorder(n1);

	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);

	return 0;
}