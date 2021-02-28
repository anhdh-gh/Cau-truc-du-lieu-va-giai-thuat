#include<bits/stdc++.h>
using namespace std;
long long F[1005][1005];

long long qhd(string a)
{
	long long n = a.size(),i,j,k,kq=1;
	for(i = 0 ; i < n ; i++) F[i][i] = 1;
	for(k = 1 ; k < n ; k++)
	{
		for(i = 0 ; i < n-k ; i++)
		{
			j = i+k;
			if(a[i]==a[j] && k > 1)
				F[i][j] = F[i+1][j-1];
			else if(a[i]==a[j] && k==1)
				F[i][j] = 1;
			else F[i][j] = 0;
			if(F[i][j]) kq = max(kq,j-i+1);
		}
	}
	return kq;		
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<qhd(a)<<endl;
	}
}
// Xem lai cong thuc trong slide
