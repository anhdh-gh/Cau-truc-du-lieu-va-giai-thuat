#include<bits/stdc++.h>
using namespace std;
// Ap dung cong thuc
// C(0,n) = C(n,n) = 1
// C(k,n) = C(k,n-1) = C(k-1,n-1)
// Idea: Tao 1 ma tran gom co n hang va k cot. Sau do dien cac gia tri vao ma tran theo cong thuc.
long long N,K;
long long C[1005][1005];
long long m = 1e9+7;

void qhd()
{
	for(long long n = 0 ; n <= N ; n++) // chay hang
		for(long long k = 0 ; k <= n && k <= K; k++) // chay cot && k <= n && k <= K
			if(k == 0 || k == n)
				C[n][k] = 1;
			else C[n][k] = (C[n-1][k] + C[n-1][k-1])%m;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		qhd();
		cout<<C[N][K]<<endl;
	}
}
