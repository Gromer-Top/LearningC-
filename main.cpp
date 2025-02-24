#include <iostream>
#include <vector>

int randomizeGuess();
int enterUserGuess(std::vector <std::string> variants);
void calcResultGame(int userGuess, int compGuess, std::vector <std::string> variants);

int main()
{
    int userGuess(0), compGuess(0);
    bool gameOver = false;
    while (!gameOver)
    {
        std::vector <std::string> variants {"Scissors", "Rock", "Paper"};
        srand(time(0));
        compGuess = randomizeGuess();
        userGuess = enterUserGuess(variants);
        while (userGuess < 0 || userGuess >= variants.size())
        {
            std::cout << "Error! Please try again.";
            userGuess = enterUserGuess(variants);
        }
        calcResultGame(userGuess, compGuess, variants);
        std::cout << "Play again? (0: Yes): ";
        std::cin >> gameOver;
    }
    return 0;
}

int randomizeGuess()
{
    int min = 0;
    int max = 2;
    int res = rand() % (max - min + 1) + min;
    return res;
}

int enterUserGuess(std::vector <std::string> variants)
{
    int userGuess;
    std::cout << "Options: \n";
    for (int i = 0; i < variants.size(); i++)
    {
        std::cout << i + 1 << ": " << variants[i] << "\n";
    }
    std::cout << "Enter your choice: ";
    std::cin >> userGuess;
    return userGuess - 1;
}

void calcResultGame(int userGuess, int compGuess, std::vector <std::string> variants)
{
    if (userGuess == 0 && compGuess == 2 || userGuess == 1 && compGuess == 0 || userGuess == 2 && compGuess == 1)
    {
        std::cout << "You chose: " << variants[userGuess] << "\t" << "The computer chose: " << variants[compGuess] << "\n";
        std::cout << "You won!\n";
    }
    else if (userGuess == 0 && compGuess == 0 || userGuess == 1 && compGuess == 1 || userGuess == 2 && compGuess == 2)
    {
        std::cout << "You chose: " << variants[userGuess] << "\t" << "The computer chose: " << variants[compGuess] << "\n";
        std::cout << "Draw!\n";
    }
    else
    {
        std::cout << "You chose: " << variants[userGuess] << "\t" << "The computer chose: " << variants[compGuess] << "\n";
        std::cout << "You lost!\n";
    }
}
