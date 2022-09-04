# include<iostream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string s1 = "", s2 = "";
        for (int i = 0; i < s.size(); i++) {
            if ('1'<=s[i] && s[i]<='9') {
                s1 += s[i];
            } else {
                s2 += s[i];
            }
        }
        s = s2+s1;
        cout << s << endl;
    }

    return 0;
}