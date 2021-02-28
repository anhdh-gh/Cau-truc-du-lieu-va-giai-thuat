#include<bits/stdc++.h>
using namespace std;
long long modulo = 1e9+7;
// So co n chu so: a0 a1 a2 a3 ... an
// 1 <= a0 <= 9
// 0 <= ai <= 9 va i thuoc [1,n]
long long F[105][50005];
//F[i][j]: Co bao nhieu so co co i chu so va co tong 
//cac chu so = j. 0 <= ai <= 9 

// Xet 0 <= ai <= 9 va i thuoc [1,9]
// Cap nhat mang trang thai
void qhd(long long n,long long k)
{
	// Base case
	for(long long i = 0 ; i <= n ; i++)
		F[i][0] = 1;// Chi co 1 chu so 0. F[0][0] = 1
	for(long long i = 1 ; i <= k ; i++)
		F[0][i] = 0; // Khong co so nao	
	// QHD
	for(long long i = 1 ; i <= n ; i++)
		for(long long j = 1 ; j <= k ; j++)
		{
			F[i][j] = 0;	
			for(long long m = 0 ; m <= 9 ; m++)
				if(j - m >= 0)
					F[i][j] = (F[i][j]+F[i-1][j-m])%modulo;			
		}
}

// Xet so dau tien a0
long long process(long long n,long long k)
{
	if(n == 0) return 0; 
	long long ans = 0;
	for(long long i = 1; i <= 9 ; i++)
		if(k - i >= 0)
			ans = (ans+F[n-1][k-i])%modulo;
	return ans;
}

main()
{
	qhd(100,50000);
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cout<<process(n,k)<<endl;
	}
}
