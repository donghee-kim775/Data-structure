#pragma once
#ifndef __node_H__
#define __node_H__
typedef char element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

void displayInorder(treeNode* root);
#endif // !__node_H__