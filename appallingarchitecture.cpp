#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <set>
#pragma GCC optimize ("O3")
using namespace std;





int main() {

    double CenterX = 0.0; 
    int TotalDivisor = 0; 

    int H, W;

    cin >> H >> W; 

    string Bottom; 

    for (int y = 0; y < H; y++) {

        string s = ""; 
        cin >> s; 

        for (int x = 0; x < W; x++) {

            if (s[x] != '.') {
                CenterX += x; 
                TotalDivisor++; 
            }


        }
        if (y == H - 1)
            Bottom = s; 

    }

    CenterX /= double(TotalDivisor);

    int LeftMost = 0; 

    for (int i = 0; i < Bottom.size(); i++)
        if (Bottom[i] != '.') {
            LeftMost = i;
            break; 
        }


    int RightMost = 0;

    for (int i = Bottom.size()-1; i != -1; i--)
        if (Bottom[i] != '.') {
            RightMost = i;
            break; 
        }


    std::cerr << CenterX << ' ' << LeftMost << ' ' << RightMost << '\n'; 

    if (CenterX+.5 < LeftMost) {
        std::cout << "left\n"; 
    }
    else if (CenterX-.5 > RightMost) {
        std::cout << "right\n"; 
    }
    else {
        std::cout << "balanced\n"; 
    }

   
}
