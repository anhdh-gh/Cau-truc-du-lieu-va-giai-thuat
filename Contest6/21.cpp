#include<bits/stdc++.h>
using namespace std;

struct so{
	long long value;
	long long solan;
};

bool cmp1(so a,so b){return a.value < b.value;}
bool cmp2(so a,so b)
{
	if(a.solan == b.solan) return a.value < b.value;
	else return a.solan > b.solan;
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		so a[n];
		for(long long i = 0 ; i < n ; i++)
		{
			cin>>a[i].value;
			a[i].solan = 1;
		}
		sort(a,a+n,cmp1);
		vector<so>b;
		b.insert(b.begin(),a,a+n);
		for(long long i = 0 ; i < b.size()-1 ; i++)
			if(b[i].value == b[i+1].value)
			{
				b[i].solan++;
				b.erase(b.begin()+1+i--);
			}
		sort(b.begin(),b.end(),cmp2);
		for(long long i = 0; i < b.size() ; i++)
			while(b[i].solan--)
				cout<<b[i].value<<" ";
		cout<<endl;
	}
}
