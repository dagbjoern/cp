#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>

int main(int argc, char *argv[])
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_real_distribution<> dist(0, 1);

	if(argc != 2)
	{
		std::cout << "Sample-Anzahl als Parameter angeben." << std::endl;
		return EXIT_FAILURE;
	}

	int n = atoi(argv[1]);
	int counter = 0;
	for(int i = 0; i < n; i++)
	{
		double x = dist(rng);
		double y = dist(rng);
		counter += (pow(x, 2) + pow(y, 2)) < 1;
	}

	std::cout << std::fixed << std::setprecision(10) << (double) counter / n * 4 << std::endl;

	return EXIT_SUCCESS;
}
