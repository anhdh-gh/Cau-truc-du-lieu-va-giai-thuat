#include<iostream>
#include<algorithm>
using namespace std;

void xuly(string &a)
{
	long long i;
	for(i = a.size()-1 ; i > 0 ; i--)
		if(a[i] > a[i-1]) break;
	if(i != 0)
	{
		for(long long j = a.size()-1 ; j >= i ; j--)
			if(a[j] > a[i-1])
			{
				swap(a[i-1],a[j]);
				break;
			}
		sort(a.begin()+i,a.end());		
	}
	else a = "BIGGEST";
}

main()
{
	long long T,n;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>n>>a;
		xuly(a);
		cout<<n<<" "<<a<<endl;
	}
}
