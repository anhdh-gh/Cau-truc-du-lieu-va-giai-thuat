#include<iostream>
#include<math.h>
using namespace std;
long long dem(long long n)
{
	long long count = 0;
	if(n%2!=0) return 0;
	else count = 1;
	for(long long i = 2 ; i <=sqrt(n) ; i++)
		if(n%i==0)
			if(n/i==i) count++;
			else 
			{
				if((n/i)%2==0 && i%2==0) count+=2;
				else if((n/i)%2==0 || i%2==0) count++;
			}
	return count;
}

int main()
{
	long long T,n,count;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<dem(n)<<endl;
	}
	return 0;
}
