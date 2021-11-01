#include <iostream> 
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std; 


enum EventType {OPEN, CLOSE};

struct Event {
    EventType Type; 
    int Position;
    int Min, Max;
};

vector<Event> Axis[2]; 

int Get(int Position, vector<Event> & Axis) {
    
    int Bracket = 0; 

    int Length = 0; 
    int PrevPosition = 0; 

    for (auto& Event : Axis) {

        if (Position >= Event.Min and Position <= Event.Max) {

            if (Event.Type == OPEN) {

                if (Bracket == 0) {
                    PrevPosition = Event.Position; 
                }

                Bracket++;
                
            }
            else {
                Bracket--;



                Length += Event.Position - PrevPosition;
                PrevPosition = Event.Position;
            }
        }

    }

    return Length; 

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int Count = 0;

    cin >> Count; 

    for (int i = 0; i < Count; i++) {

        double xMin, yMin, xMax, yMax; 

        cin >> xMin >> yMin >> xMax >> yMax; 

        int xMinI = (xMin * 100.0) + .5; 
        int xMaxI = (xMax * 100.0) + .5;
        int yMinI = (yMin * 100.0) + .5;
        int yMaxI = (yMax * 100.0) + .5;

        Event a; 

        a.Position = xMinI * 10;
        a.Min = yMinI * 10;
        a.Max = yMaxI * 10;
        a.Type = OPEN; 
        
        Axis[0].push_back(a); 
        
        a.Position = xMaxI * 10;
        a.Min = yMinI * 10;
        a.Max = yMaxI * 10;
        a.Type = CLOSE;

        Axis[0].push_back(a);

        a.Position = yMinI * 10;
        a.Min = xMinI * 10;
        a.Max = xMaxI * 10;
        a.Type = OPEN;

        Axis[1].push_back(a);

        a.Position = yMaxI * 10;
        a.Min = xMinI * 10;
        a.Max = xMaxI * 10;
        a.Type = CLOSE;

        Axis[1].push_back(a);

    }


    for (int i = 0; i < 2; i++)
        sort(Axis[i].begin(), Axis[i].end(), [](const Event& a, const Event& b) {
        if (a.Position == b.Position)
        {
            return a.Type < b.Type;
        }
        return a.Position < b.Position;
            }
    );


    

    int Bracket = 0;

    int Length = 0;
    int PrevPosition = 0;
    int PreviousLength = 0; 

    long long TotalArea = 0; 

    for (auto& Event : Axis[0]) {

        //Are we opening or closing? :O 

        if (Bracket != 0) {
            TotalArea += (long long)PreviousLength * (long long)(Event.Position - PrevPosition);
        }

        if (Event.Type == CLOSE) {
            Bracket--;  
        }
        else {
            Bracket++; 
        }
        PrevPosition = Event.Position;
        PreviousLength = Get(Event.Position + 1, Axis[1]);
    }


    TotalArea /= 100;
    auto SuperRemainder = TotalArea % 100; 

    auto Remainder = (TotalArea / 100) % 100; 

    if (SuperRemainder > 49)
        Remainder++; 

    if (Remainder == 100) {
        TotalArea += 10000;
        Remainder = 0; 
    }

    cout << (TotalArea / 10000) << (Remainder < 10 ? ".0" : ".") << Remainder << '\n';
    
}
