#include "./functions/functions.hpp"

using namespace std;

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
        else if (!ExistInSecretWord(ToLower(guess), ToLower(secretWord))){
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

