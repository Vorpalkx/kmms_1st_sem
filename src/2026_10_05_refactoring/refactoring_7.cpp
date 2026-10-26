#include <cmath>
#include <iostream>

float cacl_sequence(float x, float eps);

int main() {
	float eps;
	float x1, x2;
	float dx;
  std::cout << "Enter x1, x2, precision and step: (x1 x2 eps dx)" << std::endl;
  std::cin >> x1 >> x2 >> eps >> dx;
  x1 = (x1 < 0) ? 0 : x1;
  x2 = (x2 > 2) ? 2 : x2;

	int n = (x2 - x1) / dx;
	for (int i = 0; i <= n + 1; i++) {
	  std::cout
      << "F("
      << x1 + i * dx
      << ") = "
      << cacl_sequence(x1 + i * dx, eps)
      << std::endl;
  }

  std::cin.ignore();
  std::cout << "Нажмите любую клавишу для продолжения...";
  std::cin.get();

  return 0;
}

float cacl_sequence(float x, float eps) {
	int n = 0;
	float fx = 0;
	int op = 1;
  
  double seq_pow = pow(x - 1, n + 1);
  double seq_item_1 = (x * (n + 1) - 2 * n - 3);
  double seq_item_2 = (n * n + 3 * n + 1);
	while(abs(seq_pow * seq_item_1 / seq_item_2) > eps) {
		fx += op * pow(x - 1, n + 1) / (n + 1);
		op *= -1;
		n++;
    seq_pow = pow(x - 1, n + 1);
    seq_item_1 = (x * (n + 1) - 2 * n - 3);
    seq_item_2 = (n * n + 3 * n + 1);
	}
	return fx;
}

