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

main()
{
	long long T;
	cin>>T;
	string a,b;
	while(T--)
	{
		cin>>a;
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
		// Dieu kien de cho 1 xau khong co cac ki tu dung canh nhau: 
		// So xuat hien nhieu nhat phai <= do dai a/2 (chan ) || <= do dai a/2 +1 ( le) 
		
		long long ss;
		if(a.size()%2==0) ss = a.size()/2; 
		else ss = a.size()/2+1;
		if(luu[0].sl > ss) cout<<-1;
		else cout<<1;
		cout<<endl;
	}
}
