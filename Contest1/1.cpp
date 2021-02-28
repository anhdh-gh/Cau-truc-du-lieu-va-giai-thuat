#include<iostream>
using namespace std;

void xuly(string &a)
{
	long long i;
	for(i = a.size()-1 ; i >= 0 ; i--)
		if(a[i] == '1') a[i] = '0';
		else break;
	if(i >= 0) a[i] = '1';	
}

main()
{
	long long T,i;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		xuly(a);
		cout<<a<<endl;
	}
}
