
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt");
    
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
    int x3;
    int y3;
    int z3;
    int successes = 0;
    while(input >> x1 && input >> x2 && input >> x3) {
        input >> y1; input >> y2; input >> y3;
        input >> z1; input >> z2; input >> z3;
        if(x1 + y1 > z1 && x1 + z1 > y1 && y1 + z1 > x1) {
            successes++;
        }
        if(x2 + y2 > z2 && x2 + z2 > y2 && y2 + z2 > x2) {
            successes++;
        }
        if(x3 + y3 > z3 && x3 + z3 > y3 && y3 + z3 > x3) {
            successes++;
        }
    }

    cout << successes << endl;

    input.close();
    return 0;
}