#include<iostream>
using namespace std;

struct hcn
{
	long long dai;
	long long rong;
};

hcn a[3];

long long kt()
{
	// TH1: 3 hcn chong nhau
	if(a[0].dai==a[1].dai && a[1].dai==a[2].dai && a[0].dai==a[0].rong+a[1].rong+a[2].rong) return 1;
	// TH2: 3 hcn ghep vao nhau
	else
	{
		if(a[0].rong + a[1].dai == a[0].dai)
		{
			if(a[1].rong+a[2].rong==a[0].dai && a[2].dai == a[1].dai) return 1;
			else if(a[1].rong+a[2].dai==a[0].dai && a[1].dai == a[2].rong) return 1;
		}
		else if(a[0].rong + a[1].rong == a[0].dai)
		{
			if(a[1].rong == a[2].rong && a[1].dai + a[2].dai == a[0].dai) return 1;
			else if(a[1].rong == a[2].dai && a[1].dai+a[2].rong==a[0].dai) return 1;	
		}
	}
	// TH3: Khong ghep duoc
	return 0;
}

int main()
{
	//input
	for(long long i = 0 ; i < 3 ; i++)
		cin>>a[i].dai>>a[i].rong;
	// output
	// sap xep cac canh (dai rong)
	for(long long i = 0 ; i < 3 ; i++)
		if(a[i].dai < a[i].rong)
			swap(a[i].dai,a[i].rong);
	// sap xep dai tu lon den nho
	for(long long i = 0 ; i < 2 ; i++)
		for(long long j = i+1 ; j < 3 ; j++)
			if(a[j].dai > a[i].dai)
				swap(a[j],a[i]);
	
	if(kt()==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
