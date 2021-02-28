#include <bits/stdc++.h> 
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

node *tao_node(vector<int>a)
{
	int i; // vi tri root
	if(a.size()%2==0) i = a.size()/2-1;
	else i = a.size()/2;
	node *temp = new node(a[i]);
	vector<int>l(a.begin(),a.begin()+i); // Phan ra lam 2 tap 1 tap chua phan tu ben trai
	vector<int>r(a.begin()+i+1,a.end()); // Mot tap chua phan tu ben phai
	if(!l.empty()) temp->left = tao_node(l); // Neu ben trai con phan tu => Call tao ben trai
	if(!r.empty()) temp->right = tao_node(r); // Neu ben phai con phan tu =>Call goi ben phai
	return temp;
}

void Duyet_truoc(node *root)
{
	if(root == NULL) return;
	cout<<root->data<<" ";
	Duyet_truoc(root->left);
	Duyet_truoc(root->right);
}

main() 
{ 
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a(n);
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		sort(a.begin(),a.end());
		node *root = tao_node(a);
		Duyet_truoc(root);
		cout<<endl;
	}
} 
