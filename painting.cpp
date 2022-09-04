#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> wall(200001, 0);

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
	
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        wall[a]++;
        wall[b+1]--;
    }
    for (int i = 1; i <= 200001; i++) {
        wall[i] += wall[i-1];
    }
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        for (int i = a; i <= b; i++) {
            cout << wall[i] << endl;
        }
    }
	return 0;

}