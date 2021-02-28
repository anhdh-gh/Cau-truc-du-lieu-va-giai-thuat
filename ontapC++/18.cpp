#include<iostream>
#include<algorithm>
using namespace std;

long long dem(string a,long long vi,long long vj)
{
	long long count = vj-vi+1;
		for(long long i = vi ; i < vj ; i++)
			for(long long j = i+1 ; j <= vj ; j++)
				if(a[i]==a[j]) 
				{
					count -=2;
					break;
				}
	return count;			
}

int main()
{
	string a;
	char b;
	cin>>a;
	for(long long i = 0 ; i < a.size() ; i++)
		if(a[i] == a[i+1])
		{
			b = a[i];
			a.erase(a.begin()+1+i--);
		}
		else if(a.find(b)!=-1)
		{
			a.erase(a.begin()+a.find(b));
			i--;
		}
	long long count = 0;
	for(long long i = 0 ; i < a.size()-1 ; i++)
		for(long long j = i+1 ; j < a.size() ; j++)
			if(a[i] == a[j])
				count += dem(a,i+1,j-1);
	cout<<count/2<<endl;
	return 0;
}
