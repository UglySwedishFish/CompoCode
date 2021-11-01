#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;



int main() {

    map<string, int> Definitions;
    map<int, string> InverseDefinitions;

    string Command;
    bool SkipCommand = false;

    while (true) {

        if (!SkipCommand)
            if (!(cin >> Command))
                break;
        SkipCommand = false;
        if (Command == "clear") {
            Definitions.clear();
            InverseDefinitions.clear();
        }
        else if (Command == "def") {
            string Name;
            int Value;
            cin >> Name;
            cin >> Value;

            


            if (Definitions.find(Name) != Definitions.end()) {
                int PreviousValue = Definitions[Name];
                InverseDefinitions.erase(PreviousValue);
            }

            Definitions[Name] = Value;

            InverseDefinitions[Value] = Name;
        }
        else if (Command == "calc") {

            string ExCmd = "";

            int Value = 0;
            bool Unknown = false;
            bool Sign = true;


            do {
                cin >> ExCmd;

                if (ExCmd == "+") {
                    Sign = true;
                    std::cout << "+ ";
                }
                else if (ExCmd == "-") {
                    Sign = false;
                    std::cout << "- ";
                }
                else if (ExCmd == "def") {
                    Command = "def";
                    SkipCommand = true;
                    break;
                }
                else if (ExCmd != "=") {
                    std::cout << ExCmd << ' ';
                    //now its a variable name 

                    if (Definitions.find(ExCmd) == Definitions.end()) {
                        Unknown = true;
                    }
                    else {

                        Value += (Sign * 2 - 1) * Definitions[ExCmd];


                    }



                }


            } while (ExCmd != "=");

            if (!SkipCommand) {

                std::cout << "= ";

                if (Unknown || InverseDefinitions.find(Value) == InverseDefinitions.end()) {
                    std::cout << "unknown\n";
                }
                else {
                    std::cout << InverseDefinitions[Value] << '\n';
                }
            }

        }


    }





}
