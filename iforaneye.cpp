#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include <set>
#include <sstream>
#pragma GCC optimize ("O3")
using namespace std;

map<char, vector<string>> Replacements; 



string ReplaceAt(string OriginalS, char C, int Index, int Length, bool UpperCase, string & A) {

    string S = ""; 
    string _A = ""; 

    for (int i = 0; i < OriginalS.size(); i++) {

        if (i == Index) {
            S += UpperCase ? toupper(C) : C;
            _A += "-";
        }
        else if (i > Index and i - Index < Length) {
            //do nothing
        }
        else {
            S += OriginalS[i]; 
            _A += A[i]; 
        }


    }

    A = _A; 


    return S; 

}

int GetLength(string S, string A,  int StartCharacter, char C) {

    for (int i = Replacements[C].size() - 1; i != -1; i--) {

        bool Ok = true; 

        string Test = Replacements[C][i]; 

        if (Test.size() + StartCharacter > S.size())
            continue;  //we go out of bounds! 

        for (int j = 0; j < Test.size(); j++) {

            if (Test[j] != tolower(S[j + StartCharacter]) || A[j+StartCharacter] !='.')
                Ok = false; 

        }

        if (Ok) {
            return Test.size(); 
        }


    }
    return -1; 

}


string Replace(string Word) {
    
    string Result = Word; 
    string Allowed; 
    for (int i = 0; i < Result.size(); i++)
        Allowed += '.'; 

    //iterate over every letter, check for 

    bool HasFound = true; 

    while (HasFound) {
        HasFound = false; 

        //check each character, then for said character keep track of the longest thing. Keep iterating until word reaches minimum. (ie cannot be compressed any further) 

        for (int i = 0; i < Result.size(); i++) {

            int Longest = -1; 
            char C = '-'; 

            for (auto& Case : Replacements) {
                int L = GetLength(Result, Allowed, i, Case.first);
                if (L > Longest) {
                    C = Case.first; 
                    Longest = L; 
                    HasFound = true; 
                }
            }

            if (HasFound) {
                Result = ReplaceAt(Result, C, i, Longest, isupper(Result[i]), Allowed);
                break; 
            }

        }




    }

    return Result; 
}

int main() {

    Replacements['@'] = { "at" }; 
    Replacements['&'] = { "and" }; 
    Replacements['1'] = { "one", "won" }; 
    Replacements['2'] = { "to", "too", "two" }; 
    Replacements['4'] = { "for", "four" }; 
    Replacements['b'] = { "be", "bea", "bee" }; 
    Replacements['c'] = { "sea", "see" };
    Replacements['i'] = { "eye" }; 
    Replacements['o'] = { "oh", "owe" }; 
    Replacements['r'] = { "are" }; 
    Replacements['u'] = { "you" }; 
    Replacements['y'] = { "why" }; 

    int Lines; 
    cin >> Lines; 

    for (int i = 0; i < Lines+1; i++) {
        string line; 
        getline(cin, line); 

        string S;
        istringstream parse(line); 
        while (parse >> S) {
            cout << Replace(S); 
            cout << ' ';
        }
        cout << '\n'; 
        
        

    }





}
