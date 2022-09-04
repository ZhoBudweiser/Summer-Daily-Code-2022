#include <iostream>
using namespace std;

int main()
{
    long long sum;
    int a, n, item = 0;
    while (cin >> a >> n)
    {
        sum = 0;
        item = 0;
        do
        {
            item = item * 10 + a;
            sum += item;
            cout << item << "  " << sum << endl;
        } while (--n);

        cout << sum << endl;
    }

    return 0;
}