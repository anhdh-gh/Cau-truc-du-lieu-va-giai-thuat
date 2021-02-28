#include<iostream>
using namespace std;

long long ucln(long long a,long long b)
{
	if(a%b==0) return b;
	else ucln(b,a%b);
}

int main()
{
	long long T,a,b;
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		cout<<ucln(a,b)<<" "<<(a*b)/ucln(a,b)<<endl;
	}
	return 0;
}
