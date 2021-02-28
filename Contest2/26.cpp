#include<iostream>
using namespace std;

void TRY(string a,long long k,string &max)
{
	if(k == 0) return;
	for(long long i = 0 ; i < a.size()-1 ; i++)
		for(long long j = i+1 ; j < a.size() ; j++)
			if(a[j] > a[i])
			{
				swap(a[i],a[j]); 
				if(max < a) max = a;
				TRY(a,k-1,max);
				swap(a[i],a[j]); 			
			}
}

main()
{
	long long T,k;
	cin>>T;
	string a,max;
	while(T--)
	{
		cin>>k;
		cin>>a;
		max = a;
		TRY(a,k,max);
		cout<<max<<endl;
	}
}
