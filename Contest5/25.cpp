#include<bits/stdc++.h>
using namespace std;
// Idea: la day tribonacci
// Cong thuc:
// T(0) = 1 , T(1) = 1, T(2) = 2 
// T(i) = T(i-1) + T(i-2) + T(i-3)
long long Tri[55];
void Tribinacci()
{
	Tri[0]=1;Tri[1]=1;Tri[2]=2;
	for(long long i = 3 ; i <= 50 ; i++)
		Tri[i] = Tri[i-1]+Tri[i-2]+Tri[i-3];
}

main()
{
	long long T,n;
	cin>>T;
	Tribinacci();
	while(T--)
	{
		cin>>n; // So dinh con ech co the nhay toi
		cout<<Tri[n]<<endl;	
	}
}

//Cach khac: Tuong tu bai 7 nhung mac dinh k = 3
//#include<bits/stdc++.h>
//using namespace std;
////long long m = 1e9+7;
//long long k = 3;
//main()
//{
//	long long T;
//	cin>>T;
//	while(T--)
//	{
//		long long n;
//		cin>>n;
//		long long dp[n+1]={0};
//		dp[0] = 1;
//		for(long long i = 1 ; i <= n ; i++)
//			for(long long j = i-1 ; j >= 0 && j >= i-k ; j--)
//				dp[i] = (dp[i]+dp[j]);
//		cout<<dp[n]<<endl;
//	}
//}
