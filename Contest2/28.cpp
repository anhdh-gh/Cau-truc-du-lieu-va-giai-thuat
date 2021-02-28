#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long>luu;
long long ok;
void in(vector<long long>&a)
{
	ok = 1;
	cout<<"[";
	for(long long i = 0 ; i < a.size()-1 ; i++)
		cout<<a[i]<<" ";
	cout<<a[a.size()-1]<<"] ";
}

void TRY(vector<long long>a,long long x,long long i,long long s)
{
	luu.push_back(a[i]);
	s += a[i];
	if(s > x) return;
	if(s == x) in(luu);
	else 
		for(long long j = i ; j < a.size() ; j++)
		{
			TRY(a,x,j,s);
			luu.pop_back();
		}
}

main()
{
	long long T,n,x,s;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		vector<long long>a(n);
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		for(long long i = 0; i < a.size()-1 ; i++)
			if(a[i] == a[i+1])
				a.erase(a.begin()+i--);
		ok = 0;
		for(long long i = 0; i < a.size() ; i++)
		{
			s = 0;
			luu.clear();
			TRY(a,x,i,s);
		}
		if(ok == 0) cout<<-1;
		cout<<endl;
	}
}
