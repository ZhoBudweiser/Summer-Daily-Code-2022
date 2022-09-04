#include <bits/stdc++.h>
using namespace std;

void getNext(string pattern, vector<int>& match) {
    int n = match.size();
    match[0] = -1;
    for (int j = 1; j < n; j++) {
        int i = match[j-1];
        while ((i >= 0) && pattern[i+1] != pattern[j]) {
            i = match[i];
        }
        if (pattern[i+1] == pattern[j]) {
            match[j] = i+1;
        } else {
            match[j] = -1;
        }
    }
}

void Kmp(string text, string pattern, vector<int>& match) {
    int i = 0, j = 0;
    int m = text.size(), n = pattern.size();

    while (i < m) {
        while (i < m && j < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = match[j-1] + 1;
            } else {
                i++;
            }
        }
        if (j == n) {
            cout << i - n + 1 << endl;
            i--;
            j = 0;
        }
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    string text, pattern;
    while (cin >> text >> pattern) {
        int m = text.size();
        int n = pattern.size();
        vector<int> match(n, -1);
        getNext(pattern, match);
        Kmp(text, pattern, match);
        for (int i = 0; i < n; i++) {
            cout << match[i] + 1<< " ";
        }
        cout << endl;
    }

    return 0;
}