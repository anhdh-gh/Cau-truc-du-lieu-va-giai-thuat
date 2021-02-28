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

int Duyet_truoc(node *root)
{
	if(root == NULL) return 0;
	if(root->left==NULL&&root->right==NULL) return 0; 
	int l = Duyet_truoc(root->left);
	int r = Duyet_truoc(root->right);
	return 1+l+r;
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
		cout<<Duyet_truoc(root)<<endl;
	}
}
