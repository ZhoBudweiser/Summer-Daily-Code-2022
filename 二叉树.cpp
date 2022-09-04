# include<iostream>
# include<cmath> 
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    freopen("1.error","w",stderr);
    
    long long a, b;
    while (cin >> a >> b) {
        while(a!=b){
            if(a>b) a /= 2;
            else b /= 2;
        }
        cout<<a<<endl;
	}

    return 0;
}
