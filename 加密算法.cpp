# include<iostream>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if ('A'<=s[i] && s[i]<='Z') {
                s[i] = (s[i]-'A' + 3) % 26 + 'A';
            } else if ('a'<=s[i] && s[i]<='z') {
                s[i] = (s[i]-'a' + 3) % 26 + 'a';
            }
        }
        cout << s << endl;
    }

    return 0;
}