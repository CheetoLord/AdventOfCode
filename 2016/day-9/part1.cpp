
#include <iostream>
#include <fstream>

using namespace std;

string decompress(string data) {

    string decompressedData = "";
    int dataLength = data.length();
    bool readingMarker = false;

    bool readingLength = true;
    string markedLength = "";
    string markedCount = "";

    for(int i = 0; i < dataLength; i++) {
        if(!readingMarker) {

            if(data[i] == '(') {
                readingMarker = true;
            } else {
                decompressedData += data[i];
            }

        } else { //if reading marker

            if(readingLength) {
                if(data[i] == 'x') {
                    readingLength = false;
                } else {
                    markedLength += data[i];
                }
            } else { //if not reading length
                if(data[i] == ')') {
                    readingLength = true;
                    readingMarker = false;

                    string markedText = data.substr(i+1, stoi(markedLength));
                    for(int j = 0; j < stoi(markedCount); j++) {
                        decompressedData += markedText;
                    }
                    i += stoi(markedLength);

                    markedLength = "";
                    markedCount = "";
                } else {
                    markedCount += data[i];
                }
            }

        } //end if/else
    } //end for

    return decompressedData;

}

int main() {

    ifstream input("input.txt");
    string myData;
    input >> myData;
    input.close();
    
    string decompressedData = decompress(myData);

    cout << "Length of decompressed data is: " << decompressedData.length() << endl;
    
    return 0;
}