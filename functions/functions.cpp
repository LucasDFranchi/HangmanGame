#include "functions.hpp"
#include "../graphics/hangman.hpp"

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
        if (tolower(outputVector.at(i).first) == tolower(*guess.c_str())){
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
    const int maxWrongGuessCount = 8; 

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
        cout << "\t\t\t Letras erradas: ";
        for (auto & e : errorVector){
            cout << e << " ";
        }
    }

    cout << endl;
    DrawHangman(errorVector.size());
    cout << "Digite seu chute [a-z][A-Z]: "; 

}

void InformError(string errorString){
    system("clear");
    cout << errorString << endl;
    sleep(1);
}

string ReadFile(ifstream &inputFile){
    vector<string> possibleWords;
    string str;

    inputFile.open("words.txt");

    if(!inputFile.is_open()){
        cout << "Arquivo de configuraçao nao encontrado!" << endl;
        cout << "Abortanto operaçao!" << endl;
        exit(-1);
    }

    while (std::getline(inputFile, str))
    {
        if(str.size() > 0)
            possibleWords.push_back(str);
    }
    inputFile.close();

    return possibleWords.at(SortingRandomValue(possibleWords));
}

int SortingRandomValue(vector<string> &stringVector){
    srand ( time(NULL) );
    return int(rand()) % stringVector.size();
}

string ToLower(string str){
    string outputString = "";

    for(char& c : str) {
        outputString += tolower(c);
    }
    return outputString;
}