#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;
main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n,k;
		cin>>n>>k;
		long long dp[n+1]={0};	// dp[i] la mang chua co the tao bao nhieu day so ( so <= k ) co sum = i;
		dp[0] = 1;				// dp[0] chi co the tao duoc 1 day 0 co tong = 0
		for(long long i = 1 ; i <= n ; i++)
		// Cong thuc truy hoi: 
		// Th1: i - k >= 0: dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k] // tong k so sau i
		// Th2: i < k: dp[i] = dp[i-1] + dp[i-2] + ... + dp[0]
			for(long long j = i-1 ; j >= 0 && j >= i-k ; j--)
				dp[i] = (dp[i]+dp[j])%m;
		cout<<dp[n]<<endl;
	}
}

//#include<bits/stdc++.h>
//using namespace std;
//long long m = 1e9+7;
//
//long long qhd(long long n,long long k)
//{
//	if(k >= n) // so cach 2^(n-1) => Day chinh la bai toan co bao nhieu cach phan tich n thanh tong cac so nho hon n
//	{
//		long long p = 1;
//		for(long long i = 1 ; i <= n-1 ; i++)
//			p = ((p%m)*(2%m))%m;
//		return p;
//	}
//	long long dp[n+1]={0};	// dp[i] la mang chua co the tao bao nhieu day so ( so < k ) co sum = i;
//	dp[0] = 1;
//	for(long long i = 1 ; i <= n ; i++)
//		for(long long j = i-1 ; j >= i-k && j >= 0 ; j--)
//			dp[i] = (dp[i]+dp[j])%m;
//	return dp[n];		
//}
//
//main()
//{
//	long long T;
//	cin>>T;
//	while(T--)
//	{
//		long long n,k;
//		cin>>n>>k;
//		cout<<qhd(n,k)<<endl;
//	}
//}
