#include<iostream>
using namespace std;
int main()
{
	long long T,a,count;
	cin>>T;
	for(long long j = 1 ; j <= T ; j++)
	{
		cin>>a;
		cout<<"Test "<<j<<":";
		for(long long i = 2 ; a!= 1 ; i++)
		{
			count = 0;
			while(a%i==0)
			{
				count++;
				a /= i;
			}
			if(count != 0) cout<<" "<<i<<"("<<count<<")";
		}
		cout<<endl;
	}
	return 0;
}
