#include<bits/stdc++.h>
using namespace std;
struct kitu{
	char c;
	long long sl;
};

bool comp(kitu a,kitu b){return a.sl > b.sl;}

long long dem(string a,char x)
{
	long long d = 0;
	for(long long i = 0 ; i < a.size() ; i++)
		if(x == a[i]) d++;
	return d;
}

long long d;
long long solve(kitu luu[],long long n,long long max,long long chuaxet[])
{
	for(long long i = 0 ; i < n ; i++)
	{
		long long vt = 0; // vi tri bat dau dat 
		while(chuaxet[vt]!=0) vt++;
		for(long long j = 0 ; j < luu[i].sl ; j++)
		{
			if(vt+j*d >= max) return -1;
			chuaxet[vt+j*d] = 1;
		}
	}
	return 1;
}

main()
{
	long long T;
	cin>>T;
	string a,b;
	while(T--)
	{
		cin>>d>>a;
		b = a;
		sort(b.begin(),b.end());
		for(long long i = 0 ; i < b.size()-1 ; i++)
			if(b[i]==b[i+1]) b.erase(b.begin()+i--);
		kitu luu[b.size()];
		for(long long i = 0 ; i < b.size() ; i++)
		{
			luu[i].c = b[i];
			luu[i].sl = dem(a,b[i]);
		}
		sort(luu,luu+b.size(),comp);
		// xu ly
		long long chuaxet[a.size()]={0};
		cout<<solve(luu,b.size(),a.size(),chuaxet)<<endl;
	}
}
