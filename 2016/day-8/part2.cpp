
#include <iostream>
#include <fstream>

using namespace std;


void makeRect(bool **display, int width, int height) {
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            display[j][i] = true;
        }
    }
}


void shiftRow(bool **display, int width, int height, int row, int amnt) {
    bool *newRow = new bool[width];
    for(int i = 0; i < width; i++) {
        newRow[(i + amnt) % width] = display[row][i];
    }
    for(int i = 0; i < width; i++) {
        display[row][i] = newRow[i];
    }
}


void shiftCol(bool **display, int width, int height, int col, int amnt) {
    bool *newRow = new bool[height];
    for(int i = 0; i < height; i++) {
        newRow[(i + amnt) % height] = display[i][col];
    }
    for(int i = 0; i < height; i++) {
        display[i][col] = newRow[i];
    }
}


void performOperation(bool **display, int width, int height, string instr) {
    if(instr.find("rect") != string::npos) {
        int width = stoi(instr.substr(5, instr.find("x")-5));
        int height = stoi(instr.substr(instr.find("x")+1));
        makeRect(display, width, height);
    }
    else if (instr.find("rotate row y=") != string::npos) {
        int row = stoi(instr.substr(13, instr.find(" by ")-13));
        int shift = stoi(instr.substr(instr.find(" by ")+4));
        shiftRow(display, width, height, row, shift);
    }
    else if (instr.find("rotate column x=") != string::npos) {
        int col = stoi(instr.substr(16, instr.find(" by ")-16));
        int shift = stoi(instr.substr(instr.find(" by ")+4));
        shiftCol(display, width, height, col, shift);
    }
}


int main() {

    ifstream input("input.txt");

    const int rows = 6;
    const int cols = 50;

    bool **display = new bool*[rows];
    for(int i = 0; i < rows; i++) {
        display[i] = new bool[cols];
        for(int j = 0; j < cols; j++) {
            display[i][j] = false;
        }
    }

    string instr;
    while(getline(input, instr)) {
        performOperation(display, cols, rows, instr);
    }
    
    int totalLit = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(display[i][j]) {
                totalLit++;
            }
        }
    }

    //code from part 1 copied, this is the only change

    cout << "displaying image:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << (display[i][j] ? "#" : " ");
        }
        cout << endl;
    }

    input.close();
    return 0;
}