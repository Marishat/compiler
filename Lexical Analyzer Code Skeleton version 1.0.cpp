#include <iostream>
using namespace std;

int main()
{
    string equation;

    cout << "Enter your equation: ";
    getline(cin, equation);

    for (int i = 0; i < equation.length(); i++)
    {

        if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '=')
        {
            cout << endl;
            cout << equation[i] << endl;
        }
        else if (equation[i] == ' ')
        {

            continue;
        }
        else
        {

            cout << equation[i];
        }
    }

    return 0;
}
