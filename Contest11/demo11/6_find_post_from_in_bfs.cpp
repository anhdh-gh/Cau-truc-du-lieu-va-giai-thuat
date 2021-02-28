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

// Tim vi tri gan voi bfs[s_b] nhat
int Find(vector<int>bfs,vector<int>temp)
{
	int vi_tri = INT_MAX;
	for(int i = 0 ; i < temp.size() ; i++)
		for(int j = 0 ; j < bfs.size() ; j++)
			if(bfs[j]==temp[i])
				vi_tri = min(vi_tri,j);
	return vi_tri;
}

node *build_tree(vector<int>in,vector<int>bfs,int s_b)
{
	node *temp = new node(bfs[s_b]);
	int i = find(in.begin(),in.end(),bfs[s_b])-in.begin();
	vector<int>l(in.begin(),in.begin()+i);
	vector<int>r(in.begin()+1+i,in.end());
	if(!l.empty()) temp->left = build_tree(l,bfs,Find(bfs,l));
	if(!r.empty()) temp->right = build_tree(r,bfs,Find(bfs,r));
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
		vector<int>in(n),bfs(n);
		for(int i = 0 ; i < n ; i++) cin>>in[i];
		for(int i = 0 ; i < n ; i++) cin>>bfs[i];
		node *root = build_tree(in,bfs,0);
		Duyet_sau(root);
		cout<<endl;
	}
}
