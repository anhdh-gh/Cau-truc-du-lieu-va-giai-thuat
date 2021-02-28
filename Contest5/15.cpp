#include<bits/stdc++.h>
using namespace std;
long long C[105][105][105];
long long qhd(string s1,string s2,string s3,long long m,long long n,long long p)
{
	for(long long i = 1 ; i <= m ; i++) 
		for(long long j = 1 ; j <= n ; j++)	
			for(long long k = 1 ; k <= p ; k++)
				if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1]) 
					C[i][j][k] = C[i-1][j-1][k-1] + 1;
			else			
				C[i][j][k] = max(max(C[i-1][j][k],C[i][j-1][k]),C[i][j][k-1]);
	return C[m][n][p];
}

main()
{
	long long T,m,n,p;
	cin>>T;
	string s1,s2,s3;
	while(T--)
	{
		cin>>m>>n>>p>>s1>>s2>>s3;
		cout<<qhd(s1,s2,s3,m,n,p)<<endl;
	}
}
//Guong bai 1 nhung dung mang 3 chieu
