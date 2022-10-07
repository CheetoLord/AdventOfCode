
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt");

    const int messageLength = 8;
    int occurances[messageLength][26];
    for(int i = 0; i < messageLength; i++) {
        for(int j = 0; j < 26; j++) {
            occurances[i][j] = 0;
        }
    }

    string currMessage;
    while(input >> currMessage) {
        for(int i = 0; i < messageLength; i++) {
            occurances[i][(int)currMessage[i] - 97]++;
        }
    }

    string result = "";
    for(int i = 0; i < messageLength; i++) {
        int max = 0;
        int bestCharAlphabeticalIndex = -1;
        for(int j = 0; j < 26; j++) {
            if(occurances[i][j] > max) {
                max = occurances[i][j];
                bestCharAlphabeticalIndex = j;
            }
        }
        result += (char) (bestCharAlphabeticalIndex + 97);
    }
    
    cout << "Decrypted message: " << result << endl;

    input.close();
    return 0;
}