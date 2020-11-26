#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
using namespace std;


#define bigint long long 

//NOT A COMPLETE SOLUTION, ONLY YIELDS 41 POINTS!!!



int main() {


	std::vector<float> Ping[2]; 
	for (int i = 0; i < 2; i++)
		Ping[i] = std::vector<float>(2e7); 

	int P, T; 
	std::cin >> P >> T; 
	float L; 
	std::cin >> L; 

	int maxP = 0; 

	for (int x = 0; x < P; x++) {
		int index; 
		std::cin >> index; 
		Ping[0][100000+index] = 1.0; 

		//std::cout << "Set ping " << 1004 + index << " to: " << Ping[0][1004 + index] << '\n'; 

		maxP = std::max(maxP, index + 1); 
	}

	int K = 0; 

	for (int t = 0; t < T; t++) {
		K = 0; 
		for (int x = -10000; x < maxP + 10000; x++) {
		
			int _index = x + 100000;
			int ping = t % 2; 

			Ping[1-ping][_index] = Ping[ping][_index - 1] * 0.5 + Ping[ping][_index + 1] * 0.5; 

			if (Ping[!ping][_index] >= 1.0*L) {
				K++; 
			}

		}





	}


	std::cout << K << '\n'; 


}

