
#include <iostream>
#include <fstream>

using namespace std;

bool supportsTLS(string IP) {
    int hypernetDepth = 0;
    bool ABBA = false;
    bool subABBA = false;
    for(int i = 0; i < IP.length()-3; i++) {
        string next4 = IP.substr(i, 4);
        if(next4[0] == next4[3] && next4[1] == next4[2] && next4[0] != next4[1]) {
            if(hypernetDepth > 0) {
                subABBA = true;
            } else {
                ABBA = true;
            }
        }
        
        string currChar = IP.substr(i, 1);
        if(currChar == "]") {
            hypernetDepth--;
        }
        if(currChar == "[") {
            hypernetDepth++;
        }
    }

    return ABBA && !subABBA;
}

int main() {

    ifstream input("input.txt");
    
    string currIP;
    int successfulIPs = 0;

    while(input >> currIP) {
        if(supportsTLS(currIP)) {
            successfulIPs++;
        }
    }

    cout << "The number of IPs that support TLS is " << successfulIPs << endl;

    input.close();
    return 0;
}