#include<bits/stdc++.h>
using namespace std;
long long tien[]={1,2,5,10,20,50,100,200,500,1000};

long long solve(long long n)
{
	long long dem = 0;
	for(long long i = 9 ; i >= 0 ; i--)
		if(n >= tien[i])
		{
			dem += n/tien[i];
			n %= tien[i];	
		}
	return dem;
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<solve(n)<<endl;
	}
}
