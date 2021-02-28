#include<bits/stdc++.h>
using namespace std;
long long n,k;
vector<long long>Max;
long long xuly(long long l,long long h) // chia de tri
{
	long long mid = (l+h)/2;
	if(k==mid) return Max.back();
	if(k > mid) k = h-k;
	Max.pop_back();
	return xuly(l,mid-1);
}

main()
{
	long long T,dd;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		k--; // tinh tu vi tri 0
		dd = 1; 
		Max.push_back(1);
		for(long long i = 0 ; i < n-1 ; i++){dd=2*dd+1;Max.push_back(Max[i]+1);} // do dai dd sau khi lap n-1 lan;
		cout<<xuly(0,dd-1)<<endl;
		Max.clear();
	}
}
