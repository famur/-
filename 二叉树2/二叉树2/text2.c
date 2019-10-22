#include"¶þ²æÊ÷2.c"
int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int index=0;
	BTNode*tree;
	tree=BinaryTreeCreate(a, &index);
	BinaryTreePrevOrder(tree);
	system("pause");
	return 0;
}