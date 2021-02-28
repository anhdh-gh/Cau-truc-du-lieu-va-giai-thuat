#include<bits/stdc++.h>
using namespace std;

//Duyet truoc (Preorder) NLR: NODE->LEFT->RIGHT: Duyet goc truoc => Duyet all ben trai => Duyet all ben phai
//Duyet giua (Inorder) LNR: lEFT->NODE->RIGHT: Duyet all ben trai truoc => Duyet goc => Duyet all ben phai
//Duyet sau (Postorder) LRN: LEFT->RIGHT->NODE: Duyet all ben trai => Duyet all ben phai => Duyet goc
//Ten duyet la vi tri cua NODE trong N,L,R 

//Idea:
//Duyet truoc:  a[] = 1  2  4  5  3  6	   		=> node a[0] = 1 la goc (root)
//Duyet giua:   b[] = 4  2  5 |1| 3  6 		    => co 3 node (4,2,5) la node ben trai, co 2 node (3,6) la node ben phai node 1(root)
//			L	  N	   R
//=> b[] = |4 2 5| |1| |3 6|
//		  N		L	   R
//=> a[] = |1| |2 4 5| |3 6|		=> node 2 la node trai cua 1, node 3 la node phai cua 1
//												
//=> b[] = (4 |2| 5) |1| (|3| 6)	=> co 1 node (4) la node ben trai, co 1 node (5) la node ben phai node 2
//								=> co 0 node la node ben trai, co 1 node (6) la node ben phai cua 3
//								
//						Tu a[]	=> 4 la node trai cua 2, 5 la node phai cua 2
//								=> 6 la node phai cua 3
//															1
//														   /  \
//														  2	   3
//													     / \	\
//													    4	5 	 6
//Duyet sau: c[] = 4 5 2 6 3 1

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

node *build_tree(vector<int>in,vector<int>pre,int s_p)
{
	node *temp = new node(pre[s_p]);
	int i = find(in.begin(),in.end(),pre[s_p])-in.begin();
	vector<int>l(in.begin(),in.begin()+i);
	vector<int>r(in.begin()+i+1,in.end());
	if(!l.empty()) temp->left = build_tree(l,pre,s_p+1);
	if(!r.empty()) temp->right = build_tree(r,pre,s_p+1+l.size());
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
		vector<int>in(n),pre(n);
		for(int i = 0 ; i < n ; i++) cin>>in[i];
		for(int i = 0 ; i < n ; i++) cin>>pre[i];
		node *root = build_tree(in,pre,0);
		Duyet_sau(root);
		cout<<endl;
	}
}
