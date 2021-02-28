#include<bits/stdc++.h>
using namespace std;

long long process(string a)
{
	string temp;
	long long sum = 0,n;
	for(long long i = 0 ; i < a.size() ; i++)
		for(long long j = 1 ; j <= a.size() ; j++)
		{
			temp = a.substr(i,j); // lay j ki tu tu vi tri i
			if(temp.size()==j)
			{
				// Convert sang so nguyen
				stringstream tempnum(temp);
				tempnum>>n;
				sum += n;	
			}
		}
	return sum;
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<process(a)<<endl;
	}
}
