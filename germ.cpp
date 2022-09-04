# include<iostream>
using namespace std;

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int N;
    while (cin >> N) {
        while (N--) {
            int days;
            cin >> days;
            cout << (2 * days * days - 2 * days + 1) << endl;
        }
    }
    return 0;
}