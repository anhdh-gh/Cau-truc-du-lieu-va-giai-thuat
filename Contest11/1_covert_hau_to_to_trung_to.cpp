#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Cach 1: Su dung stack
//idea: Duyet tu dau den cuoi s
// Neu la toan hang stack.push(s[i])
// Neu la toan tu lay 2 phan tu top cua stack roi push('(' + s2 + toan tu + s1 + ')')
string process1(string a)
{
	stack<string>st;
	for(int i = 0 ; i < a.size() ; i++)
	{
		if(a[i]>='a'&&a[i]<='z') st.push(string(1,a[i]));
		else
		{
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			//st.push("("+s2+" "+a[i]+" "+s1+")");
			st.push(s2+" "+a[i]+" "+s1);
		}
	}
	return st.top();
}

// Cach 2: Su dung cay nhi phan
//1: Chuyen bieu thuc sang cay nhi phan
//   + Xet tu dau den cuoi xau s
// 	 + Neu s[i] la ngan xep => stack.push(s[i])
//	 + Neu la (+,-,*,/) => pop 2 gia tri o dau ngan xep => Bien chung thanh child roi push va stack
//2: Duyet truoc (ben trai truoc)

struct node{
	char data;
	node *left;
	node *right;
	node(char x)
	{
		data = x;
		left = right = NULL;
	}
};

void duyet_truoc(node *t)
{
	if(t != NULL)
	{
		duyet_truoc(t->left);
		cout<<t->data<<" ";
		duyet_truoc(t->right);
	}
}

void process2(string a)
{
	// Xay dung cay
	stack<node*>st;
	node *t,*t1,*t2;
	for(int i = 0 ; i < a.size() ; i++)
	{
		t = new node(a[i]);
		if(a[i]>='a'&&a[i]<='z') st.push(t);
		else 
		{
			t1 = st.top();st.pop();
			t2 = st.top();st.pop();
			t->right = t1;
			t->left = t2;
			st.push(t);
		}		
	}
	duyet_truoc(st.top());
	cout<<endl;
}


main()
{
 	faster()
	int T;
	cin>>T;
	string a;
	cin.ignore();
	while(T--)
	{
		cin>>a;
		cout<<process1(a)<<endl;
		//process2(a);
	}
}
//https://www.geeksforgeeks.org/expression-tree/
//https://practice.geeksforgeeks.org/problems/construct-an-expression-tree/1
