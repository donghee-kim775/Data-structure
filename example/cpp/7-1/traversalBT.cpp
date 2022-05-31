#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(treeNode* root) {
	if (root){
		printf("%c", root->data);
		preorder(root->left);//root의 왼쪽작업
		preorder(root->right);//root의 오른쪽작업
	}
}//전위순회

void inorder(treeNode* root) {
	if (root){
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}//중위순회

void postorder(treeNode* root) {
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}//후위순회