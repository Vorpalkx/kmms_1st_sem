#include <iostream>
#include <cmath>
using namespace std;

float func1(float x, float eps)
{
	int n = 0;
	float fx = 0;
	int op = 1;
	while( abs( pow(x-1, n+1)*((x*(n+1)-2*n-3)/(n*n+3*n+1) )) > eps )
	{
		fx += op * pow(x-1, n+1)/(n+1);
		op *= -1;
		n++;
	}
	return fx;
}

main()
{
	float eps;
	float x1 , x2;
	float dx;
	cout << "Enter x1, x2, precision and step: (x1 x2 eps dx) ";
	cin >> x1 >> x2 >> eps >> dx;
	if (x1 < 0) x1 = 0;  if(x2 > 2) x2 = 2; 

	int n = (x2-x1)/dx;
	for(int ix = 0; ix <= n + 1; ix++)
		cout << "F(" << x1 + ix*dx << ") = " << func1(x1 + ix*dx, eps) << endl;
	system("PAUSE");

}