#include <iostream>
#include <random>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <vector>
#include <math.h>

void unit_sphere()
{
  std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_real_distribution<> dist(0, 1);

  int points = 1e9;
  int acc = 0;

  for(int i = 0; i < points; i++)
  {
    if(i % 10000 == 0)
      std::cout << std::setprecision(2) << "\r" << (double) (i+1) * 100 / points << "%   ";
    acc += (pow(dist(rng), 2) + pow(dist(rng), 2) + pow(dist(rng), 2)) < 1;
  }


  double vol = (double) 8 * acc / points;
  double t_vol =  M_PI * 4 / 3;
  std::cout << std::setprecision(12) << "\runit sphere volume – MC: " << vol << " theory: " << t_vol << std::endl;
  std::cout << "pi – MC: " << vol * 3 / 4 << " theory: " << M_PI << std::endl;

}

int main()
{
  unit_sphere();
	return EXIT_SUCCESS;
}
