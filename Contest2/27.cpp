#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,k,a[100],tong,okin;
vector<long long>luu;

void in()
{
	okin++;
//	for(long long i = 0 ; i < luu.size() ; i++)
//		cout<<luu[i]<<" ";
//	cout<<endl;
}

void TRY(long long sum,long long i)
{
	luu.push_back(a[i]);
	sum += a[i];
	if(sum > tong) return;
	if(sum == tong) in();
	else
		for(long long j = i+1 ; j <= n ; j++)
		{
			TRY(sum,j);
			luu.pop_back();
		}	
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		tong = 0;
		for(long long i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			tong += a[i];
		}
		if(tong%k!=0) cout<<0;
		else
		{
			sort(a+1,a+n+1);
			tong /= k;
			okin = 0;
			for(long long i = 1 ; i <= n ; i++)
			{
				luu.clear();
				TRY(0,i);
			}	
			if(okin >= k) cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}
