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

int MaxSumPath(node *root,int &res)
{
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL) return root->data;
	int leftsum = MaxSumPath(root->left,res);
	int rightsum = MaxSumPath(root->right,res);
	if(root->left&&root->right)
	{
		res = max(res,leftsum+rightsum+root->data);
		return max(leftsum,rightsum)+root->data;
	}
	if(root->left==NULL) return rightsum+root->data;
	return leftsum+root->data;
}

void insert(node *&root, int cha, int con, char c)
{
    if(cha==root->data)
    {
        if(c=='L')
        {
            root->left=new node(con);
            return;
        }
        if(c=='R')
        {
            root->right=new node(con);
            return;
        }
    }
    else if(root->left==NULL && root->right==NULL) return;
    else
    {
        if(root->left) insert(root->left, cha, con, c);
        if(root->right) insert(root->right,cha,con, c);
    }
}
 
main()
{
	int T,n,u,v,res;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = NULL;
		while(n--)
		{
			cin>>u>>v>>x;
			if(root == NULL) root = new node(u);
			insert(root,u,v,x);
		}
		res = INT_MIN;
		MaxSumPath(root,res);
		cout<<res<<endl;
	}
}
//https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
