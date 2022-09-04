# include<bits/stdc++.h>
using namespace std;

struct Node
{
    int x;
    Node(int a) {x = a;}
};

bool operator< (const Node& a, const Node&b) {
    return a.x > b.x;
} 

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    priority_queue<Node> q;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        q.push(Node(x));
    }
    int ans = 0;
    while (q.size() > 1) {
        Node num1 = q.top();
        q.pop();
        Node num2 = q.top();
        q.pop();
        ans += num1.x + num2.x;
        q.push(Node(num1.x+num2.x));
    }
    cout << ans ;

    return 0;
}