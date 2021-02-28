#include<bits/stdc++.h>
using namespace std;

string process1(string a)
{
	stack<string>st;
	for(int i = 0 ; i < a.size() ; i++)
		if(a[i]>='a'&&a[i]<='z') st.push(string(1,a[i]));
		else
		{
			string t1 = st.top(); st.pop();
			string t2 = st.top(); st.pop();
			st.push(t2+" "+a[i]+" "+t1);
			//st.push("("+t2+" "+a[i]+" "+t1+")");
		}
	return st.top();
}

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

void Duyet_giua(node *root)
{
	if(root == NULL) return;
	Duyet_giua(root->left);
	cout<<root->data<<" ";
	Duyet_giua(root->right);
}

void process2(string a)
{
	stack<node*>st;
	for(int i = 0 ; i < a.size() ; i++)
	{
		node *temp = new node(string(1,a[i]));
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			temp->right = st.top(); st.pop();
			temp->left = st.top(); st.pop();
		}
		st.push(temp);
	}
	Duyet_giua(st.top());
	cout<<endl;
}

main()
{
	int T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		//cout<<process1(a)<<endl;
		process2(a);
	}
}
