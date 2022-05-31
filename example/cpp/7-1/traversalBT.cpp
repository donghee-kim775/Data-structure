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
		preorder(root->left);//root�� �����۾�
		preorder(root->right);//root�� �������۾�
	}
}//������ȸ

void inorder(treeNode* root) {
	if (root){
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}//������ȸ

void postorder(treeNode* root) {
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->data);
}//������ȸ