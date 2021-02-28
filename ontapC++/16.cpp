#include<iostream>
using namespace std;

void doc(string a)
{
	long long sum = 0;
	for(long long i = 0 ; i < a.size();)
	{
		if(a[i] == 'V')
		{
			sum += 5;
			i++;
		}
		else if(a[i] == 'L') 
		{
			sum += 50;
			i++;
		}
		else if(a[i] == 'D') 
		{
			sum += 500; 
			i++;
		}
		else if(a[i] == 'M')
		{
			sum += 1000;
			i++;
		}
		else if(a[i] == 'I')
		{
			if(a[i+1]=='V') 
			{
				sum += 4;
				i+=2;
			}
			else if(a[i+1]=='X')
			{
				sum += 9;
				i+=2;
			}
			else 
			{
				sum += 1;
				i++;
			}
		}
		else if(a[i] == 'X')
		{
			if(a[i+1]=='L') 
			{
				sum += 40;
				i+=2;
			}
			else if(a[i+1]=='C')
			{
				sum += 90;
				i+=2;
			}
			else 
			{
				sum += 10;
				i++;
			}			
		}
		else if(a[i] == 'C')
		{
			if(a[i+1]=='D') 
			{
				sum += 400;
				i+=2;
			}
			else if(a[i+1]=='M')
			{
				sum += 900;
				i+=2;
			}
			else 
			{
				sum += 100;
				i++;
			}			
		}					
	}
	cout<<sum<<endl;
}

int main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		doc(a);
	}
	return 0;
}
