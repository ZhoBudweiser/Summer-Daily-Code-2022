# include<iostream>
# include <algorithm>
using namespace std;

int num[1005];

bool cmp (int a, int b) {
    if (a%2 == b%2) {
        return a < b;
    } else {
        return a % 2 > b % 2;
    }
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num, num+n, cmp);
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    return 0;
}