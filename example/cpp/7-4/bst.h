#pragma once
#ifndef __bst_H__
#define __bst_H__
#include "node.h"

treeNode* searchBST(treeNode* root, element x);
treeNode* insertBSTNode(treeNode* p, element x);
void deleteBSTNode(treeNode* root, element key);

#endif // !__bst_H__
