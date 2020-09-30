#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <map> 
#include <string>

using namespace std;

#define bigint long long

bigint SmallestDivisor(bigint X) {

    for (bigint x = 2; x <= (sqrt(X) + 10); x++) {
        if (X % x == 0)
            return x;
    }
    return 1;
}

int main() {

    bigint Num; 
    cin >> Num; 

    int totDiv = 0; 

    while (Num > 1) {
        auto Divisor = SmallestDivisor(Num); 
        
        Num /= Divisor; 
        
        totDiv++; 
        if (Divisor == 1)
            break;
    }

    cout << totDiv << '\n'; 


}
