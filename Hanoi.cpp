# include<iostream>
using namespace std;

int step = 1;

void Hanoi(int n, char src, char mid, char dst) {
    if (n == 1) {
        cout << src << "-->" << dst << "   ";
        if (step % 5 == 0) {
            cout << endl;
        }
        step++;
        return;
    }
    Hanoi(n-1, src, dst, mid);
    Hanoi(1, src, mid, dst);
    Hanoi(n-1, mid, src, dst);
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int n;
    while (cin >> n) {
        if (0 == n) {
            break;
        }
        step = 1;
        Hanoi(n, 'A', 'B', 'C');
        cout << endl;
    }

    return 0;
}
