#include"二叉树2.h"

//初始化


//销毁
//void BinaryTreeDestory(BTNode* root)
//{
//	if (root)
//	{
//		if(root->_left) /* 有左孩子 */
//			BinaryTreeDestory(root->_left); /* 销毁左孩子子树 */
//		if (root->_right) /* 有右孩子 */
//			DestroyBiTree(root->_right); /* 销毁右孩子子树 */
//		free(root); /* 释放根结点 */
//		root = NULL; /* 空指针赋0 */
//	}
//}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	BTNode*newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->_data = a[*pi];
	newNode->_left = NULL;
	newNode->_right = NULL;
	if (a[*pi] != '#')
	{
		BTNode*root = newNode;
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}

void BinaryTreePreorder(BTNode* root)
{
	if (root)
	{
		printf("%c", root->_data);
		BinaryTreePreorder(root->_left);
		BinaryTreePreorder(root->_right);
	}
	else
		return;
}