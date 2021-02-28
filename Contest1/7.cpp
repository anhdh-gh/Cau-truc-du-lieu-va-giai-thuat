#include<iostream>
#include <vector>
using namespace std;

void in(vector<long long>a)
{
	cout<<"(";
	for(long long i = 0 ; i < a.size() ; i++)
		if(i == a.size()-1) cout<<a[i];
		else cout<<a[i]<<" ";
	cout<<") "; 
}


long long stop;
void sinh(vector<long long>&a)
{
	stop = 0;
	long long i,D = 0,thuong,du;
	for(i = a.size()-1 ; i >= 0 ; i--)
		if(a[i] > 1)
		{
			stop = 1;
			a[i] -= 1;
			D++;
			thuong = D/a[i];
			du = D%a[i];
			if(i < a.size()-1) a.erase(a.begin()+i+1,a.end());
			for(long long j = 0 ; j < thuong ; j++)
				a.push_back(a[i]);
			if(du > 0) a.push_back(du);					
			break;
		}
		else D++;	
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		// input
		cin>>n;
		vector<long long>a;
		a.push_back(n);
		in(a);
		// output
		sinh(a);
		while(stop == 1)
		{
			in(a);
			sinh(a);
		}
		cout<<endl;	
	}
}
