#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;	
	}	
};

node *Find(node *root,int U)
{
	if(root == NULL) return NULL;
	if(root->data == U) return root;
	node *temp1 = Find(root->left,U);
	node *temp2 = Find(root->right,U);
	if(temp1!=NULL) return temp1;
	return temp2;
}

void BFS(node *root)
{
	queue<node*>q;
	if(root != NULL) q.push(root);
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left != NULL) q.push(root->left);
		if(root->right != NULL) q.push(root->right);
	}
	cout<<endl;
}

main()
{
	int T,n,U,V;
	char X;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = NULL;
		while(n--)
		{
			cin>>U>>V>>X;
			if(root == NULL) root = new node(U);
			node *temp = Find(root,U);
			if(X=='L') temp->left = new node(V);
			else temp->right = new node(V);
		}
		BFS(root);
	}
}
