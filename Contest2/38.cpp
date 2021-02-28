#include<bits/stdc++.h>
using namespace std;
unsigned long long p[]={2,3,5,7,11,13,17,19,23,29,31},k;

void tinh(vector<long long>&luu,unsigned long long &k)
{
	unsigned long long temp = 1;
	sort(luu.begin(),luu.end(),greater<long long>());
	for(long long i = 0 ; i < luu.size() ; i++)
		temp *= pow(p[i],luu[i]-1);	
	if(temp < k && temp !=0) k = temp;	
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n,i=2;
		cin>>n;
		if(n == 1) cout<<1<<endl;
		else if(n == 0) cout<<0<<endl;
		else
		{
			vector<long long>luu;
			while(n!=1)
				if(n%i==0) 
				{
					luu.push_back(i);	
					n /= i;	
				}
				else i++;	
			k = 1e18;
			while(luu.empty()==0)
			{
				tinh(luu,k);
				if(luu.size()>=2) luu[luu.size()-2] *= luu[luu.size()-1];
				luu.pop_back();
			}
			cout<<k<<endl;				
		}
	}
}
