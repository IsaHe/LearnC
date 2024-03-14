#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* addCharToStringIfNotIn(char* string, char toAdd) {
    char* expanded = (char *) malloc((strlen(string) + 2) * sizeof(char));
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == toAdd) {return NULL;}

        expanded[i] = string[i];
    }
    expanded[strlen(string)] = toAdd;
    expanded[strlen(string) + 1] = '\0';
    return expanded;
}

char** getAllSubStrWoutRepChar(char* string) {
    unsigned int lenghtString = strlen(string);
    char** posibleSubStr = (char**) malloc(lenghtString * sizeof(char*));

    for (int i = 0; i < lenghtString; ++i) {
        char* currentString = "";
        for (int j = i; j < lenghtString; ++j) {
            currentString = addCharToStringIfNotIn(currentString, string[j]);
            if (currentString == NULL) {
                break;
            }
            posibleSubStr[i] = currentString;
        }
    }

    return posibleSubStr;
}

unsigned int lenghtOfLongestSubstring(char* string) {
    unsigned int maxLenght = 0;

    char** allPosibleSubStr = getAllSubStrWoutRepChar(string);
    for (int i = 1; i < strlen(string); ++i) {
        if (strlen(allPosibleSubStr[i]) > maxLenght) {
            maxLenght = strlen(allPosibleSubStr[i]);
        }
    }

    return maxLenght;
}



int main() {

    char* string = " ";

    char** possibleSubStr = getAllSubStrWoutRepChar(string);
    unsigned int maxLenght = lenghtOfLongestSubstring(string);

    printf("%d\n", maxLenght);
    for (int i = 0; i < strlen(string); ++i) {
        printf("%s; ", possibleSubStr[i]);
        free(possibleSubStr[i]);
    }
    free(possibleSubStr);

    return 0;
}