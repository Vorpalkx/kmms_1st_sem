#include <cmath>
#include <iostream>

float func1(float x, float eps);

int main() {
	float eps;
	float x1, x2;
	float dx;

  std::cout << "Enter x1, x2, precision and step: (x1 x2 eps dx)" << std::endl;
  std::cin >> x1 >> x2 >> eps >> dx;

  x1 = (x1 < 0) ? 0 : x1;
  x2 = (x2 > 2) ? 2 : x2;

	int n = (x2 - x1) / dx;

	for (int ix = 0; ix <= n + 1; ix++) {
	  std::cout << "F(" << x1 + ix*dx << ") = " << func1(x1 + ix*dx, eps) << std::endl;
  }

  std::cin.ignore();
  std::cout << "Нажмите любую клавишу для продолжения...";
  std::cin.get();

  return 0;
}

float func1(float x, float eps) {
	int n = 0;
	float fx = 0;
	int op = 1;

	while( abs( pow(x-1, n+1) * (x * (n+1) - 2*n - 3) / (n*n + 3 * n + 1) ) > eps ) {
		fx += op * pow(x-1, n+1) / (n+1);
		op *= -1;
		n++;
	}
	return fx;
}

