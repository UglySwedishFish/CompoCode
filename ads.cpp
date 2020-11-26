#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <sstream>
using namespace std;


#define bigint long long 


vector<string> WebPage;

void CheckString(int X, int Y, int W, int H, int Depth) {

	bool Forbidden = false; 

	std::vector<bool> Checked = std::vector<bool>(H * W, false); 


	for (int x = X; x < W; x++) {
		for (int y = Y; y < H; y++) {
		
			if (Checked[x * H + y])
				continue; 

			auto c = WebPage[y][x]; 

			if (WebPage[y][x] == '+') {

				//find the size of the image -> 
				
				int EndCornerX, EndCornerY;

				for (EndCornerX = x; EndCornerX < W; EndCornerX++) {

					if (WebPage[y][EndCornerX] != '+')
						break; 

				}

				for (EndCornerY = y; EndCornerY < H; EndCornerY++) {

					if (WebPage[EndCornerY][x] != '+')
						break;

				}
			
				for (int _x = x; _x < EndCornerX; _x++) {
					for (int _y = y; _y < EndCornerY; _y++) {
						Checked[_x * H + _y] = true;
					}
				}


				//if(Depth != 1)
				CheckString(x + 1, y + 1, EndCornerX-1, EndCornerY-1, Depth+1);

			}
			else if (isalpha(c) or isdigit(c)) {}
			else if(c == '?' or c == '!' or c == ',' or c == '.' or c == ' ') {}
			else {
				Forbidden = true; 
			}

		
		
		}
	}

	if (Forbidden && Depth != 0) {

		for (int x = X-1; x < W+1; x++) {
			for (int y = Y-1; y < H+1; y++) {
				WebPage[y][x] = ' '; 
			}
		}


	}


}


int main() {

	
	
	std::string t; 
	std::getline(cin, t); 

	istringstream b(t); 


	int H = 7, W = 7; 
	b >> H >> W; 
	WebPage.resize(H); 
	for (int x = 0; x < H; x++) {
		std::getline(cin, WebPage[x]); 

		while (WebPage[x].size() != W)
			WebPage[x].push_back(' ');

	}

	CheckString(0, 0, W,H, 0); 

	for (int x = 0; x < H; x++) {
		cout << WebPage[x] << '\n'; 
	}
		

}
