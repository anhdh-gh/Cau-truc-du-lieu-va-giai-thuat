#include<iostream>
#include <queue>
using namespace std;

int main()
{
	long long T,n,so;
	cin>>T;
	while(T--)
	{
		cin>>n;
		queue<long long>a;
		a.push(9);
		while(a.empty() != 1)
		{
			so = a.front();
			a.pop();
			if(so%n==0)
			{
				cout<<so<<endl;
				break;
			}
			a.push(so*10);
			a.push(so*10+9);
		}
	}
}
