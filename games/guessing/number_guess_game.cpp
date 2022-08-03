#include <string>
#include <iostream>
#include <random>
using namespace std;

/* Here goes any game rule constant.  */
class GameRules
{
public:
    static const int lives = 3;
};

/*Returns a random integer between the given range*/
int getRandomInteger(int min, int max)
{
    return min + (std::rand() % (max - min + 1));
}

class NumberGuessingGame
{
private:
    int promptUser()
    {
        int input = 0;
        cout << "Enter a random integer" << endl;
        cin >> input;
        return input;
    }

    void getFeedbackMessage(string message)
    {
        cout << "Number was " + message << endl;
    }

    void giveFeedback(int difference)
    {
        if (difference == 0)
            return getFeedbackMessage("correct, you won!!");
        if (difference <= 1)
            return getFeedbackMessage("close");
        if (difference <= 3)
            return getFeedbackMessage("not close and not far...");
        return getFeedbackMessage("far");
    }

    bool checkGuessing(int numberToGuess, int input)
    {
        const int difference = abs(numberToGuess - input);
        giveFeedback(difference);
        if (difference == 0)
            return true;
        return false;
    }

    void showLooseMessage()
    {
        cout << "Ohhh, you loose..." << endl;
    }

public:
    string showGameStartup()
    {
        string command = "";
        cout << "Welcome to the random number guesser game. \n Enter h to get the game rules \n Enter e to exit \n Enter any other key to start the game " << endl;
        cin >> command;
        return command;
    }

    void startGame()
    {
        // Seed to get random numbers
        srand(time(0));
        const int numberToGuess = getRandomInteger(1, 10);
        for (int i = 1; i <= GameRules::lives; i++)
        {
            const int input = promptUser();
            const bool hasGuessed = checkGuessing(numberToGuess, input);
            if (hasGuessed)
                break;
            if (i == GameRules::lives)
                showLooseMessage();
        }
    }
    void showGameInstructions()
    {
        string command = "";
        cout << "Hello There, this is a number guessing game. You will have three opportunities to guess a number between 1 and 10. \n Each time you enter a number, I will give some hints whether you are close or not for the number to guess. \n Enter any key to start" << endl;
        cin >> command;
    }
};

int main()
{
    NumberGuessingGame game;
    string commandResult = game.showGameStartup();
    if (commandResult == "h")
        game.showGameInstructions();
    if (commandResult == "e")
        return 0;
    game.startGame();
    return 0;
}
