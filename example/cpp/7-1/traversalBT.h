#pragma once
#ifndef __TraversalBT_H__
#define __TraversalBT_H__

typedef char element;

typedef struct treeNode {
	element data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);
#endif // !__TraversalBT_H__
