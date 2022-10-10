
#include <iostream>
#include <fstream>

using namespace std;


void giveBotChip(int botNum, int chipNum, int *chip1, int *chip2) {
    if(chipNum > chip1[botNum]) {
        chip2[botNum] = chip1[botNum];
        chip1[botNum] = chipNum;
    } else {
        chip2[botNum] = chipNum;
    }
}


bool botHasChip(int botNum, int chipNum, int *chip1, int *chip2) {
    return chip1[botNum] == chipNum || chip2[botNum] == chipNum;
}


void doSetup(string instr, int *chip1, int *chip2) {
    if(instr.substr(0, 5) != "value") {
        return;
    }

    int chipNum = stoi(instr.substr(6, instr.substr(6).find(" ")));
    int botNum = stoi(instr.substr(instr.find("bot") + 4));
    giveBotChip(botNum, chipNum, chip1, chip2);
}


//returns true if bot in instruction is the one in question
bool doExchange(string instr, int *chip1, int *chip2, int *outputs) {
    if(instr.substr(0, 5) == "value") {
        return false;
    }
    
    int botNum = stoi(instr.substr(4, instr.substr(4).find(" ")));

    if(chip1[botNum] == -1 || chip2[botNum] == -1) { //only do operation if bot has 2 microchips
        return false;
    }

    if(chip1[botNum] == 61 && chip2[botNum] == 17) { //if bot is the one we are searching for
        return true;
    }


    if(instr.find("low to output") != string::npos) {
        int numStartIndex = instr.find("low to output ")+14;
        int outputIndex = stoi(instr.substr(numStartIndex, instr.substr(numStartIndex).find(" ")));
        outputs[outputIndex] = chip2[botNum];
    } else {
        int numStartIndex = instr.find("low to bot ")+11;
        int recipBot = stoi(instr.substr(numStartIndex, instr.substr(numStartIndex).find(" ")));
        if(!botHasChip(recipBot, chip2[botNum], chip1, chip2)) {
            giveBotChip(recipBot, chip2[botNum], chip1, chip2);
        }
    }

    if(instr.find("high to output") != string::npos) {
        int numStartIndex = instr.find("high to output ")+15;
        int outputIndex = stoi(instr.substr(numStartIndex));
        outputs[outputIndex] = chip1[botNum];
    } else {
        int numStartIndex = instr.find("high to bot ")+12;
        int recipBot = stoi(instr.substr(numStartIndex));
        if(!botHasChip(recipBot, chip1[botNum], chip1, chip2)) {
            giveBotChip(recipBot, chip1[botNum], chip1, chip2);
        }
    }

    return false;
}


int main() {

    ifstream input("input.txt");

    //assumes no bot has a number higher than 249
    //chip 1 is always bigger chip
    int storedChip1[250];
    int storedChip2[250];
    int outputBins[250];

    //initialize all bots to store nothing
    for(int i = 0; i < 250; i++) {
        storedChip1[i] = -1;
        storedChip2[i] = -1;
        outputBins[i] = -1;
    }

    //initialize all bot chip values
    string instr;
    while(getline(input, instr)) {
        doSetup(instr, storedChip1, storedChip2);
    }

    //return to beggining of input file
    input.clear();
    input.seekg(0);

    int loops = 0;
    int targetBotNum = -1;
    while(true) {
        while(getline(input, instr)) {
            if(doExchange(instr, storedChip1, storedChip2, outputBins)) {
                targetBotNum = stoi(instr.substr(4, instr.substr(4).find(" ")));
                break;
            }
        }
        input.clear();
        input.seekg(0);
        if(targetBotNum != -1) {
            break;
        }

        loops++;
        if(loops >= 100) {
            break;
        }
    }
    
    cout << "The bot which compares value-61 and value-17 microchips is bot number " << targetBotNum << endl;

    input.close();
    return 0;
}