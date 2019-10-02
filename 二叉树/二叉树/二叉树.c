#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef char BTdata;

//�� �������Ķ��������������͵Ķ��壻
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
//���������д���������
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
//Ҷ�ӽ����
int BitreeLeaf(BTnode*root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return (BitreeLeaf(root->left) + BitreeLeaf(root->right));
}
//���
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
//��������Ҷ������
int BinaryTreeleafSize(BTnode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeleafSize(root->left) + BinaryTreeleafSize(root->right);
}
//�ݹ�ǰ�����
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
//�ݹ��������
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
//�ݹ�������
void PostOrder(BTnode*root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c", root->data);
	}
}
//�ǵݹ��������
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

//���ȴ�ӡ
int PrintAncestors(BTnode *root, BTdata  x)
{
	if (!root)  return 0;
	if (root->data == x)    return 1;
	//��������п����ҵ�ƥ��ֵ ��ô�˽ڵ�϶������Ƚ��
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
	//���������д����������Ķ�������洢��
	BTnode* tree = CreatTree(a, &i);
	//printf("Ҷ�ӽ����:%d\n", BitreeLeaf(tree));
	//printf("���:%d\n", BitreeDepth(tree));
	//printf("��������Ҷ������:%d", BinaryTreeleafSize(tree));
	//printf("\n�ݹ�ǰ�����:");
	//PreOrder(tree);
	//printf("\n�ݹ��������:");
	//InOrder(tree);
	//printf("\n�ݹ�������:");
	//PostOrder(tree);
	//printf("\n�ǵݹ��������:");
	//Inorders(tree);
	printf("\n��ӡ���ȣ�");
	PrintAncestors(tree,'H' );
	puts("\n");
	system("pause");
	return 0;
}