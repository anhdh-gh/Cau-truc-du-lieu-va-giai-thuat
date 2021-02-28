#include<bits/stdc++.h>
using namespace std;

long long priority(char a)
{
	if(a=='^') return 3;
	if(a=='*'||a=='/') return 2;
	if(a=='+'||a=='-') return 1;
	return 0;
}

void process(string s)
{
	string res;
	stack<char>STACK;
	for(long long i = 0 ; i < s.size() ; i++)
	{
		if(s[i]=='(') STACK.push(s[i]);
		else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) res.push_back(s[i]);
		else if(s[i]==')')
		{
			while(STACK.empty()!=1 && STACK.top()!='(')
			{
				res.push_back(STACK.top());
				STACK.pop();
			}
			STACK.pop();
		}		
		else // Neu s[i] = + - * /
		{
			while(STACK.empty()!=1 && priority(s[i]) <= priority(STACK.top())) // Lay ra tat ca nhung cai co do uu tien >= s[i]
			{
				res.push_back(STACK.top());
				STACK.pop();
			}
			STACK.push(s[i]);
		}
	}
	while(STACK.empty()!=1)
	{
		if(STACK.top()!='(') res.push_back(STACK.top());
		STACK.pop();
	}
	cout<<res<<endl;
}

main()
{
	long long T;
	cin>>T;
	string s;
	while(T--)
	{
		cin>>s;
		process(s);
	}
}
//https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
