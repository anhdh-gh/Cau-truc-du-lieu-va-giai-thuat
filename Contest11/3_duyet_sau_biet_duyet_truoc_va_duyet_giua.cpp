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

int Find(int b[],int start,int x)
{
	int i = 0;
	while(b[start+i]!=x) i++;
	return i;
}

// Moi node deu co hanh dong them node ben trai va phai
// t_s: Truoc_start, g_s: giua_start
node *build_tree(int a[],int b[],int t_s,int g_s,int n)
{
	if(n==0) return NULL;
	node *temp = new node(a[t_s]);
	int i = Find(b,g_s,a[t_s]);
	temp->left = build_tree(a,b,t_s+1,g_s,i);
	temp->right = build_tree(a,b,t_s+i+1,g_s+i+1,n-1-i);
	return temp;
}

void Duyet_sau(node *root)
{
	if(root == NULL) return;
	Duyet_sau(root->left);
	Duyet_sau(root->right);
	cout<<root->data<<" ";
}

void process(int a[],int b[],int n)
{
	// Build tree
	node *root = build_tree(a,b,0,0,n);
	// Duyet sau
	Duyet_sau(root);
	cout<<endl;
}

main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[n],b[n];
		for(int i = 0 ; i < n ; i++) cin>>b[i];
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		process(a,b,n);
	}
}
//Cach 2:Ngan hon https://ideone.com/g2HTqO
//https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1
