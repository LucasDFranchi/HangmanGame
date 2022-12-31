#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

/* Functions Prototype */
void UpdateDisplay(string guess, vector<pair<char, bool>> &outputVector, vector<char> &errorVector);
void PrepareSecretWord(string secretWord, vector<pair<char, bool>> &outputVector);
void UpdateSecretWord(string guess, vector<pair<char, bool>> &outputVector);
bool CheckVictoryCondition(vector<pair<char, bool>> &outputVector);
bool ExistInSecretWord(string guess, string secretWord);
int SortingRandomValue(vector<string> &stringVector);
bool CheckDefeatCondition(vector<char> &errorVector);
void InformError(string errorString);
string ReadFile(ifstream &inputFile);
bool ValidGuess(string guess);