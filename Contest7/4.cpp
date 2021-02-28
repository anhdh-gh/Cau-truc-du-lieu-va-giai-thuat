#include<bits/stdc++.h>
using namespace std;
string a;
stack<char>s;
char dao(char b)
{
	if(b==')') return '(';
	if(b=='}') return '{';
	if(b==']') return '[';
}

bool process()
{
	if(a.empty()==1) return true;
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i]=='[' || a[i]=='(' || a[i]=='{')
			s.push(a[i]);
		else
		{
			if(dao(a[i]) != s.top()) return false;
			else if(s.empty()!=1) s.pop();
		} 
	return true;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>a;
		if(process()==true) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
