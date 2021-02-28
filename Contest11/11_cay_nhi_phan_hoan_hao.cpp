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

string check(vector<node*>Muc[1005],int muc_la)
{
	for(int i = 0 ; i <= muc_la ; i++)
		if(pow(2,i)!=Muc[i].size()) return "No";		
	return "Yes";
}

main()
{
	int T,n,u,v,muc_la;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<node*>Muc[1005];
		node *root = NULL;
		while(n--)
		{
			cin>>u>>v>>x;
			if(root == NULL) 
			{
				root = new node(u,0);
				muc_la = 0;
				Muc[0].push_back(root);
			}
			node *temp = Find(root,u);
			if(x == 'L') 
			{
				temp->left = new node(v,temp->muc+1);
				Muc[temp->muc+1].push_back(temp->left);
			}
			else
			{
				temp->right = new node(v,temp->muc+1);
				Muc[temp->muc+1].push_back(temp->right);
			}
			muc_la = max(muc_la,temp->muc+1);
		}
		cout<<check(Muc,muc_la)<<endl;
	}
}
