#include<iostream>
#include<cstring>
#include<exception>
#include<cstdlib>
using namespace std;
bool check(int ch, char ch1[][12], int size);
void display(char XO[][12], int size)
{
    cout << "Player(1)= \"X\" \nPlayer(2)= \"O\"" << endl << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << XO[i][j];
        }
        cout << endl;
    }
}
void Edit(char XO[][12], int size, int choice, int& x, char& ch)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if ((i == 0 || i == 2 || i == 4) && (j == 1 || j == 5 || j == 9))
            {
                if (!check(choice, XO, size))
                {
                    cout << ">>>  Invalid, there is a value at this position. <<<" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                else if ((XO[i][j] == char(choice + 48)) && (x == 0 || x == 2 || x == 4 || x == 6 || x == 8))
                {
                    XO[i][j] = 'X';
                    ch = 'X';
                    x++;
                    return;
                }
                else if ((XO[i][j] == char(choice + 48)) && (x == 1 || x == 3 || x == 5 || x == 7 || x == 9))
                {
                    XO[i][j] = 'O';
                    ch = 'O';
                    x++;
                    return;
                }
            }
        }
    }
}
bool Rules(char XO[][12])
{
    if ((XO[0][1] == 'X' && XO[0][5] == 'X' && XO[0][9] == 'X') ||
        (XO[0][1] == 'O' && XO[0][5] == 'O' && XO[0][9] == 'O') ||

        (XO[2][1] == 'X' && XO[2][5] == 'X' && XO[2][9] == 'X') ||
        (XO[2][1] == 'O' && XO[2][5] == 'O' && XO[2][9] == 'O') ||

        (XO[4][1] == 'X' && XO[4][5] == 'X' && XO[4][9] == 'X') ||
        (XO[4][1] == 'O' && XO[4][5] == 'O' && XO[4][9] == 'O') ||

        (XO[0][1] == 'X' && XO[2][1] == 'X' && XO[4][1] == 'X') ||
        (XO[0][1] == 'O' && XO[2][1] == 'O' && XO[4][1] == 'O') ||

        (XO[0][5] == 'X' && XO[2][5] == 'X' && XO[4][5] == 'X') ||
        (XO[0][5] == 'O' && XO[2][5] == 'O' && XO[4][5] == 'O') ||

        (XO[0][9] == 'X' && XO[2][9] == 'X' && XO[4][9] == 'X') ||
        (XO[0][9] == 'O' && XO[2][9] == 'O' && XO[4][9] == 'O') ||

        (XO[0][1] == 'X' && XO[2][5] == 'X' && XO[4][9] == 'X') ||
        (XO[0][1] == 'O' && XO[2][5] == 'O' && XO[4][9] == 'O') ||

        (XO[4][1] == 'X' && XO[2][5] == 'X' && XO[0][9] == 'X') ||
        (XO[4][1] == 'O' && XO[2][5] == 'O' && XO[0][9] == 'O'))
    {
        return true;
    }
    else
        return false;
}
bool check(int choice, char XO[][12], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 12;)
        {
            if (XO[i][j] == char(choice + 48))
                return true;
            else
            {
                j++;
            }
        }
    }
    return false;
}
int main()
{
    int i = 0;
    char ch;
    int choice;
    char XO[5][12] = { " 1 | 2 | 3 ",
                    "---|---|---",
                    " 4 | 5 | 6 ",
                    "---|---|---",
                    " 7 | 8 | 9 " };
    do
    {
        display(XO, 5);
        while (!(cin >> choice))
        {
            cout << "Enter an integer number: " << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }

        if (char(choice + 48) < 49 || char(choice + 48) > 57)
        {
            cout << ">>> (Invalid input) <<<" << endl << endl;
            system("pause");
            system("cls");
        }
        else
        {
            if (!Rules(XO))
            {
                system("cls");
                Edit(XO, 5, choice, i, ch);

                if (i > 8)
                {
                    cout << ">>> (No one wins) <<<" << endl;
                    return 0;
                }

                if (Rules(XO))
                {
                    if (ch == 'X')
                        cout << "Player(1) Wins !!" << endl;
                    else if (ch == 'O')
                        cout << "Player(2) Wins !!" << endl;

                    return 0;
                }
            }
        }
    } while (i <= 8);
}
