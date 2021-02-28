#include<bits/stdc++.h>
using namespace std;
string a;
// Neu so dau + va - = so ngaoc ( => No
// Else => Yes
//void process()
//{
//	getline(cin,a);
//	long long count1=0,count2=0;
//	for(long long i = 0 ; i < a.size() ; i++)
//	{
//		if(a[i]=='(') count1++;
//		if(a[i]=='+' || a[i]=='-') count2++;
//	}
//	if(count1 == count2) cout<<"No"<<endl;
//	else cout<<"Yes"<<endl;
//}
//
//main()
//{
//	long long T;
//	cin>>T;
//	cin.ignore();
//	while(T--)
//	{
//		process();
//	}
//}

stack<char>s;
bool process()
{
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i]!=')')
			s.push(a[i]);
		else if(s.empty()!=1)
		{
			long long dchar = 0;
			while(s.top()!='(')
			{
				s.pop();
				dchar++;
			}
			s.pop();
			if(dchar <= 1) return true;
		}
	while(s.empty()!=1) s.pop();
	return false;
}

main()
{
	long long T;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		getline(cin,a);
		if(process()==false) cout<<"No";
		else cout<<"Yes";
		cout<<endl;
	}
}
