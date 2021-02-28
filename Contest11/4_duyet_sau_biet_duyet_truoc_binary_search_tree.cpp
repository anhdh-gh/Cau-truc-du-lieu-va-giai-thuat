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

void duyet_sau(node *root)
{
	if(root == NULL) return;
	duyet_sau(root->left);
	duyet_sau(root->right);
	cout<<root->data<<" ";
}

int Find(int a[],int start,int x,int m)
{
	if(start >= m-1) return 0;
	int i = 0;
	while(a[start+i] < x) i++;
	return i;
}

node *build_tree(int a[],int start,int n,int m)
{
	if(n==0) return NULL;
	node *temp = new node(a[start]);
	int i = Find(a,start+1,a[start],m);
	temp->left = build_tree(a,start+1,i,m);
	temp->right = build_tree(a,start+1+i,n-1-i,m);
	return temp;
}

void process(int a[],int n)
{
	int m = n;
	node *root = build_tree(a,0,n,m);
	duyet_sau(root);
	cout<<endl;
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[n];
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		process(a,n);
	}
}
