
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt");

    int x = 0;
    int y = 0;
    int dir = 0;
    string instr;
    while(input >> instr) {
        int commaPos = instr.find(",");
        if(commaPos >= 0) {
            instr = instr.substr(0, commaPos);
        }

        if(instr[0] == "L"[0]) { //apparently "L" is a 'const char *' i guess...
            dir+=3; //equivalent to minus 1 since modulous 4, but this way it never goes negative
        } else {
            dir++;
        }

        int steps = stoi(instr.substr(1));
        switch(dir%4) {
            case 0:
                y -= steps;
            break;
            case 1:
                x += steps;
            break;
            case 2:
                y += steps;
            break;
            case 3:
                x -= steps;
            break;
        }
    }

    int absX = x > 0 ? x : -x;
    int absY = y > 0 ? y : -y;

    cout << absX + absY << endl;

    input.close();
    return 0;
}