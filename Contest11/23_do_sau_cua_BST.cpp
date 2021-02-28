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

int Find(vector<int>a,int start,int n,int x)
{
	if(start >= a.size()-1) return 0;
	for(int i = 0 ; i < n-1 ; i++)
		if(a[start+i] > x) 
			return i;
	return 0;
}

int muc_max;
node *build_node(vector<int>a,int start,int n,int muc_cha)
{
	if(n==0) return NULL;
	node *temp = new node(a[start],muc_cha+1); muc_max = max(muc_max,muc_cha+1);
	int i = Find(a,start+1,n,a[start]);
	temp->left = build_node(a,start+1,i,temp->muc);
	temp->right = build_node(a,start+i+1,n-1-i,temp->muc);
	return temp;
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
		muc_max = -1005;	
		node *root = build_node(a,0,n,-1); // Tinh tu muc 0
		cout<<muc_max<<endl;
	}
}
