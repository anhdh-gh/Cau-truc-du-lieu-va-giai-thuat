#include <iostream>     
using namespace std;

void output(int a[],int n)
{
	for(int i = 0 ; i < n ; i++)
		for(int j = i+1 ; j < n ; j++)
			if(a[i] == a[j])
			{
				cout<<a[i]<<endl;
				return;
			}
	cout<<"NO\n";
}

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		output(a,n);	
	}
	return 0;
}
