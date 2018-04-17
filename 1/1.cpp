#include <iostream>
#include <random>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
#include <numeric>

double saw2d(int steps, std::mt19937& rng)
{
	std::uniform_int_distribution<> dist(0, 3);
	bool lattice[2 * steps + 1][2 * steps + 1];
	memset(lattice, false, sizeof(lattice));
	int x = steps - 1; int y = steps - 1;

	for(int i = 0; i < steps; i++)
	{
		int xnew, ynew;

		//terminate loop if no further steps are possible
		if(lattice[x+1][y] && lattice[x-1][y] && lattice[x][y+1] && lattice[x][y-1])
			break;

		//bad implementation, worst case time complexity is infinite
		//todo: remove impossible steps from random pool
		do
		{
			xnew = x;
			ynew = y;
			switch(dist(rng))
			{
				case 0:	xnew = x + 1; break;
				case 1:	xnew = x - 1; break;
				case 2:	ynew = y + 1; break;
				case 3:	ynew = y - 1; break;
			}
		}
		while(lattice[xnew][ynew]);

		x = xnew;
		y = ynew;
		lattice[x][y] = true;
	}
	//             (origin   )               (origin   )
	return pow(x - (steps - 1), 2) + pow(y - (steps - 1), 2);
}

int main()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	int size = 1e5;
	std::vector<int> output(size);
	std::ofstream f;
  f.open ("build/output.txt");
	for(int j = 10; j <= 60; j += 5)
	{
		std::cout << j << "... " << std::flush;
		for(int i = 0; i < size; i++)
			output[i] = saw2d(j, rng);
		f << j << " " << std::accumulate(output.begin(), output.end(), 0) / (double) size << std::endl;
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
