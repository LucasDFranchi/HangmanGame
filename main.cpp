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
bool CheckDefeatCondition(vector<char> &errorVector);
void InformError(string errorString);
string ReadFile(ifstream &inputFile);
bool ValidGuess(string guess);

/* Main Code */
int main(){
    string guess = "";
    vector<pair<char, bool>> outputVector;
    vector<char> wrongGuesses;
    ifstream fileStream;

    string secretWord = ReadFile(fileStream);

    PrepareSecretWord(secretWord, outputVector);  

    while(true){

        UpdateDisplay(guess, outputVector, wrongGuesses);
                
        cin >> guess;        

        if (!ValidGuess(guess)){
            InformError("Informe uma letra valida [a-z][A-Z]");
        }
        else if (!ExistInSecretWord(guess, secretWord)){
            InformError("A letra informada nao existe na palavra");
            wrongGuesses.push_back(*guess.c_str());
        }
        else{

            UpdateSecretWord(guess, outputVector);

            if (CheckVictoryCondition(outputVector)){
                cout << "Parabens voce acertou a palavra secreta!" << endl;
                exit(0);
            }
        }

        if (CheckDefeatCondition(wrongGuesses)){
            cout << "Numero maximo de tentativas excedido!" << endl;
            exit(0);
        }

    }

    return 0;
}

/* Functions */
void PrepareSecretWord(string secretWord, vector<pair<char, bool>> &outputVector){
    for(char& c : secretWord) {
        outputVector.push_back(make_pair(c, false)); 
    }
}

bool ValidGuess(string guess){
    
    regex pat("^([a-z]|[A-Z]){1,1}$");

    return regex_match(guess, pat);
}

bool ExistInSecretWord(string guess, string secretWord){
    return secretWord.find(guess) != string::npos ? true : false; 
}

void UpdateSecretWord(string guess, vector<pair<char, bool>> &outputVector){

    for (size_t i = 0; i < outputVector.size(); i++){
        if (outputVector.at(i).first == *guess.c_str()){
            outputVector.at(i).second = true;
        }

        if (outputVector.at(i).second){
            cout << " " << outputVector.at(i).first << " ";
        }
        else{
            cout << " _ ";
        }

    }
    cout << endl;
}

bool CheckVictoryCondition(vector<pair<char, bool>> &outputVector){

    bool ret = true;

    for (size_t i = 0; i < outputVector.size(); i++){
        if (!outputVector.at(i).second){
            ret = false;
            break;
        }
    }

    return ret;
}

bool CheckDefeatCondition(vector<char> &errorVector){
    const int maxWrongGuessCount = 5; 

    return errorVector.size() > maxWrongGuessCount;
}

void UpdateDisplay(string guess, vector<pair<char, bool>> &outputVector, vector<char> &errorVector){
    system("clear");

    cout << "*************************" << endl;
    cout << "***** Jogo da Forca *****" << endl;
    cout << "*************************" << endl << endl;

    for (size_t i = 0; i < outputVector.size(); i++){
        if (outputVector.at(i).second){
            cout << " " << outputVector.at(i).first << " ";
        }
        else{
            cout << " _ ";
        }
    }
    if (errorVector.size() > 0){
        cout << "\t\t Letras erradas: ";
        for (auto & e : errorVector){
            cout << e << " ";
        }
    }

    cout << endl;
    cout << "Digite seu chute [a-z][A-Z]: "; 
}

void InformError(string errorString){
    system("clear");
    cout << errorString << endl;
    sleep(1);
}

string ReadFile(ifstream &inputFile){
    inputFile.open("words.txt");
    vector<string> possibleWords;
    size_t availableWords = 0;

    inputFile >> availableWords;

    for (size_t i = 0; i < availableWords; i++){
        string lastWord = "";
        inputFile >> lastWord;
        possibleWords.push_back(lastWord);
    }
    srand ( time(NULL) );
    int r = int(rand()) % availableWords + 1;

    return possibleWords.at(r);
}