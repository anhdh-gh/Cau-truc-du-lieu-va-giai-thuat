#include<iostream>
#include<algorithm>
using namespace std;

long long kt(long long a[],long long b[],long long n)
{
	for(long long i = 0 ; i < n ; i++)
		if(a[i] > b[i]) return 0;
	return 1; 	
}

int main()
{
	long long n;
	cin>>n;
	long long a[n],b[n];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	for(long long i = 0 ; i < n ; i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	if(kt(a,b,n)==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
