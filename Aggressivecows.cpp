#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
int N, C;
int a[maxn];

bool judge(int x){
    int cnt = 1;
    int last = a[0];

    for (int i = 1; i < N; i++) {
        if (a[i] - last >= x) {
            last = a[i];
            cnt++;
        }
        if (cnt >= C) return true;
    }

    return false;
}

int main(){

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while(cin >> N >> C){
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        int l = 1, r = a[N-1]-a[0];
        while (l < r) {
            int mid = (r+l+1) >> 1;
            if (judge(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}