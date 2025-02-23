#include <iostream>
#include <cstdlib>
#include <vector>
#include <windows.h>

int randomizeGuess();
int enterUserGuess(std::vector <std::string> variants);
void calcResultGame(int userGuess, int compGuess, std::vector <std::string> variants);

int main()
{
    //кодировку на кириллицу переключаем
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //----------------------------------
    int userGuess(0), compGuess(0);
    std::vector <std::string> variants {"Ножницы", "Камень", "Бумага"};
    srand(time(0));
    compGuess = randomizeGuess();
    userGuess = enterUserGuess(variants);
    calcResultGame(userGuess, compGuess, variants);
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
    std::cout << "Варианты: \n";
    for (int i = 0; i < size(variants); i++)
    {
        std::cout << i + 1 << ": " << variants[i] << "\n";
    }
    std::cout << "Введите свой выбор: ";
    std::cin >> userGuess;
    return userGuess - 1;
}

void calcResultGame(int userGuess, int compGuess, std::vector <std::string> variants)
{
    if (userGuess == 0 && compGuess == 2 || userGuess == 1 && compGuess == 0 || userGuess == 2 && compGuess == 1)
    {
        std::cout << "Ты выбрал: " << variants[userGuess] << "\t" << "Компьютер выбрал: " << variants[compGuess] << "\n";
        std::cout << "Ты выйграл!";
    }
    else if (userGuess == 0 && compGuess == 0 || userGuess == 1 && compGuess == 1 || userGuess == 2 && compGuess == 2)
    {
        std::cout << "Ты выбрал: " << variants[userGuess] << "\t" << "Компьютер выбрал: " << variants[compGuess] << "\n";
        std::cout << "Ничья!";
    }
    else
    {
        std::cout << "Ты выбрал: " << variants[userGuess] << "\t" << "Компьютер выбрал: " << variants[compGuess] << "\n";
        std::cout << "Ты проиграл!";
    }
}