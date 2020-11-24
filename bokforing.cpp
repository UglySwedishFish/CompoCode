#include <iostream>
#include <vector>

struct Action {
	int Slot, Amount; 
};


int main() {
	std::vector<Action> People; 
	Action Restart = { -1,0 };

	int N, Q; 
	std::cin >> N >> Q; 

	People = std::vector<Action>(N, Action{ -1,0 }); 

	for (int i = 0; i < Q; i++) {

		std::string Command; 
		std::cin >> Command; 
		if (Command == "SET") {
			int Person, Amount; 
			std::cin >> Person >> Amount; 
			People[Person - 1] = Action{ i, Amount }; 
		}
		if (Command == "RESTART") {
			int Amount; 
			std::cin >> Amount; 
			Restart = { i, Amount }; 
		}
		if (Command == "PRINT") {
			int Person; 

			std::cin >> Person; 

			if (People[Person - 1].Slot > Restart.Slot) {
				std::cout << People[Person - 1].Amount << '\n';
			}
			else {
				std::cout << Restart.Amount << '\n'; 
			}

		}

	}



}
