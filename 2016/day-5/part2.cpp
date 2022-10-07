
#include <iostream>
#include "md5.h"

using namespace std;

int main() {

    string ID = "abbhdwsy";
    string result = "--------";
    const string invalidIndexes = "89abcdef";
    int index = 0;
    while(result.find("-") != string::npos) {
        string hash = md5(ID + to_string(index));
        if(hash.substr(0, 5) == "00000") {
            if(invalidIndexes.find(hash.substr(5, 1)) != string::npos) {
                index++;
                continue;
            }

            int charPos = stoi(hash.substr(5, 1));
            if(result.substr(charPos, 1) != "-") {
                index++;
                continue;
            }

            result = result.substr(0, charPos) + hash.substr(6, 1) + result.substr(charPos+1);
        }
        index++;
    }
    
    cout << "Door password: " << result << endl;
    return 0;
}