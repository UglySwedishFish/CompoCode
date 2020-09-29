#include <iostream>
#include <math.h>

using bigint = long long; 

using namespace std; 

double NthRoot(bigint X, bigint  Power) {

    return pow(abs(X), 1.0 / Power); 
}

unsigned long long PowFast(bigint  X, bigint  Power) {
    bigint Base = 1;
    for (bigint i = 0; i < Power; i++)
        Base *= X; 
    return Base; 
}


int main() {

    while (true) {

        bigint N;
        std::cin >> N; 
        if (N == 0)
            break; 

        bigint  BaseRoot = 2;
        bigint  Square = 1;
        double Root = 1.0; 
        while ((Root = NthRoot(N, BaseRoot++)) > 1.99f) {

            bigint  RootInt = ((N > 0) * 2 - 1) * (bigint(Root));

            for (bigint  x = (RootInt - 1); x < RootInt + 2; x++) {
                if (PowFast(x, BaseRoot - 1) == N)
                    Square = BaseRoot - 1; 
            }

        }

        std::cout << Square << '\n'; 

    }



}
