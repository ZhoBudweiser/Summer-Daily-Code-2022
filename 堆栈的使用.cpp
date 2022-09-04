# include <iostream>
# include <stack>
# include <cstdio>
using namespace std;

int main()
{
    string str;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            break;
        }
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            getline(cin,str);
            if (str == "A")
            {
                if (s.empty())
                {
                    cout << 'E' << endl;
                }
                else
                {
                    cout << s.top() << endl;
//                     cout << "!" << endl;
                }
            }
            else if (str == "O")
            {
                if (!s.empty())
                {
                    s.pop();
                }
            }
            else if (str[0] == 'P')
            {
                int num = 0;
                for (int j = 2; j < str.size(); j++)
                {
                    num = num * 10 + str[j] - '0';
                }
//                 cout << num << endl;
                s.push(num);
            }
//             cout << i << endl;
        }
        cout << endl;
    }
    
    return 0;
}