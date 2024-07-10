#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        string s;
        getline(cin, s);
        s = s + ";";
        int red = 0, blue = 0, green = 0, pre = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ':')
            {
                pre = i + 2;
                continue;
            }
            if (s[i] == ';')
            {
                int p = pre;
                while (p < i)
                {
                    int num = 0;
                    while (s[p] != ' ')
                    {
                        num *= 10;
                        num += s[p] - '0';
                        p++;
                    }
                    p++;
                    if (s[p] == 'r')
                        red = max(red, num);
                    if (s[p] == 'b')
                        blue = max(blue, num);
                    if (s[p] == 'g')
                        green = max(green, num);

                    while (s[p] != ';' && s[p] != ',')
                        p++;
                    p += 2;
                }

                pre = i + 2;
            }
        }
        ans += red * green * blue;
        cout << red << " " << green << " " << blue << endl;
    }
    cout << ans << endl;
}