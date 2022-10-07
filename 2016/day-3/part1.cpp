
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt");
    
    int x;
    int y;
    int z;
    int successes = 0;
    while(input >> x && input >> y && input >> z) {
        if(x + y <= z || x + z <= y || y + z <= x) {
            continue;
        }
        successes++;
    }

    cout << successes << endl;

    input.close();
    return 0;
}