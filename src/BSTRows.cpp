/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct queue
{
	node **q;
	int front, rear, max;
};


typedef struct queue Q;
typedef struct node node;

Q * createQueue(int n)
{
	Q *myq = (Q *)malloc(sizeof(Q));
	myq->q = (node **)malloc(n*sizeof(node));
	myq->front = myq->rear = -1;
	return myq;
}

int noofNodes(struct node * root)
{
	if (root)
	{
		int n = noofNodes(root->left);
		n++;
		n += noofNodes(root->right);
		return n;
	}
	return 0;
}
void enque(Q *myq, node *data)
{
	myq->q[++myq->rear] = data;
}
node * deque(Q *myq)
{
	return myq->q[++myq->front];
}
bool isQueueEmpty(Q *myq)
{
	return myq->front == myq->rear;
}
int *BSTRighttoLeftRows(node * root)
{
	if (root == NULL)
		return NULL;
	int n = noofNodes(root), i = 0;
	int *a = (int *)malloc(n*sizeof(int));
	node *temp = root;
	Q *myq = createQueue(n);
	enque(myq, temp);
	do
	{
		temp = deque(myq);
		a[i++] = temp->data;
		if (temp->right)
			enque(myq, temp->right);
		if (temp->left)
			enque(myq, temp->left);

	} while (!isQueueEmpty(myq));
	return a;
}

