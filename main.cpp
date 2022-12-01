#include <iostream>
#include "stdio.h"
#include "stdlib.h"


struct structure {

    int alpha[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char characters[10000];
    int numOfEachCharacter[26];
    int numOfInt;
    int numOfChar;
    int numOfStruct;
    int numOfFloat;
    int numOfDouble;
    int numOfFile;
    int numOfFunction = 0;
    int numOfArray = 0;
    int numOfPointer = 0;
};

struct structureTwo {
    int percentOfAlpha = 0;
    int percentOfChar = 0;
    int percentOfInt = 0;
    int percentOfStruct = 0;
    int percentOfFloat = 0;
    int percentOfDouble = 0;
    int percentOfFile =0;
    int percentOfFunction = 0;
    int percentOfArray = 0;
    int percentOfPointer = 0;
} percentStruct;

struct structure structureOne;
struct structure structureTwo;

int gIndex = 0;
int fullPercentage = 1000;
int percentage;

void readFile (char fileName[100]);
void checkDataType();
void findFunctionArrAndPointer(int j, char arr[], int numOfFunction, int numOfArray, int numOfPointer);
void compare();
int calculateEachPercentage (int numOne, int numTwo);
void  calculatePercentage ();

int main () {
    char fileOneName[100] = "fileOne.txt";
    char fileTwoName[100] = "fileTwo.txt";
    readFile(fileOneName);
    gIndex = 1;
    readFile(fileTwoName);
    gIndex = 0;
    checkDataType();
    gIndex = 1;
    checkDataType();
    compare();
    calculatePercentage ();
}

void readFile (char fileName[100]) {
    FILE *fptr;
    fptr = fopen(fileName, "r");

    char c = fgetc(fptr);

    struct  structure Data;
    int i = 0;
    while (!feof(fptr) == 1) {
        if (gIndex == 0){
            structureOne.characters[i] = c;
        }else if (gIndex == 1) {
            structureTwo.characters[i] = c;
        }
        i++;
        int index = c - 97;
        Data.alpha[index]++;
        c = fgetc(fptr);
    }
    fclose(fptr);

    for (int i = 0; i < 26; ++i) {
        if (gIndex == 0) {
            structureOne.numOfEachCharacter[i] = Data.alpha[i];
        }else if (gIndex == 1) {
            structureTwo.numOfEachCharacter[i] = Data.alpha[i];
        }
    }

}


void checkDataType() {
    for (int i = 0; i < 10000; i++) {
        if (gIndex == 0){
            if (structureOne.characters[i] == 'i'  && structureOne.characters[i+1] == 'n'  && structureOne.characters[i+2] == 't' && structureOne.characters[i+3] == ' '){
                structureOne.numOfInt += 1;
                int j = i + 4;
                findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction,structureOne.numOfArray, structureOne.numOfPointer);

            }else if (structureOne.characters[i] == '*'){

            }
            else if (structureOne.characters[i] == 'c'  && structureOne.characters[i+1] == 'h'  && structureOne.characters[i+2] == 'a' && structureOne.characters[i+3] == 'r' && structureOne.characters[i+4] == ' '){
                structureOne.numOfChar += 1;
                int j = i + 5;
                findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);

            }else if (structureOne.characters[i] == 's'  && structureOne.characters[i+1] == 't'  && structureOne.characters[i+2] == 'r' && structureOne.characters[i+3] == 'u' && structureOne.characters[i+4] == 'c' && structureOne.characters[i+5] == 't' && structureOne.characters[i+6] == ' '){
                structureOne.numOfStruct += 1;
            }else if (structureOne.characters[i] == 'f'  && structureOne.characters[i+1] == 'l'  && structureOne.characters[i+2] == 'o' && structureOne.characters[i+3] == 'u' && structureOne.characters[i+4] == 'a' && structureOne.characters[i+5] == 't' && structureOne.characters[i+6] == ' '){
                structureOne.numOfFloat += 1;
            }else if (structureOne.characters[i] == 'd'  && structureOne.characters[i+1] == 'o'  && structureOne.characters[i+2] == 'u' && structureOne.characters[i+3] == 'b' && structureOne.characters[i+4] == 'l' && structureOne.characters[i+5] == 'e' && structureOne.characters[i+6] == ' '){
                structureOne.numOfDouble += 1;
            }else if (structureOne.characters[i] == 'F'  && structureOne.characters[i+1] == 'I'  && structureOne.characters[i+2] == 'L' && structureOne.characters[i+3] == 'E' && structureOne.characters[i+4] == ' '){
                structureOne.numOfFile += 1;
                int j = i + 5;
                findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);
            }else if (structureOne.characters[i] == 'v'  && structureOne.characters[i+1] == 'o'  && structureOne.characters[i+2] == 'i' && structureOne.characters[i+3] == 'd' && structureOne.characters[i+4] == ' '){
                int j = i+5;
                findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);
            }

       }else if (gIndex == 1) {
            if (structureTwo.characters[i] == 'i'  && structureTwo.characters[i+1] == 'n'  && structureTwo.characters[i+2] == 't' && structureTwo.characters[i+3] == ' '){
                structureTwo.numOfInt += 1;
                int j = i + 4;
                findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction, structureTwo.numOfArray, structureTwo.numOfPointer);

            }else if (structureTwo.characters[i] == 'c'  && structureTwo.characters[i+1] == 'h'  && structureTwo.characters[i+2] == 'a' && structureTwo.characters[i+3] == 'r' && structureTwo.characters[i+4] == ' '){
                structureTwo.numOfChar += 1;
                int j = i + 5;
                findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);

            }else if (structureTwo.characters[i] == 's'  && structureTwo.characters[i+1] == 't'  && structureTwo.characters[i+2] == 'r' && structureTwo.characters[i+3] == 'u' && structureTwo.characters[i+4] == 'c' && structureTwo.characters[i+5] == 't' && structureTwo.characters[i+6] == ' ') {
                structureTwo.numOfStruct += 1;
            }else if (structureTwo.characters[i] == 'f'  && structureTwo.characters[i+1] == 'l'  && structureTwo.characters[i+2] == 'o' && structureTwo.characters[i+3] == 'u' && structureTwo.characters[i+4] == 'a' && structureTwo.characters[i+5] == 't' && structureTwo.characters[i+6] == ' '){
                structureTwo.numOfFloat += 1;
            }else if (structureTwo.characters[i] == 'd'  && structureTwo.characters[i+1] == 'o'  && structureTwo.characters[i+2] == 'u' && structureTwo.characters[i+3] == 'b' && structureTwo.characters[i+4] == 'l' && structureTwo.characters[i+5] == 'e' && structureTwo.characters[i+6] == ' '){
                structureTwo.numOfDouble += 1;
            }else if (structureTwo.characters[i] == 'F'  && structureTwo.characters[i+1] == 'I'  && structureTwo.characters[i+2] == 'L' && structureTwo.characters[i+3] == 'E' && structureTwo.characters[i+4] == ' '){
                structureTwo.numOfFile += 1;
                int j = i+5;
                findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);
            }else if (structureOne.characters[i] == 'v'  && structureOne.characters[i+1] == 'o'  && structureOne.characters[i+2] == 'i' && structureOne.characters[i+3] == 'd' && structureOne.characters[i+4] == ' '){
                int j = i+5;
                findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);
            }
        }
    }
}

void compare() {
    int numOfAlpha = 26;
    int matchAlpha = 0;
    int percent;
    for (int i = 0; i < 26; ++i) {
        if (structureOne.numOfEachCharacter[i] == 0 && structureTwo.numOfEachCharacter[i] == 0){
            numOfAlpha--;
        }else   {
            if (structureOne.numOfEachCharacter[i] == structureTwo.numOfEachCharacter[i]){
                matchAlpha++;
            }
        }
    }
    percent = (matchAlpha*100)/numOfAlpha;
    percentStruct.percentOfAlpha = percent;

    percent = calculateEachPercentage(structureOne.numOfInt,structureTwo.numOfInt);
    percentStruct.percentOfInt = percent;
    percent = calculateEachPercentage(structureOne.numOfChar,structureTwo.numOfChar);
    percentStruct.percentOfChar = percent;
    percent = calculateEachPercentage(structureOne.numOfStruct,structureTwo.numOfStruct);
    percentStruct.percentOfStruct = percent;
    percent = calculateEachPercentage(structureOne.numOfFloat,structureTwo.numOfFloat);
    percentStruct.percentOfFloat = percent;
    percent = calculateEachPercentage(structureOne.numOfDouble,structureTwo.numOfDouble);
    percentStruct.percentOfDouble = percent;
    percent = calculateEachPercentage(structureOne.numOfFile,structureTwo.numOfFile);
    percentStruct.percentOfFile = percent;
    percent = calculateEachPercentage(structureOne.numOfFunction,structureTwo.numOfFunction);
    percentStruct.percentOfFunction = percent;
    percent = calculateEachPercentage(structureOne.numOfArray,structureTwo.numOfArray);
    percentStruct.percentOfArray = percent;
    percent = calculateEachPercentage(structureOne.numOfPointer,structureTwo.numOfPointer);
    percentStruct.percentOfPointer = percent;
};


void findFunctionArrAndPointer(int j, char arr[], int numOfFunction, int numOfArray, int numOfPointer) {
    while (arr[j+1] == '=') {
        if (arr[j] == '('){
            numOfFunction++;
            break;
        }else if (arr[j] == '['){
            numOfArray++;
        }else if (arr[j] == '*') {
            numOfPointer++;
        }
        j++;
    }
}

int calculateEachPercentage (int numOne, int numTwo) {
    int percent;
    if (numOne < numTwo) {
        percent = (numOne*100)/numTwo;
    }else if (numOne > numTwo) {
        percent = (numTwo*100)/numOne;
    }else {
        percent = 100;
    }
    return percent;
}



void  calculatePercentage () {
    int comparedPercent = percentStruct.percentOfStruct + percentStruct.percentOfChar
                        + percentStruct.percentOfInt + percentStruct.percentOfAlpha + percentStruct.percentOfFloat
                        + percentStruct.percentOfDouble + percentStruct.percentOfFile + percentStruct.percentOfFunction
                        + percentStruct.percentOfArray + percentStruct.percentOfPointer;
    percentage = (comparedPercent*100)/fullPercentage;
    printf("%d (percent) same!!!",percentage);
}