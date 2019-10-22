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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int* pi);
void BinaryTreeDestory(BTNode* root);
void BinaryTreeInit(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 遍历 
void BinaryTreePrevOrder(BTNode* root);		 //前序
void BinaryTreeInOrder(BTNode* root);		//中序
void BinaryTreePostOrder(BTNode* root);		//后序

// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root); 