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
    int numOfVoid;
    int numOfFile;
    int numOfFunction;
    int numOfArray;
    int numOfCharArray;
    int numOfIntArray;
    int numOfCharPointer;
    int numOfIntPointer;
    int numOfFilePointer;
    int numOfPointer;
    int numOfCharFunction;
    int numOfIntFunction;
    int numOfVoidFunction;
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
int findFunctionArrAndPointer(int j, char arr[], int numOfFunction, int numOfArray, int numOfPointer);
void checkArrayType(int arrType);
void checkPointerType(int pointerType);
void checkFunctionType(int functionType);
void increasingFun(int result, int type);
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

    for (int i = 0; i < 1; ++i) {
        printf("num of int = file one: %d vs file two %d\n",structureOne.numOfInt, structureTwo.numOfInt);
        printf("num of char = file one: %d vs file two %d\n",structureOne.numOfChar, structureTwo.numOfChar);
        printf("num of float = file one: %d vs file two %d\n",structureOne.numOfFloat, structureTwo.numOfFloat);
        printf("num of double = file one: %d vs file two %d\n",structureOne.numOfDouble, structureTwo.numOfDouble);
        printf("num of void = file one: %d vs file two %d\n",structureOne.numOfVoid, structureTwo.numOfVoid);
        printf("num of FILE = file one: %d vs file two %d\n",structureOne.numOfFile, structureTwo.numOfFile);
        printf("num of Function = file one: %d vs file two %d\n",structureOne.numOfFunction, structureTwo.numOfFunction);
        printf("num of pointer = file one: %d vs file two %d\n",structureOne.numOfPointer, structureTwo.numOfPointer);
        printf("num of Array = file one: %d vs file two %d\n",structureOne.numOfArray, structureTwo.numOfArray);
        printf("num of Struct = file one: %d vs file two %d\n",structureOne.numOfStruct, structureTwo.numOfStruct);
        printf("num of charArray = file one: %d vs file two %d\n",structureOne.numOfCharArray, structureTwo.numOfCharArray);
        printf("num of intArray = file one: %d vs file two %d\n",structureOne.numOfIntArray, structureTwo.numOfIntArray);
        printf("num of intFun = file one: %d vs file two %d\n",structureOne.numOfIntFunction, structureTwo.numOfIntFunction);
        printf("num of charFun = file one: %d vs file two %d\n",structureOne.numOfCharFunction, structureTwo.numOfCharFunction);
        printf("num of voidFun = file one: %d vs file two %d\n",structureOne.numOfVoidFunction, structureTwo.numOfVoidFunction);
        printf("num of intPinter = file one: %d vs file two %d\n",structureOne.numOfIntPointer, structureTwo.numOfIntPointer);
        printf("num of charPointer = file one: %d vs file two %d\n",structureOne.numOfCharPointer, structureTwo.numOfCharPointer);
        printf("num of FilePointer = file one: %d vs file two %d\n",structureOne.numOfFilePointer, structureTwo.numOfFilePointer);
    }

    return 0;
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
                int j = i + 2;
                int result = findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction,structureOne.numOfArray, structureOne.numOfPointer);
                increasingFun(result,2);
            }
            else if (structureOne.characters[i] == 'c'  && structureOne.characters[i+1] == 'h'  && structureOne.characters[i+2] == 'a' && structureOne.characters[i+3] == 'r' && structureOne.characters[i+4] == ' '){
                structureOne.numOfChar += 1;
                int j = i + 3;
                int result = findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);
                increasingFun(result,1);
            }else if (structureOne.characters[i] == 's'  && structureOne.characters[i+1] == 't'  && structureOne.characters[i+2] == 'r' && structureOne.characters[i+3] == 'u' && structureOne.characters[i+4] == 'c' && structureOne.characters[i+5] == 't' && structureOne.characters[i+6] == ' '){
                structureOne.numOfStruct += 1;
            }else if (structureOne.characters[i] == 'f'  && structureOne.characters[i+1] == 'l'  && structureOne.characters[i+2] == 'o' && structureOne.characters[i+3] == 'a' && structureOne.characters[i+4] == 't' && structureOne.characters[i+5] == ' '){
                structureOne.numOfFloat += 1;
            }else if (structureOne.characters[i] == 'd'  && structureOne.characters[i+1] == 'o'  && structureOne.characters[i+2] == 'u' && structureOne.characters[i+3] == 'b' && structureOne.characters[i+4] == 'l' && structureOne.characters[i+5] == 'e' && structureOne.characters[i+6] == ' '){
                structureOne.numOfDouble += 1;
            }else if (structureOne.characters[i] == 'F'  && structureOne.characters[i+1] == 'I'  && structureOne.characters[i+2] == 'L' && structureOne.characters[i+3] == 'E' && structureOne.characters[i+4] == ' '){
                structureOne.numOfFile += 1;
                int j = i + 3;
                int result =findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);
                increasingFun(result,3);
            }else if (structureOne.characters[i] == 'v'  && structureOne.characters[i+1] == 'o'  && structureOne.characters[i+2] == 'i' && structureOne.characters[i+3] == 'd' && structureOne.characters[i+4] == ' '){
                printf("checking void");
                structureOne.numOfVoid++;
                int j = i+3;
                int result = findFunctionArrAndPointer(j,structureOne.characters,structureOne.numOfFunction, structureOne.numOfArray, structureOne.numOfPointer);
                increasingFun(result,3);
            }

       }else if (gIndex == 1) {
            if (structureTwo.characters[i] == 'i'  && structureTwo.characters[i+1] == 'n'  && structureTwo.characters[i+2] == 't' && structureTwo.characters[i+3] == ' '){
                structureTwo.numOfInt += 1;
                int j = i + 2;
                int result = findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction, structureTwo.numOfArray, structureTwo.numOfPointer);

                increasingFun(result,2);
            }else if (structureTwo.characters[i] == 'c'  && structureTwo.characters[i+1] == 'h'  && structureTwo.characters[i+2] == 'a' && structureTwo.characters[i+3] == 'r' && structureTwo.characters[i+4] == ' '){
                structureTwo.numOfChar += 1;
                int j = i + 3;
                int result =findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);
                increasingFun(result,1);
            }else if (structureTwo.characters[i] == 's'  && structureTwo.characters[i+1] == 't'  && structureTwo.characters[i+2] == 'r' && structureTwo.characters[i+3] == 'u' && structureTwo.characters[i+4] == 'c' && structureTwo.characters[i+5] == 't' && structureTwo.characters[i+6] == ' ') {
                structureTwo.numOfStruct += 1;
            }else if (structureTwo.characters[i] == 'f'  && structureTwo.characters[i+1] == 'l'  && structureTwo.characters[i+2] == 'o'  && structureTwo.characters[i+3] == 'a' && structureTwo.characters[i+4] == 't' && structureTwo.characters[i+5] == ' '){
                structureTwo.numOfFloat += 1;
            }else if (structureTwo.characters[i] == 'd'  && structureTwo.characters[i+1] == 'o'  && structureTwo.characters[i+2] == 'u' && structureTwo.characters[i+3] == 'b' && structureTwo.characters[i+4] == 'l' && structureTwo.characters[i+5] == 'e' && structureTwo.characters[i+6] == ' '){
                structureTwo.numOfDouble += 1;
            }else if (structureTwo.characters[i] == 'F'  && structureTwo.characters[i+1] == 'I'  && structureTwo.characters[i+2] == 'L' && structureTwo.characters[i+3] == 'E' && structureTwo.characters[i+4] == ' '){
                structureTwo.numOfFile += 1;
                int j = i+3;
                int result  = findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);
                increasingFun(result,3) ;
            }else if (structureTwo.characters[i] == 'v'  && structureTwo.characters[i+1] == 'o'  && structureTwo.characters[i+2] == 'i' && structureTwo.characters[i+3] == 'd' && structureTwo.characters[i+4] == ' '){
                structureTwo.numOfVoid++;
                int j = i+3;
                int result = findFunctionArrAndPointer(j,structureTwo.characters,structureTwo.numOfFunction,structureTwo.numOfArray, structureTwo.numOfPointer);
                increasingFun(result,3);
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


int findFunctionArrAndPointer(int j, char arr[], int numOfFunction, int numOfArray, int numOfPointer) {
    while (arr[j+1] != '=') {
        j++;
        if (arr[j] == '(') {
            int k = j;
            printf("k => %d", k);
            while (arr[k + 1] != '=' || arr[k + 1] != ';') {
                if (arr[k] = ')') {
                    if (gIndex == 0) {
                        numOfFunction++;
                        structureOne.numOfFunction = numOfFunction;
                    } else if (gIndex == 1) {
                        numOfFunction++;
                        structureTwo.numOfFunction = numOfFunction;
                    }
                    return 1;
                }
                k++;
            }

        } else if (arr[j] == '[') {
            int k = j;
            while (arr[k] != '=' || arr[k] != ';') {
                if (arr[k] = ']') {
                    if (gIndex == 0) {
                        numOfArray++;
                        structureOne.numOfArray = numOfArray;
                    } else if (gIndex == 1) {
                        numOfArray++;
                        structureTwo.numOfArray = numOfArray;
                    }
                    return 2;
                }
                k++;
            }
        } else if (arr[j] == '*') {
            if (gIndex == 0) {
                numOfPointer++;
                structureOne.numOfPointer = numOfPointer;
            } else if (gIndex == 1) {
                numOfPointer++;
                structureTwo.numOfPointer = numOfPointer;
            }
            return 3;
        }
    }

void checkArrayType(int arrType) {
    switch (arrType) {
        case 1:
            if (gIndex == 0){
                structureOne.numOfCharArray += 1;
            }else if (gIndex == 1){
                structureTwo.numOfCharArray += 1;
            }
            break;
        case 2:
            if (gIndex == 0){
                structureOne.numOfIntArray += 1;
            }else if (gIndex == 1){
                structureTwo.numOfIntArray += 1;
            }
            break;
    }
}

void checkPointerType(int pointerType) {
    switch (pointerType) {
        case 1:
            if (gIndex == 0){
                structureOne.numOfCharPointer += 1;
            }else if (gIndex == 1){
                structureTwo.numOfCharPointer += 1;
            }
            break;
        case 2:
            printf("reading intPointer %d\n",gIndex);
            if (gIndex == 0){

                structureOne.numOfIntPointer += 1;
            }else if (gIndex == 1){
                structureTwo.numOfIntPointer += 1;
            }
            break;
        case 3:
            if (gIndex == 0){
                structureOne.numOfFilePointer += 1;
            }else if (gIndex == 1){
                structureTwo.numOfFilePointer += 1;
            }
            break;
    }
}

void checkFunctionType(int functionType) {
    switch (functionType) {
        case 1:
            if (gIndex == 0){
                structureOne.numOfCharFunction += 1;
            }else if (gIndex == 1){
                structureTwo.numOfCharFunction+= 1;
            }
            break;
        case 2:
            if (gIndex == 0){
                structureOne.numOfIntFunction += 1;
            }else if (gIndex == 1){
                structureTwo.numOfIntFunction += 1;
            }
            break;
        case 3:
            if (gIndex == 0){
                structureOne.numOfVoidFunction += 1;
            }else if (gIndex == 1){
                structureTwo.numOfVoidFunction += 1;
            }
            break;
    }
}

void increasingFun(int result, int type){


    switch (result) {
        case 1:
            checkFunctionType(type);
            break;
        case 2:
            checkArrayType(type);
            break;
        case 3:
            checkPointerType(type);
            break;
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
    printf("%d (percent) same!!\n",percentage);
}

