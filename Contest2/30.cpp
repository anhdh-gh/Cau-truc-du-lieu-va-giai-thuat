#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long ktnt(long long n)
{
	if(n < 2) return 0;
	for(long long i = 2 ; i <= sqrt(n) ; i++)
		if(n%i==0) return 0;
	return 1;
}

vector<long long>prime,temp;
void sinhnt(long long p,long long s)
{
	for(long long i = p ; i <= s ; i++)
		if(ktnt(i) == 1)
			prime.push_back(i);
}

vector<vector<long long> >luu;
void TRY(long long n,long long p,long long s,long long i,long long sum)
{
	temp.push_back(prime[i]);
	sum += prime[i];
	if(sum == s && temp.size() == n) luu.push_back(temp);
	if(sum > s || temp.size() > n) return;
	else 
		for(long long j = i+1 ; j < prime.size() ; j++)
		{
			TRY(n,p,s,j,sum);
			temp.pop_back();
		}
}

main()
{
	long long T,n,p,s,sum;
	cin>>T;
	while(T--)
	{
		cin>>n>>p>>s;
		prime.clear();
		luu.clear();
		sinhnt(p,s);
		for(long long i = 0 ; i < prime.size() ; i++)
		{
			sum = 0;
			temp.clear();
			TRY(n,p,s,i,sum);
		}
		cout<<luu.size()<<endl;
		for(long long i = 0 ; i < luu.size() ; i++)
		{
			for(long long j = 0 ; j < luu[i].size() ; j++)
				cout<<luu[i][j]<<" ";	
			cout<<endl;		
		}
	}
}
