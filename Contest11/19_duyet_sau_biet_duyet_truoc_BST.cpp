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

int Find(vector<int>a,int s,int n,int x)
{
	if(s >= a.size()-1) return 0;
	for(int i = 0 ; i < n ; i++)
		if(a[s+i] > x) return i;
	return 0;
}

node *build_node(vector<int>a,int s,int n)
{
	if(n==0) return NULL;
	node *temp = new node(a[s]);
	int i = Find(a,s+1,n-1,a[s]);
	temp->left = build_node(a,s+1,i);
	temp->right = build_node(a,s+1+i,n-1-i);
	return temp;
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
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a(n);
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		node *root = build_node(a,0,n);
		Duyet_sau(root);
		cout<<endl;
	}
}
