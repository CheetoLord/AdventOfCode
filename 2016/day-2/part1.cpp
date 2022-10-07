
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    ifstream input("input.txt");

    int x = 1;
    int y = 1;
    string instrs;
    string code = "";
    while(input >> instrs) {
        for(int i = 0; i < instrs.length(); i++) {
            string dir = instrs.substr(i, 1);
            if(dir == "U") {
                y = y > 0 ? y-1 : 0;
            }
            else if(dir == "D") {
                y = y < 2 ? y+1 : 2;
            }
            else if(dir == "L") {
                x = x > 0 ? x-1 : 0;
            }
            else if(dir == "R") {
                x = x < 2 ? x+1 : 2;
            }
        }
        code += to_string(1 + x + y*3);
    }

    cout << code << endl;

    input.close();
    return 0;
}