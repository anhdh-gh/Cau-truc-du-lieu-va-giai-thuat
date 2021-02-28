#include <bits/stdc++.h> 
using namespace std; 
//Tu array duyet bfs => Duyet giua bang cach sort
// Idea: Tao_node(a,b,s_a)
// s_a: Vi tri tao node tu a[s_a] => temp = node(a[s_a])
// Call tao_node(a,b,0)
// Tim vi tri i cua a[s_a] trong array b
// Tao 2 array 
//  + array Left[b,b+i-1] => j = Tim trong a[] Vi tri phan tu Left[j] gan nhat voi a[s_a]
//	+ array Right[b+i+1,b.end] => k = Tim trong a[] Vi tri phan tu Right[k] gan nhat voi a[s_a]
// Neu left!=rong => Call temp->left = tao_node(a,Left,j)
// Neu Right!=rong => Call temp->right = tao_node(a,Right,k)

struct node 
{ 
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

//Tim so gan nhat trong a
int Find(vector<int>a,vector<int>temp)
{
	int vt_min = 1005;
	for(int i = 0 ; i < temp.size() ; i++)
		for(int j = 0 ; j < a.size() ; j++)
			if(a[j]==temp[i]) 
				vt_min = min(vt_min,j);
	return vt_min;
}

node *tao_node(vector<int>a,vector<int>b,int s_a)
{
	node *temp = new node(a[s_a]);
	int i = find(b.begin(),b.end(),a[s_a])-b.begin();
	vector<int>l(b.begin(),b.begin()+i);
	vector<int>r(b.begin()+i+1,b.end());
	if(!l.empty()) temp->left = tao_node(a,l,Find(a,l));
	if(!r.empty()) temp->right = tao_node(a,r,Find(a,r));
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
	int T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>a; //Duyet bfs
		while(n--) {cin>>x;a.push_back(x);}
		vector<int>b(a);sort(b.begin(),b.end()); //Duyet giua
		node *root = tao_node(a,b,0);
		Duyet_truoc(root);
		cout<<endl;
	}
} 

//#include<bits/stdc++.h>
//using namespace std;
//int n,a[111111];
//struct node{
//	int data;
//	node *trai,*phai;
//};
//node *TaoNode(int data){
//	node *t=new node;
//	t->data=data;
//	t->trai=NULL;t->phai=NULL;
//	return t;
//}
//void TaoCay(node *&cay,int data){
//	if(cay==NULL) cay=TaoNode(data);
//	else{
//		if(data<cay->data) TaoCay(cay->trai,data);
//		else TaoCay(cay->phai,data);
//	}
//}
//void DuyetTruoc(node *cay){
//	if(cay!=NULL){
//		cout<<cay->data<<" ";
//		DuyetTruoc(cay->trai);
//		DuyetTruoc(cay->phai);
//	}
//}
//int main(){
//	int T;cin>>T;
//	while(T--){
//		node *cay=NULL;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//			TaoCay(cay,a[i]);
//		}
//		DuyetTruoc(cay);
//		cout<<endl;
//	}
//	return 0;
//}
