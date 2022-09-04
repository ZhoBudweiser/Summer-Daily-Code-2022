# include<iostream>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    string s;
    while (cin >> s) {
        int i = 1;
        while (i*2-1<=s.size()) {
            int a = i-1;
            int b = i*2-2;
            while (a < b) {
                if ((s[a] != '#' && s[b] == '#') || (s[a] == '#' && s[b] != '#')) {
                    break;
                }
                a++;
                b--;
            }
            if (a < b) {
                break;
            }
            i <<= 1;
        }
        if (i*2-1<=s.size()) {
            cout << "NO" << endl;
        } else if (i-1 != s.size()){
            int j;
            for (j = i-1; j < s.size(); j++) {
                if (s[j] != '#') {
                    cout << "NO" << endl;
                    break;
                    
                }
            }
            if (j >= s.size()) {
                cout << "YES" << endl;
            }
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
