#include <iostream>
#include <random>
#include <cstdlib>
#include <cstring>

double saw2d(int steps)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_real_distribution<> dist(0, 1);
	bool lattice[2 * steps + 1][2 * steps + 1];
	memset(lattice, false, sizeof(lattice));
	int x = steps - 1;
	int y = steps - 1;

	for(int i = 0; i < steps; i++)
	{
		int xnew;
		int ynew;
		
		//terminate loop if no further steps are possible		
		if(lattice[x+1][y] && lattice[x-1][y] && lattice[x][y+1] && lattice[x][y-1])
			break;

		//bad implementation, worst case time complexity is infinite
		//todo: remove impossible steps from random pool
		do
		{
			xnew = x;
			ynew = y;
			double rand = dist(rng);
			if(rand < 0.25)
				xnew = x + 1;
			if(rand > 0.25 && rand < 0.5)
				xnew = x - 1;
			if(rand > 0.5 && rand < 0.75)
				ynew = y + 1;
			if(rand > 0.75)
				ynew = y - 1;
		}
		while(lattice[xnew][ynew]);

		x = xnew;
		y = ynew;
		lattice[x][y] = true;
	}

	//             (origin )               (origin )
	return pow(x - (steps-1), 2) + pow(y - (steps-1), 2);
}

int main()
{
	//todo: implement different step counts etc
	for(int i = 0; i < 100; i++)
		std::cout << saw2d(60) << std::endl;
	return EXIT_SUCCESS;
}
