#include<bits/stdc++.h>
using namespace std;

long long qhd(long long n)
{
	long long dp[10005]; // dp[i]: So luong it nhat cac so nho hon i co tong binh phuong = i
	//Co 1 mang luu tat ca so cac so cua cac cach. Sau do tim min cua mang do. => dp[i] = min(mang do)
	dp[0] = 0; // Khong co so nao
	dp[1] = 1; //1^2
	dp[2] = 2; //2^2 + 1^2
	dp[3] = 3; //2^2 + 2^2 + 1^2
	// Update array dp[]
	for(long long i = 4 ; i <= n ; i++) // Run de update mang dp[]
	{
		dp[i] = i; // i = 1^2 + 1^2 + .... (sum i lan 1^2)
		for(long long j = 1 ; j <= sqrt(i) ; j++) 
			dp[i] = min(dp[i],dp[i-j*j]+1);
			// dp[i-temp]+1 + 1: (+1) La so temp da duoc phan tich temp = j^2 + so cach phan tich so i-temp thanh tong binh phuong cac so nho hon so i-temp	
	}
	return dp[n];
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<qhd(n)<<endl;
	}
}
//Vd: 6 => sqrt(6) = 2
//i = 1: 6 = 1^2 + 5. Mà dp[5] = 2 => 2+1 = 3;
//i = 2: 6 = 2^2 + 2. Ma dp[2] = 2 =? 2+1 = 3

