#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
enum enChoice
{
    rock = 1,
    paper = 2,
    scissor = 3
};
short readRound()
{
    short round;
    cout << "Enter Round: ";
    cin >> round;
    while (cin.fail() || cin.peek() != '\n' || round < 1 || 10 < round)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [1, 10]\n"
             << "Enter Round: ";
        cin >> round;
    }
    return round;
}
short userChoice()
{
    short user;
    cout << "Enter Your Choice: \n"
         << "(1)rock ,(2)paper ,(3)scissor: ";
    cin >> user;
    while (cin.fail() || cin.peek() != '\n' || user < 1 || 3 < user)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter Your Choice: \n"
             << "(1)rock ,(2)paper ,(3)scissor: ";
        cin >> user;
    }
    return user;
}
short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
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
        short round = readRound(),
              equal = 0, user_c = 0, computer_c = 0;
        for (short i = 1; i <= round; i++)
        {
            system("color 07");
            cout << "\nRound: " << i << '\n';
            short user = userChoice(),
                  computer = computerChoice();
            cout << "=================================\n"
                 << "Your Choice Is : " << resultOfChoice(user)
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
        while (cin.fail() || cin.peek() != '\n' || again < 0 || 1 < again)
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "Do you Want To Play More:\n"
                 << "(0)NO, (1)YES : ";
            cin >> again;
        }
    } while (again);
    return 0;
}