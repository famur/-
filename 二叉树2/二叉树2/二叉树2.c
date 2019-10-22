#include"������2.h"

//��ʼ��


//����
//void BinaryTreeDestory(BTNode* root)
//{
//	if (root)
//	{
//		if(root->_left) /* ������ */
//			BinaryTreeDestory(root->_left); /* ������������ */
//		if (root->_right) /* ���Һ��� */
//			DestroyBiTree(root->_right); /* �����Һ������� */
//		free(root); /* �ͷŸ���� */
//		root = NULL; /* ��ָ�븳0 */
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