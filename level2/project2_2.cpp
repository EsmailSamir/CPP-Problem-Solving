#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
enum enLevel
{
    easy = 1,
    mid = 2,
    hard = 3,
    mixLevel = 4
};
enum enType
{
    sum = 1,
    sup = 2,
    mul = 3,
    div = 4,
    mixType = 5
};
struct stGameInfo
{
    short resultOfRound;
    short resultOfAllGame;
    string finallResult;
};
struct stUserInfo
{
    short howManyWin;
    short howManyLose;
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
short userChoiceLevel()
{
    short gameLevel;
    cout << "What Level Do You Want: \n"
         << "(1)Easy ,(2)Mid ,(3)hard, (4)Mix: ";
    cin >> gameLevel;
    while (cin.fail() || cin.peek() != '\n' || gameLevel < 1 || 4 < gameLevel)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "What Level Do You Want: \n"
             << "(1)Easy ,(2)Mid ,(3)hard, (4)Mix: ";
        cin >> gameLevel;
    }
    return gameLevel;
}
string ChoiceForLevel(short gameLevel)
{
    switch (enLevel(gameLevel))
    {
    case enLevel::easy:
        return "easy";
    case enLevel::mid:
        return "mid";
    case enLevel::hard:
        return "hard";
    default:
        return "mix";
    }
}
short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
}

short userChoiceType()
{
    short gameType;
    cout << "What Level Do You Want: \n"
         << "(1)Sum ,(2)Sup ,(3)Mul ,(4)Div ,(5)Mix : ";
    cin >> gameType;
    while (cin.fail() || cin.peek() != '\n' || gameType < 1 || 5 < gameType)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "What Level Do You Want: \n"
             << "(1)Sum ,(2)Sup ,(3)Mul ,(4)Div ,(5)Mix : ";
        cin >> gameType;
    }
    return gameType;
}
char ChoiceForType(short gameType)
{
    switch (enType(gameType))
    {
    case enType::sum:
        return '+';
    case enType::sup:
        return '-';
    case enType::mul:
        return '*';
    case enType::div:
        return '/';
    default:
        'mix';
    }
}

short choiseNumberForLevel(short gameLevel)
{
    switch (gameLevel)
    {
    case enLevel::easy:
        return limitsOfRandom(1, 10);
    case enLevel::mid:
        return limitsOfRandom(10, 50);
    case enLevel::hard:
        return limitsOfRandom(50, 100);
    default:
        return limitsOfRandom(1, 100);
    }
}
short doingOperator(short gameType)
{
    switch (gameType)
    {
    case enType::sum:
        return choiseNumberForLevel(gameType)+ choiseNumberForLevel(gameType);
    case enType::sup:
        return choiseNumberForLevel(gameType)- choiseNumberForLevel(gameType);
    case enType::mul:
        return choiseNumberForLevel(gameType)* choiseNumberForLevel(gameType);
    case enType::div:
        return choiseNumberForLevel(gameType)/ choiseNumberForLevel(gameType);
    default:
        return choiseNumberForLevel(gameType) choiseNumberForLevel(gameType);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    
    return 0;
}