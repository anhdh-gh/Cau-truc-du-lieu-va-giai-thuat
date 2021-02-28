#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int muc;
	node *left;
	node *right;
	node(int x,int m)
	{
		data = x;
		muc = m;
		left = NULL;
		right = NULL;
	}
};

int do_sau;
void build_tree(node *&root,int x,int m)
{
	if(root==NULL){root = new node(x,m+1);do_sau = max(do_sau,root->muc);return;}
	if(x < root->data) build_tree(root->left,x,root->muc);
	else build_tree(root->right,x,root->muc);
}

main()
{
	int T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = NULL;
		do_sau = INT_MIN;
		while(n--)
		{
			cin>>x;
			build_tree(root,x,-1);
		}
		cout<<do_sau<<endl;
	}
}
