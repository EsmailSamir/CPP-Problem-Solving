#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../som3aLib.h"
using namespace std;
enum enChoice
{
    rock = 1,
    paper = 2,
    scissor = 3
};
short userChoice()
{
    short user;
    cout << "Enter Your Choice: \n"
         << "(1)rock ,(2)paper ,(3)scissor: ";
    cin >> user;
    return validation(user, 1, 3);
}
short computerChoice()
{
    return limitsOfRandom(1, 3);
}
string resultOfChoice(short numberOfChoice)
{
    switch (enChoice(numberOfChoice))
    {
    case enChoice::rock:
        return "Rock";
    case enChoice::paper:
        return "Paper";
    default:
        return "Scissor";
    }
}
string printResultOfRound(
    const short user, const short computer,
    short &equal, short &user_c, short &computer_c)
{
    if ((user == enChoice::rock && computer == enChoice::rock) ||
        (user == enChoice::paper && computer == enChoice::paper) ||
        (user == enChoice::scissor && computer == enChoice::scissor))
    {
        system("color 8F");
        equal++;
        return "Round Is Equal";
    }
    else if ((user == enChoice::rock && computer == enChoice::scissor) ||
             (user == enChoice::paper && computer == enChoice::rock) ||
             (user == enChoice::scissor && computer == enChoice::paper))
    {
        system("color 2F");
        user_c++;
        return "User Is Win Round";
    }
    else
    {
        system("color 4F");
        computer_c++;
        return "Computer Is Win Round\a";
    }
}
void printGameOver(const short user_c,
                   const short computer_c, const short equal)
{
    cout << "\nTotal Of Rounds: \n"
         << "User: " << user_c << "\nComputer: " << computer_c
         << "\nEqual: " << equal << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    bool again;
    do
    {
        short round = readNumber(1, 10),
              equal = 0, user_c = 0, computer_c = 0;
        for (short i = 1; i <= round; i++)
        {
            system("color 07");
            cout << "\n____________Round: " << i << " _____________\n";
            short user = userChoice(),
                  computer = computerChoice();
            cout << "=================================\n"
                 << "Your  Choice  Is    : " << resultOfChoice(user)
                 << "\nComputer Choice Is: " << resultOfChoice(computer)
                 << "\n\n"
                 << printResultOfRound(user, computer, equal, user_c, computer_c)
                 << "\n===============================================\n";
            Sleep(500);
        }
        system("color 07");
        printGameOver(user_c, computer_c, equal);
        cout << "\n===============================================\n"
             << "Do you Want To Play More:\n"
             << "(0)NO, (1)YES : ";
        cin >> again;
        validation(again, 0, 1);
    } while (again);
    return 0;
}