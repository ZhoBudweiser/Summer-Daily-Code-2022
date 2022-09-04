#include <iostream>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int res=0;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'F') {
                res = res*16 + s[i]-'A'+10;
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                res = res*16 + s[i]-'a'+10;
            } else if (s[i] >= '0' && s[i] <= '9') {
                res = res*16 + s[i]-'0';
            }
        }
        cout << res << endl;
    }
    return 0;
}