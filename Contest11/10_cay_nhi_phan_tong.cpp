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

node* TaoCay(int n)
{
	int a,b;char c;
	map<int,node*>m;
	node *root = NULL;
	while(n--)
	{
		cin>>a>>b>>c;
		node *cha = NULL;
		if(m.find(a)==m.end())
		{
			cha = new node(a);
			m[a] = cha;
			if(root == NULL) root = cha;
		}
		else cha = m[a];
		node *con = new node(b);
		if(c=='L') cha->left = con;
		else cha->right = con;
		m[b] = con;
	}
	return root;
}

int sum(node *root)
{
	if(root == NULL) return 0;
	int sum_left = sum(root->left);
	int sum_right = sum(root->right);
	if((sum_left==0 && sum_right==0)||(root->data == sum_left+sum_right)) 
		return root->data+sum_left+sum_right;
	return -1e9;
}

main()
{
	int T,n,u,v,i;
	char x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		node *root = TaoCay(n);
		i = sum(root);
		if(i < 0) cout<<0;
		else cout<<1;
		cout<<endl;
	}
}
