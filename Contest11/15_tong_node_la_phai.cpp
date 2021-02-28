#include<bits/stdc++.h>
using namespace std;
 
struct node{
	int data;
	char ben;
	node *left;
	node *right;
	node(int x,char b)
	{
		data = x;
		ben = b;
		left = NULL;
		right = NULL;
	}
};

node *tao_cay(int n)
{
	int a,b;char c;
	map<int,node*>m;
	node *root = NULL;
	while(n--)
	{
		cin>>a>>b>>c;
		node *cha;
		if(m.find(a)==m.end())
		{
			cha = new node(a,'R');
			m[a] = cha;
			if(root == NULL) root = cha;
		}
		else cha = m[a];
		node *con = new node(b,c);
		if(c=='L') cha->left = con;
		else cha->right = con;
		m[b] = con;
	}
	return root;
}

int sum(node *root)
{
	if(root == NULL) return 0;
	if(root->left==NULL&&root->right==NULL&&root->ben=='R')
		return root->data;
	int temp1 = sum(root->left);
	int temp2 = sum(root->right);
	return temp1+temp2;
}
 
main()
{
	int T,n,u,v,res;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = tao_cay(n);
		cout<<sum(root)<<endl;
	}
}
