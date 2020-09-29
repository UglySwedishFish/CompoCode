#include <iostream>
#include <set>
#include <vector> 
#include <string>
#include <algorithm>
using namespace std; 

using bigint = signed long long; 
struct compare {
    inline bool operator()(const std::string& first,
        const std::string& second) const
    {
        return first.size() < second.size();
    }
};
int main() {
    
    int T = 0; 
    std::cin >> T; 
    compare c;

    for (int Case = 0; Case < T; Case++) {

        std::set<std::string> NumbersSet; 

        int Numbers; 

        std::cin >> Numbers; 

        bool Consistent = true; 

        auto Text = std::vector<std::string>(Numbers); 

        for (int Num = 0; Num < Numbers; Num++)
            std::cin >> Text[Num]; 
        std::sort(Text.begin(), Text.end(), c);
        for (int Num = 0; Num < Numbers; Num++) {



            std::string TextNum = Text[Num];

            std::string s = "";


            for (int i = 0; i < TextNum.size(); i++) {
                s += TextNum[i];
                
                
                if (NumbersSet.find(s) != NumbersSet.end())
                    Consistent = false; 


            }

            NumbersSet.insert(s); 

        }

        std::cout << (Consistent ? "YES\n" : "NO\n"); 
    }

}
