#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool cmp(string a,string b)
{
	if(a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

void process(long long n)
{
	vector<string>res;
	queue<string>q;
	q.push("44");
	q.push("55");
	string a;
	while(res.size() < n)
	{
		a = q.front();
		q.pop();
		res.push_back(a);
		q.push("4"+a+"4");
		q.push("5"+a+"5");
	}	
	sort(res.begin(),res.end(),cmp);
	for(long long i = 0 ; i < res.size() ; i++)
		cout<<res[i]<<" ";
	cout<<endl;
}

main()
{
 	faster()
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		process(n);
	}
}
