#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		string a ="",temp;
		for(long long i = 0 ; i < n ; i++)
		{
			cin>>temp;
			a += temp;
		}
		sort(a.begin(),a.end());
		// Xoa phan tu giong nhau
		for(long long i = 0 ; i < a.size()-1 ; i++)
			if(a[i] == a[i+1]) 
				a.erase(a.begin()+i--);
		// in
		for(long long i = 0 ; i < a.size() ; i++)
			cout<<a[i]<<" ";
		cout<<endl;		
	}
}
