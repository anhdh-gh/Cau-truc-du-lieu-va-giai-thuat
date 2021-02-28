#include<bits/stdc++.h>
using namespace std;
long long fb[100];

char tim(long long n,long long k)
{
	if(n==1) return 'A';	
	if(n==2) return 'B';
	if(k <= fb[n-2]) return tim(n-2,k); // Tim trong chuoi n-2
	return tim(n-1,k-fb[n-2]); // tim trong chuoi n-1
}

main()
{
	long long T,n,k;
	fb[1] = 1;fb[2] = 1;
	for(long long i = 3 ; i <= 92 ; i++) fb[i] = fb[i-2]+fb[i-1];
	cin>>T;	
	while(T--)
	{
		cin>>n>>k;
		cout<<tim(n,k)<<endl;
	}
}
