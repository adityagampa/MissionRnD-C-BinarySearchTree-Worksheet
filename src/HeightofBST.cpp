/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



int get_height(struct node *root)
{
	if (root)
	{
		int left = get_height(root->left);
		int right = get_height(root->right);
		if (left>right)
			return 1 + left;
		else
			return 1 + right;
	}
	return 0;
}
int get_left_sum(struct node *root)
{
	if (root)
	{
		int sum = get_left_sum(root->left);
		sum += get_left_sum(root->right);
		return sum + root->data;
	}
	return 0;
}
int get_left_subtree_sum(struct node *root)
{
	if (root)
	{
		return get_left_sum(root->left);
	}
	return -1;
}
int get_right_sum(struct node *root)
{
	if (root)
	{
		int sum = get_right_sum(root->left);
		sum += get_right_sum(root->right);
		return sum + root->data;
	}
	return 0;
}
int get_right_subtree_sum(struct node *root)
{
	if (root)
	{
		return get_right_sum(root->right);
	}
	return -1;
}
