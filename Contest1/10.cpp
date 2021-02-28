#include<iostream>
using namespace std;

string xuly(string a)
{
	string b;
	b.push_back(a[0]);
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i] == a[i+1]) b.push_back('0');
		else b.push_back('1');
	return b;	
}
 
main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<xuly(a)<<endl;
	}
}
// cach chuyen binary -> gray
//consider a 6 bit binary code 110110
//
//- first bit form left side of gray code will be the first bit from left side of
//   binary code i.e 1.
//- for second bit of gray code, find XOR operation on first and second bit of 
//  binary code i.e. 1 XOR 1 = 0
//- For third bit of gray code, find XOR operation on second and third bit of 
//  binary code i.e. 1 XOR 0 = 1
//- For forth bit of gray code, find XOR operation on third and forth bit of 
//  binary code i.e. 0 XOR 1 = 1
//- For fifth bit of gray code, find XOR operation on forth and fifth bit of 
//  binary code i.e. 1 XOR 1 = 0
//- For sixth bit of gray code, find XOR operation on fifth and sizth bit of 
//  binary code i.e. 1 XOR 0 = 1
//
//Therefore, the gray code of given binary code is 101101
