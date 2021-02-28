#include<iostream>
using namespace std;

string xuly(string a)
{
	string b;
	b.push_back(a[0]);
	for(long long i = 1 ; i < a.size() ; i++)
		if(a[i] == b[i-1]) b.push_back('0');
		else b.push_back('1');
	return b;
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<xuly(a)<<endl;
	}
}
// covert gray -> binary
//bi[0] = gr[0];
//b[i+1] = b[i] xor gr[i+1] ( i thuoc tu 0 den n);
//
//quy tac xor : giong nhau thi = 0 ; khac nhau = 1
