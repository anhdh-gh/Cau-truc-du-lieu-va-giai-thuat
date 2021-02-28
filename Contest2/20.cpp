#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long> >b;
void sinh(vector<long long>a,long long n)
{
	if(n == 1) return;
	for(long long i = 0 ; i < n-1; i++)
		a[i] += a[i+1];
	a.pop_back();
	b.push_back(a);
	sinh(a,n-1);	
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<long long>a(n);
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		b.push_back(a);
		sinh(a,n);
		for(long long i = b.size()-1 ; i >= 0 ; i--)
		{
			cout<<"[";
			for(long long j = 0 ; j < b[i].size() ; j++)
			{
				if(j == b[i].size()-1) cout<<b[i][j]<<"] ";
				else cout<<b[i][j]<<" ";		
			}			
		}
		cout<<endl;
		b.clear();
	}
}
