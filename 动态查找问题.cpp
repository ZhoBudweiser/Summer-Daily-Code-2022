# include<iostream>
# include<map>
# include <algorithm>
using namespace std;

map<int, int> m;

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            m[a]++;
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int a;
            cin >> a;
            if (m[a] == 0) {
                cout << "no" << endl;
                m[a]++;
            }
            else {
                cout << "find" << endl;
            }
        }
    }
    return 0;
}