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

int check(node *root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		if(root->left==NULL&&root->right==NULL) continue;
		else if(root->left!=NULL&&root->right!=NULL) {q.push(root->left);q.push(root->right);}
		else return 0;
	}	
	return 1;
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
		cout<<check(root)<<endl;
	}
}
