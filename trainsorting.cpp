#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <set>
#include <sstream>
#pragma GCC optimize ("O3")
using namespace std;

int main() {

	vector<int> TrainWeights; 


	int N; 

	cin >> N; 
	TrainWeights.resize(N); 

	if (N == 0) {
		std::cout << "0\n";
		return 0; 
	}

	for (int i = 0; i < N; i++) {

		cin >> TrainWeights[i]; 

	}

	vector<int> SmallerV, LargerV; 
	LargerV.resize(N);
	SmallerV.resize(N);

	SmallerV[N - 1] = 0; //we know the last one can only be 1 long, because there are no trains ahead of it 
	LargerV[N - 1] = 0; //-||-

	for (int Inner = N - 2; Inner != -1; Inner--) {

		int InnerN = TrainWeights[Inner]; 

		int Smaller = 0, Larger = 0; //<- keep track of the smallest and largest longest train configurations. will be useful for later -> 

		for (int Outer = Inner + 1; Outer < N; Outer++) {

			int OuterN = TrainWeights[Outer]; 

			//iterate over, check if larger or smaller. 

			if (OuterN > InnerN) {

				//how long would this be config -> 

				int Length = 1 + LargerV[Outer]; 

				if (Length > Larger) {
					Larger = Length; 
				}

			}
			else {


				int Length = 1 + SmallerV[Outer];

				if (Length > Smaller) {
					Smaller = Length;
				}
			}




		}

		SmallerV[Inner] = Smaller; 
		LargerV[Inner] = Larger; 

	}

	int bestSorted = 1; 

	for (int x = 0; x < N; x++) {

		int bestLarger = 0; 
		int bestSmaller = 0; 

		for (int j = x; j < N; j++) {

			int Smaller = SmallerV[j]; 

			int Larger = LargerV[j]; 
			

			int totalLength = 1 + Larger + Smaller;

			if (totalLength > bestSorted)
				bestSorted = totalLength;

		}

	}


	std::cout << bestSorted << '\n'; 


}
