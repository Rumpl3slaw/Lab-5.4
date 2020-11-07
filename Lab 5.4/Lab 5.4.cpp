#include <iostream>
#include <cmath>

using namespace std;

double D0(const int k, const int N)
{
	double D = 1;
	for (int i = k;i <= N;i++)
		D *= (pow(sin(i) * 1., 2) + pow(cos(1. / i) * 1.0, 2)) / pow(i * 1., 2);
	return D;
}
double D1(const int k,const int N , const int i ) 
{
	if (i > N)
		return 1;
	else
		return ((pow(sin(i) * 1., 2) + pow(cos(1. / i) * 1., 2)) / pow(i * 1., 2))*D1(k,N,i+1);
}
double D2(const int k,const int N , const int i )
{
	if (i < k)
		return 1;
	else
		return ((pow(sin(i) * 1., 2) + pow(cos(1. / i) * 1., 2)) / pow(i * 1., 2))*D2(k,N, i - 1);
}
double D3(const int k, const int N , const int  i, double t)
{
	t = t * (pow(sin(i) * 1., 2) + pow(cos(1. / i) * 1., 2)) / pow(i * 1., 2);
	if (i >= N)
		return t;
	else
		return D3(k,N, i + 1,t);
}
double D4(const int k,const int N , const int i,double t)
{
	t = t * (pow(sin(i) * 1., 2) + pow(cos(1. / i) * 1., 2)) / pow(i * 1., 2);
	if (i <= k)
		return t;
	else
		return D4(k,N, i - 1,t);
}
int main()
{
	int N = 15;
	int k = 1;
	int i = k;
	cout << "(iter)        D0 = " << D0(k,N) << endl;
	cout << "(rec up ++)   D1 = " << D1(k,N,k) << endl;
	cout << "(rec up --)   D2 = " << D2(k,N,N) << endl;
	cout << "(rec down ++) D3 = " << D3(k,N,k,1) << endl;
	cout << "(rec down --) D4 = " << D4(k,N,N,1) << endl;
	return 0;
}