#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{ 
	BTDataType _data;    
	struct BinaryTreeNode* _left;    
	struct BinaryTreeNode* _right; 
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);
void BinaryTreeDestory(BTNode* root);
void BinaryTreeInit(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ���� 
void BinaryTreePrevOrder(BTNode* root);		 //ǰ��
void BinaryTreeInOrder(BTNode* root);		//����
void BinaryTreePostOrder(BTNode* root);		//����

// ������� 
void BinaryTreeLevelOrder(BTNode* root); 