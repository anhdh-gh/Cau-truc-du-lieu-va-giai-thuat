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

node* Find(node *root,int u)
{
	if(root == NULL) return NULL;
	if(root->data == u) return root;
	node *temp1 = Find(root->left,u);
	node *temp2 = Find(root->right,u);
	if(temp1 != NULL) return temp1;
	return temp2;
}

int check(node *root,int muc_la)
{
	if(root == NULL) return 1;
	if(root->left == NULL && root->right == NULL)
		if(root->muc != muc_la) return 0;
	int temp1 = check(root->left,muc_la);
	int temp2 = check(root->right,muc_la);
	if(temp1 == 0) return temp1;
	return temp2; 
}

main()
{
	int T,n,u,v,muc_la;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = NULL;
		while(n--)
		{
			cin>>u>>v>>x;
			if(root == NULL) 
			{
				root = new node(u,1);
				muc_la = 1;
			}
			node *temp = Find(root,u);
			if(x == 'L') temp->left = new node(v,temp->muc+1);
			else temp->right = new node(v,temp->muc+1);
			muc_la = max(muc_la,temp->muc+1);
		}
		cout<<check(root,muc_la)<<endl;
	}
}
