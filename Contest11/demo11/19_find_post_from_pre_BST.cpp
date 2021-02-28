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

void build_tree(node *&root,int x)
{
	if(root==NULL){root = new node(x);return;}
	if(x < root->data) build_tree(root->left,x);
	else build_tree(root->right,x);
}

void Duyet_sau(node *root)
{
	if(root == NULL) return;
	Duyet_sau(root->left);
	Duyet_sau(root->right);
	cout<<root->data<<" ";
}

main()
{
	int T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = NULL;
		while(n--)
		{
			cin>>x;
			build_tree(root,x);
		}
		Duyet_sau(root);
		cout<<endl;
	}
}
