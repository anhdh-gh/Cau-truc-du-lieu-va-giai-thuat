#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,ps,qs,ress;
	cin>>T;
	while(T--)
	{
		cin>>ps>>qs;
		long long p[ps],q[qs];
		for(long long i = 0 ; i < ps ; i++)
			cin>>p[i];
		for(long long i = 0 ; i < qs ; i++)
			cin>>q[i];
		ress = (ps-1)+(qs-1)+1;
		long long res[ress][ress],k;
		for(long long i = 0 ; i < ress ; i++)
			for(long long j = 0 ; j < ress ; j++)
				res[i][j] = 0;
		for(long long i = 0 ; i < ps ; i++)
		{
			k = i;
			for(long long j = 0 ; j < qs ; j++)
				res[i][k++] = p[i]*q[j];
		}
		for(long long i = 0 ; i < ress ; i++)
		{
			long long temp = 0;
			for(long long j = 0 ; j < ress ; j++)
				temp += res[j][i];
			cout<<temp<<" ";
		}
		cout<<endl;
	}
}
