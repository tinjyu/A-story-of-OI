#include <iostream>
#include <string>
using namespace std;
string s;
string t = "You are right, but ";
int main()
{
    getline(cin, s);
    int flag = 1;
    for (int i = 0; i < 19; i++)
    {
        if (s[i] != t[i])
            flag = 0;
    }
    if (flag == 1)
        cout << "AI" << endl;
    else
        cout << "Human" << endl;
}