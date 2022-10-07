
#include <iostream>
#include <fstream>

using namespace std;

string genCheckSum(string roomName) {
    int letterCounts[26];
    for(int i = 0; i < 26; i++) {
        letterCounts[i] = 0;
    }

    for(int i = 0; i < roomName.length(); i++) {
        if(roomName.substr(i, 1) != "-") {
            letterCounts[((int) roomName[i]) - 97]++;
        }
    }

    string mostFrequentChars[5];
    for(int i = 0 ; i < 5; i++) {
        mostFrequentChars[i] = "";
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 5; j++) {
            if(mostFrequentChars[j] == "") {
                cout.flush();
                mostFrequentChars[j] = (char) (97+i);
                break;
            } else if(letterCounts[i] > letterCounts[((int) mostFrequentChars[j][0]) - 97]) {
                for(int k = 4; k > j; k--) {
                    mostFrequentChars[k] = mostFrequentChars[k-1];
                }
                mostFrequentChars[j] = (char) (97+i);
                break;
            }
        }
    }

    string retStr = "";

    for(int i = 0; i < 5; i++) {
        retStr += mostFrequentChars[i];
    }

    return retStr;
}

bool isReal(string room) {
    string givenCheckSum = room.substr(room.find("[")+1, 5);
    string calculatedCheckSum = genCheckSum(room.substr(0, room.find_last_of("-")));
    return givenCheckSum == calculatedCheckSum;
}

int getRoomId(string room) {
    return stoi(room.substr(room.find_last_of("-")+1, room.find("[")));
}

string shiftCypher(string encrypted, int shifts) {
    string decrypted = "";
    for(int i = 0; i < encrypted.length(); i++) {
        if(encrypted.substr(i, 1) == "-") {
            decrypted += " ";
            continue;
        }
        char letter = encrypted[i];
        int alphabetPos = (int)letter - 97;
        int shiftedAlphabetPos = (alphabetPos + shifts) % 26;
        decrypted += (char) (97 + shiftedAlphabetPos);
    }
    return decrypted;
}

int main() {

    ifstream input("input.txt");
    
    string roomData;
    int NPid = -1;
    while(input >> roomData) {
        if(isReal(roomData)) {
            int id = getRoomId(roomData);
            string realName = shiftCypher(roomData.substr(0, roomData.find_last_of("-")), id);
            if(realName.find("northpole") != std::string::npos) {
                NPid = id;
                break;
            }
        }
    }

    if(NPid >= 0) {
        cout << "North Pole objects are stored at sector " << NPid << endl;
    } else {
        cout << "Could not find room which sores north pole objects\n";
    }

    input.close();
    return 0;
}