#include<bits/stdc++.h>
using namespace std;
// Idea: This is binary tree full
// Each node i have 2 child node in position 2*i+1 and 2*i+2

int caculate(string a,string x,string b)
{
	int t1=stoi(a),t2=stoi(b);
	if(x=="+") return t1+t2;
	if(x=="-") return t1-t2;
	if(x=="*") return t1*t2;
	if(x=="/") return t1/t2;	
}

// Use array
string process1(string a[],int n)
{
	for(int i = n-1 ; i >= 2 ; i-=2)
		a[(i-2)/2] = to_string(caculate(a[i-1],a[(i-2)/2],a[i]));
	return a[0];
}

// Use binary tree 
struct node{
	string data;
	node *left;
	node *right;
	node(string x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

node *build_tree(string a[],int n,int i)
{
	if(i >= n) return NULL;
	node *temp = new node(a[i]);
	temp->left = build_tree(a,n,2*i+1);
	temp->right = build_tree(a,n,2*i+2);
	return temp;
}

string CACULATE(node *root)
{
	if(root->left==NULL&&root->right==NULL) return root->data;
	string a = CACULATE(root->left);
	string b = CACULATE(root->right);
	return to_string(caculate(a,root->data,b));
}

string process2(string a[],int n)
{
	node *root = build_tree(a,n,0);
	return CACULATE(root);
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		string a[n];
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		//cout<<process1(a,n)<<endl;
		cout<<process2(a,n)<<endl;
	}
}
