
#include <iostream>
#include <fstream>

using namespace std;

string getSupernet(string IP) {
    string result = "";
    bool inHypernet = false;
    for(int i = 0; i < IP.length(); i++) {
        string currChar = IP.substr(i, 1);

        if(currChar == "]") {
            inHypernet = false;
        } else if(currChar == "[") {
            inHypernet = true;
            result += " "; //added spaces so that letters separated by hypernets are not seen as together
        } else {
            if(!inHypernet) {
                result += currChar;
            }
        }
    }
    return result;
}

string getHypernet(string IP) {
    string result = "";
    bool inHypernet = false;
    for(int i = 0; i < IP.length(); i++) {
        string currChar = IP.substr(i, 1);

        if(currChar == "]") {
            inHypernet = false;
            result += " "; //added spaces so that letters separated by supernet are not seen as together
        } else if(currChar == "[") {
            inHypernet = true;
        } else {
            if(inHypernet) {
                result += currChar;
            }
        }
    }
    return result;
}

bool supportsSSL(string IP) {
    
    string supernet = getSupernet(IP);
    string hypernet = getHypernet(IP);

    for(int i = 0; i < supernet.length()-2; i++) {
        string ABA = supernet.substr(i, 3);
        if(ABA[0] != ABA[2]) {
            continue;
        }
        string BAB = ABA.substr(1, 1) + ABA.substr(0, 1) + ABA.substr(1, 1);
        if(hypernet.find(BAB) != string::npos) {
            return true;
        }
    }

    return false;
}

int main() {

    ifstream input("input.txt");
    
    string currIP;
    int successfulIPs = 0;

    while(input >> currIP) {
        if(supportsSSL(currIP)) {
            successfulIPs++;
        }
    }

    cout << "The number of IPs that support SSL is " << successfulIPs << endl;

    input.close();
    return 0;
}