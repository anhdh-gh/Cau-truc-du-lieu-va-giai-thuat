#include<bits/stdc++.h>
using namespace std;

long long ktnt(long long n)
{
	if(n == 2) return 1;
	if(n%2==0 || n < 2) return 0;
	for(long long i = 3 ; i <= sqrt(n) ; i+=2)
		if(n%i==0) return 0;
	return 1;
}

// Liet ke cac so nguyen to tu 1 -> 1e6
vector<long long>prime;
long long sinhnt()
{
	for(long long i = 2 ; i <= 1e6 ; i++)
		if(ktnt(i)==1) prime.push_back(i);
}

void process(long long n)
{
	for(long long i = 0 ; i < prime.size() ; i++)
		if(binary_search(prime.begin(),prime.end(),n-prime[i])==true)
		{
			cout<<prime[i]<<" "<<n-prime[i]<<endl;
			return;
		}
	cout<<-1<<endl;
}

main()
{
	sinhnt();
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		process(n);
	}
}
