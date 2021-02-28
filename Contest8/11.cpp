#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Liet ke all so nguyen to [1000,9999]
long long prime[10005],step[10005],temp,ts[10],sm,tmp;
long long nt(long long n)
{
	if(n%2==0) return 0;
	for(long long i = 3 ; i <= sqrt(n) ; i+=2)
		if(n%i==0) return 0;
	return 1;
}

void init()
{
	for(long long i = 1000 ; i <= 9999 ; i++)
		if(nt(i)==1)
			prime[i] = 1; 
}

// Tach so
void tach(long long n,long long a[])
{
	a[0] = n%10; // Lay so hang don vi
	a[1] = (n/10)%10; // Lay so hang chuc
	a[2] = (n/100)%10; // Lay chu so hang tram
	a[3] = n/1000; // Lay chu so hang nghin
}

long long process(long long s,long long t)
{
	memset(step,-1,sizeof(step));
	queue<long long>q;
	q.push(s);
	step[s] = 0;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp == t) return step[t];
		tach(temp,ts);
		for(long long i = 0 ; i < 4 ; i++)
		{
			tmp = temp-ts[i]*pow(10,i);
			for(long long j = 0 ; j <= 9 ; j++)
			{
				sm = tmp + j*pow(10,i);
				if(prime[sm]==1 && sm > 1000 && step[sm] == -1)
				{
					step[sm] = step[temp]+1;
					q.push(sm);	
				}	
			}
		}
	}
}

main()
{
 	faster()
	long long T,s,t;
	cin>>T;
	init();
	while(T--)
	{
		cin>>s>>t;
    	cout<<process(s,t)<<endl;
	}
}
