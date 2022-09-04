# include<iostream>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        if (1== N || 2 == N) {
            cout << N << endl;
            continue;
        }
        long long a1 = 1, a2 = 2, a3;
        for (int i = 3; i <= N; i++) {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }
        cout << a3 << endl;
    }
    return 0;
}