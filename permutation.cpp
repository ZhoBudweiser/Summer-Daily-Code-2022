# include<iostream>
# include <algorithm>
using namespace std;

string s;
int ans[10];
bool visit[10];

void permutation(int m) {
    if (m == s.size()) {
        for (int i = 0; i < m; i++) {
            cout << s[ans[i]];
        }
        cout << endl;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            ans[m] = i;
            permutation(m+1);
            visit[i] = false;            
        }
    }
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    while (cin >> s) {
        sort(s.begin(), s.end());
        // permutation(0);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));
    }

    return 0;
}
