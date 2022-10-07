
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isValidPos(int x, int y) {
    if(x >= 5 || x < 0) {return false;}
    if(y >= 5 || y < 0) {return false;}

    //when looking at the keypad, one can notice that the sum of the x and y positions must be contained in the range [2, 6]
    //and that the difference of x - y must be withing the range [-2, 2]
    int sum = x + y;
    int diff = x - y;
    if(sum > 6 || sum < 2) {return false;}
    if(diff < -2 || diff > 2) {return false;}
    return true;
}

int main() {
    
    ifstream input("input.txt");

    int x = 0;
    int y = 2;
    string keypad[5][5] = {
          {"", "", "1", "", ""},
         {"", "2", "3", "4", ""},
        {"5", "6", "7", "8", "9"},
         {"", "A", "B", "C", ""},
          {"", "", "D", "", ""}
    };
    string instrs;
    string code = "";
    while(input >> instrs) {
        for(int i = 0; i < instrs.length(); i++) {
            string dir = instrs.substr(i, 1);
            if(dir == "U") {
                if(isValidPos(x, y-1)) {
                    y--;
                }
            }
            else if(dir == "D") {
                if(isValidPos(x, y+1)) {
                    y++;
                }
            }
            else if(dir == "L") {
                if(isValidPos(x-1, y)) {
                    x--;
                }
            }
            else if(dir == "R") {
                if(isValidPos(x+1, y)) {
                    x++;
                }
            }
        }
        code += keypad[y][x];
    }

    cout << code << endl;

    input.close();
    return 0;
}