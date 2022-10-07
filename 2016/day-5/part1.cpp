
#include <iostream>
#include "md5.h"

using namespace std;

int main() {

    string ID = "abbhdwsy";
    string result = "";
    int index = 0;
    while(result.length() < 8) {
        string hash = md5(ID + to_string(index));
        if(hash.substr(0, 5) == "00000") {
            result += hash.substr(5, 1);
            cout << result << endl;
        }
        index++;
    }
    
    cout << "Door password: " << result << endl;
    return 0;
}