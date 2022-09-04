# include<iostream>
# include<queue> 
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    freopen("1.error","w",stderr);
    
    int n, m;
    while (cin >> m >> n) {
        queue<int> s;
        int cnt = 0;
        if (m <= n) {
        	s.push(m);
        	cnt++;
		}        	
        while (true) {
        	int top = s.front();
        	s.pop();
        	if (top * 2 <= n) {
        		s.push(top*2);
        		cnt++;
			}
        	else break;
        	if (top * 2 + 1 <= n) {
        		s.push(top*2+1);
        		cnt++;
			}
        	else break;
		}
		cout << cnt << endl;
	}

    return 0;
}
