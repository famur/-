#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef char BTdata;

//⑴ 二叉树的二叉链表数据类型的定义；
typedef struct  BinaryTree
{
	BTdata data;
	struct  BinaryTree* left;
	struct  BinaryTree* right;
}BTnode;

BTnode* NewBTnode(BTdata a)
{
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	node->data = a;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//以先序序列创建二叉树
BTnode* CreatTree(BTdata* a, int*p)
{
	if (a[*p] != '#')
	{
		BTnode *root = NewBTnode(a[*p]);
		++(*p);
		root->left = CreatTree(a, p);
		++(*p);
		root->right = CreatTree(a, p);
		return root;
	}
	else
	{
		return NULL;

	}

}
//叶子结点数
int BitreeLeaf(BTnode*root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return (BitreeLeaf(root->left) + BitreeLeaf(root->right));
}
//深度
int BitreeDepth(BTnode*root)
{
	int d = 0, depthl, depthr;
	if (root == NULL)
	{
		return 0;
	}
	depthl = BitreeDepth(root->left);
	depthr = BitreeDepth(root->right);
	d = depthl >= depthr ? depthl : depthr;
	return d + 1;
}
//二叉树的叶子总数
int BinaryTreeleafSize(BTnode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeleafSize(root->left) + BinaryTreeleafSize(root->right);
}
//递归前序遍历
void PreOrder(BTnode* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
	else
		return ;
}
//递归中序遍历
void InOrder(BTnode*root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("%c", root->data);
		InOrder(root->right);
	}
	else
		return;
}
//递归后序遍历
void PostOrder(BTnode*root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c", root->data);
	}
}
//非递归中序遍历
void Inorders(BTnode* root)
{
	BTnode* st[MAXSIZE];
	BTnode* cur = root;
	int top = -1;
	while (top != -1 || cur)
	{
		while (cur)
		{
			st[++top] = cur;
			cur = cur->left;
		}

		cur = st[top--];
		printf("%c", cur->data);

		cur = cur->right;
	}
}

//祖先打印
int PrintAncestors(BTnode *root, BTdata  x)
{
	if (!root)  return 0;
	if (root->data == x)    return 1;
	//如果子树中可以找到匹配值 那么此节点肯定是祖先结点
	if (PrintAncestors(root->left, x) || PrintAncestors(root->right, x))
	{
		printf("%c ", root->data);
		return 1;
	}
	return 0;
}

int main()
{
	BTdata a[] = "ABD##E#H##CF##G##";
	int i = 0;
	//以先序序列创建二叉树的二叉链表存储；
	BTnode* tree = CreatTree(a, &i);
	//printf("叶子结点数:%d\n", BitreeLeaf(tree));
	//printf("深度:%d\n", BitreeDepth(tree));
	//printf("二叉树的叶子总数:%d", BinaryTreeleafSize(tree));
	//printf("\n递归前序遍历:");
	//PreOrder(tree);
	//printf("\n递归中序遍历:");
	//InOrder(tree);
	//printf("\n递归后序遍历:");
	//PostOrder(tree);
	//printf("\n非递归中序遍历:");
	//Inorders(tree);
	printf("\n打印祖先：");
	PrintAncestors(tree,'H' );
	puts("\n");
	system("pause");
	return 0;
}