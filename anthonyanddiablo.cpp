#include <iostream>
#include <string>
using namespace std;


double pi = 3.14159265359; 
int main() {

	double A, N; 
	cin >> A >> N; 

	double radius = 0.5 * (N / pi);
	double Area = radius * radius * pi; 

	if (Area >= A) {
		std::cout << "Diablo is happy!\n"; 
	}
	else {
		std::cout << "Need more materials!\n"; 
	}

}
