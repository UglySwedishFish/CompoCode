#include <string>
#include <iostream>
#include <vector>
using namespace std; 

int BoardVisits[8][8] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
};

bool populate(int x, int y) {


    //vertical and horizontal 

    for (int lx = 0; lx < 8; lx++) {
        
        if ((BoardVisits[lx][y] > 0 && lx != x) || (BoardVisits[x][lx] != 0 && lx != y))
            return true; 


    }
    //Diagonal 1: 



    int dx = x, dy = y; 

    while (dx > -1 && dy > -1) {
        
        if (BoardVisits[dx][dy] > 0 && dx != x) {
            //std::cout << dx << ' ' << dy << '\n'; 
            return true;
        }
        
        dx--; 
        dy--; 

    }

    dx = x, dy = y;

    while (dx > -1 && dy < 8) {

        if (BoardVisits[dx][dy] > 0 && dx != x) {
        //  std::cout << dx << ' ' << dy << '\n';
            return true;
        }
        dx--;
        dy++;

    }
    return false; 

}



using namespace std; 

struct vec2 {
    int x, y; 
};

int main() {



    vector<vec2> Queens; 

    for (int y = 0; y < 8; y++) {
        string l; 
        cin >> l; 
        for (int x = 0; x < 8; x++) {
            if (l[x] == '*') {
                Queens.push_back(vec2{ x,y }); 
                BoardVisits[x][y]++; 
            }
        }
    }
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
        //  std::cout << BoardVisits[x][y]; 
        }
        //std::cout << '\n'; 
    }
    
    if(Queens.size() != 8) {
        std::cout << "invalid\n"; 
        return 0; 
    }
    
    for(auto queen : Queens)
        if (populate(queen.x, queen.y)) {
            //std::cout << queen.x <<' ' << queen.y << '\n'; 
            std::cout << "invalid\n"; 
            return 0; 
        }






    std::cout << "valid\n"; 
    
}
