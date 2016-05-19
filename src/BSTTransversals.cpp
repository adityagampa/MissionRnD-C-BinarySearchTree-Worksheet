/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
typedef struct node node;

int myinorder(node * root, int *a, int i)
{
	if (root)
	{
		i = myinorder(root->left, a, i);
		a[i] = root->data;
		return myinorder(root->right, a, i + 1);
	}
	return i;
}
void inorder(node * root, int *a)
{
	myinorder(root, a, 0);
}
int mypreorder(node * root, int *a, int i)
{
	if (root)
	{
		a[i] = root->data;
		i = mypreorder(root->left, a, i + 1);
		return mypreorder(root->right, a, i);
	}
	return i;
}
void preorder(node * root, int *a)
{
	mypreorder(root, a, 0);
}int mypostorder(node * root, int *a, int i)
{
	if (root)
	{
		i = mypostorder(root->left, a, i);
		i = mypostorder(root->right, a, i);
		a[i] = root->data;
		return i + 1;
	}
	return i;
}
void postorder(node * root, int *a)
{
	mypostorder(root, a, 0);
}