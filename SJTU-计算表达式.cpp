# include <iostream>
# include <stack>
# include <cstdio>
# include <cctype>
using namespace std;

int pri(char ch)
{
    switch (ch)
    {
        case '#':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
    
}

int getNum(string& str, int& index)
{
    int res = 0;
    while (isdigit(str[index]))
    {
        res = res * 10 + str[index] - '0';
        index++;
    }
    return res;
}

int cal(int x, int y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
    }
    
    return -1;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "0")
        {
            break;
        }
        int index = 0;
        stack<char> sOP;
        stack<int> sNum;
        str += "#";
        sOP.push('#');
        
        while (!(str[index] == '#' && sOP.top() == '#'))
        {
            if (isdigit(str[index]))
            {
                sNum.push(getNum(str, index));
            }
            else
            {
                if (pri(str[index]) > pri(sOP.top()))
                {
                    sOP.push(str[index]);
                    index++;
                }
                else
                {
                    int y = sNum.top();
                    sNum.pop();
                    int x = sNum.top();
                    sNum.pop();
                    char op = sOP.top();
                    sOP.pop();
                    int res = cal(x, y, op);
                    sNum.push(res);
                }
            }
            cout << "OP : " << sOP.top() << endl;
			cout << "Num : " << sNum.top() << endl; 
        }
        printf("%d\n", sNum.top());
        
    }
    
    return 0;
}
