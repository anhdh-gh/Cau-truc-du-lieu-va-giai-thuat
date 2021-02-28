#include<bits/stdc++.h>
using namespace std;

string Min(string s)
{
	for(long long i = 0 ; i < s.size() ; i++)
		if(s[i] == '6') s[i] = '5';
	return s;
}

string Max(string s)
{
	for(long long i = 0 ; i < s.size() ; i++)
		if(s[i] == '5') s[i] = '6';
	return s;
}

void cong(string a,string b)
{
	a = Min(a);
	b = Min(b);
	long long x = atoi(a.c_str());
	long long y = atoi(b.c_str());
	cout<<x+y<<" ";
	a = Max(a);
	b = Max(b);
	x = atoi(a.c_str());
	y = atoi(b.c_str());	
	cout<<x+y;
}

main()
{
	string a,b;
	cin>>a>>b;
	cong(a,b);
}

