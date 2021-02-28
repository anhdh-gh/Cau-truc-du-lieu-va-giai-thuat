#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void nhap(string &a)
{
	char temp;
	for(int i = 0 ; i < 6 ; i++)
	{
		cin>>temp;
		a.push_back(temp);
	}	
}

string xoay_trai(string a)
{
	swap(a[0],a[1]);
	swap(a[0],a[3]);
	swap(a[3],a[4]);
	return a;
}

string xoay_phai(string a)
{
	swap(a[1],a[2]);
	swap(a[1],a[4]);
	swap(a[4],a[5]);
	return a;
}

main()
{
	
	string in,out;
	nhap(in);
	nhap(out);
	pair<string,long long>temp,x;
	temp.first = in;
	temp.second = 0;
	//			value	step
	queue<pair<string,long long> >q;
	q.push(temp);
	while(q.front().first != out)
	{
		temp = q.front();
		q.pop();
		x.second = temp.second+1;
		x.first = xoay_trai(temp.first);
		q.push(x);
		x.first = xoay_phai(temp.first);
		q.push(x);
	}
	cout<<q.front().second;
}
