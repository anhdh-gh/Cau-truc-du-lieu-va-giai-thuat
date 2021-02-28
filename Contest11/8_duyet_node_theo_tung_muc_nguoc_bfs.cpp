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

node *Find(node *root,int U)
{
	if(root == NULL) return NULL;
	if(root->data == U) return root;
	node *temp1 = Find(root->left,U);
	node *temp2 = Find(root->right,U);
	if(temp1!=NULL) return temp1;
	return temp2;
}

// Idea: Duyet BFS ghi lai node cua tung muc => In ra theo muc lon -> nho

void BFS(node *root)
{
	vector<int>Muc[1005];
	queue<node*>q;
	if(root != NULL) q.push(root);
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		Muc[root->muc].push_back(root->data);
		if(root->left != NULL) q.push(root->left);
		if(root->right != NULL) q.push(root->right);
	}
	for(int i = 1004 ; i >= 0 ; i--)
		if(!Muc[i].empty()) 
				for(int j = 0 ; j < Muc[i].size() ; j++)
				    cout<<Muc[i][j]<<" ";
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
			if(root == NULL) root = new node(U,1);
			node *temp = Find(root,U);
			if(X=='L') temp->left = new node(V,temp->muc+1);
			else temp->right = new node(V,temp->muc+1);
		}
		BFS(root);
	}
}
