#include <iostream>
#include <set>
#include <vector> 
using namespace std; 

using bigint = signed long long; 

int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);  
    std::vector<bool> Flag(1000000000, false); 

    while (true) {

        int N, M;

        std::cin >> N >> M;

        if (N == 0 && M == 0)
            break; 

        for (int i = 0; i < N; i++) {
            int item;
            std::cin >> item;
            Flag[item] = true; 
        }

        bigint Total = 0;

        for (int i = 0; i < M; i++) {
            int item;
            std::cin >> item;

            if (Flag[item]) {
                Total++;
                Flag[item] = false; 
            }

        }
        std::cout << Total << '\n';
        
    }


}
