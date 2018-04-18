#include <iostream>
#include <cmath>

double relative_error(double x, double y)
{
  return abs(1 - x / y);
}

double a1(double x)
{
  return 1 / sqrt(x) - 1 / sqrt(x + 1);
}

double a2(double x)
{
  return 1 / (sqrt(x * (x + 1)) * (sqrt(x + 1) + sqrt(x)));
}

double b1(double x)
{
  return (1 - cos(x)) / sin(x);
}

double b2(double x)
{
  return tan(x / 2);
}

double c1(double x, double delta)
{
  return sin(x + delta) - sin(x);
}

double c2(double x, double delta)
{
  return -2 * sin(x) * pow(sin(delta / x), 2) + cos(x) * sin(delta);
}

int main()
{
  std::cout << relative_error(a1(1e25), a2(1e25))  << std::endl;
  std::cout << relative_error(b1(1e-25), b2(1e-25)) << std::endl;
  std::cout << relative_error(c1(1, 1e-25), c2(1, 1e-25)) << std::endl;
  return 0;
}
