
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt");

    int x = 250;
    int y = 250;
    int dir = 0;
    bool myGrid[500][500]; //stores whether we have visited any given position
    //myGrid[x][y] = true;
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            myGrid[i][j] = false;
        }
    }
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
        bool found = false;
        switch(dir%4) {
            case 0:
                for(int i = 0; i < steps; i++) {
                    y--;
                    if(myGrid[x][y]) {
                        found = true;
                        break;
                    }
                    myGrid[x][y] = true;
                }
            break;
            case 1:
                for(int i = 0; i < steps; i++) {
                    x++;
                    if(myGrid[x][y]) {
                        found = true;
                        break;
                    }
                    myGrid[x][y] = true;
                }
            break;
            case 2:
                for(int i = 0; i < steps; i++) {
                    y++;
                    if(myGrid[x][y]) {
                        found = true;
                        break;
                    }
                    myGrid[x][y] = true;
                }
            break;
            case 3:
                for(int i = 0; i < steps; i++) {
                    x--;
                    if(myGrid[x][y]) {
                        found = true;
                        break;
                    }
                    myGrid[x][y] = true;
                }
            break;
        }
        if(found) {
            break;
        }
    }

    x -= 250;
    y -= 250;
    //offset the 250 added in the beginning in order to start in center of array

    int absX = x > 0 ? x : -x;
    int absY = y > 0 ? y : -y;

    cout << absX + absY << endl;

    input.close();
    return 0;
}