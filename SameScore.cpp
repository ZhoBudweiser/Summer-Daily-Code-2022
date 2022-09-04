# include<iostream>
using namespace std;



int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int n;
    while (cin >> n) {
        if (0 == n) {
            break;
        }
        int scores[1005] = {0};
        while (n--) {
            int num;
            cin >> num;
            scores[num]++;
        }
        int sNum;
        cin >> sNum;
        cout << scores[sNum] << endl;
    }

    return 0;
}
