#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <set>
#pragma GCC optimize ("O3")
using namespace std;

int flip[] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };

int GenerateInversion(int a) {
    int ret = 0;
    while (a > 0) {
        int d = a % 10;
        if (flip[d] == -1)
            return -1;
        ret = flip[d] + ret * 10;
        a /= 10;
    }
    return ret;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    unordered_map<int, vector<int>> Locations; 

    int Sum, Cards; 

    cin >> Cards >> Sum; 

    vector<int> AllCards; 

    for (int i = 0; i < Cards; i++) {
        int card; 
        cin >> card; 
        AllCards.push_back(card);

        if (Locations.find(card) == Locations.end()) {
            Locations[card] = vector<int>(); 
            Locations[card].push_back(i); 
        }

        int cardInverted = GenerateInversion(card); 

        if (cardInverted == card)
            continue; 

        if (Locations.find(cardInverted) == Locations.end()) {
            Locations[cardInverted] = vector<int>();
            Locations[cardInverted].push_back(i);
        }


    }
    
    for (int i = 0; i < Cards; i++) {

        int card = AllCards[i];

        //What are we looking for? 

        int Remainder = Sum - card; 

        if (Remainder >= 0) {

            if (Locations.find(Remainder) != Locations.end()) {

                for(auto x : Locations[Remainder])
                    if (x != i) {
                        cout << "YES"; 
                        return 0; 
                    }


            }

        }

        Remainder = Sum - GenerateInversion(card);

        if (Remainder >= 0) {

            if (Locations.find(Remainder) != Locations.end()) {

                for (auto x : Locations[Remainder])
                    if (x != i) {
                        cout << "YES";
                        return 0    ;
                    }


            }

        }

    }


    cout << "NO"; 
    

}
