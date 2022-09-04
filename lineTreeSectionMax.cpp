#include <bits/stdc++.h>
using namespace std;
//区间更新，求区间和， 最大值
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;
const int maxn = 200000 + 5;
ll tree[maxn << 2];//定义线段树结点
ll lazy[maxn <<2];//懒惰标记
int arr[maxn];//输入的数据
ll ans;//答案
int n, m;

//向上合并
void Push_Up(int x)
{
    tree[x] = max(tree[lson], tree[rson]);
}

//向下传递lazy标记
void Push_Down(int x, int l, int r)
{
    if (lazy[x]) {
        int mid = (l+r) / 2;
        lazy[lson] += lazy[x];
        lazy[rson] += lazy[x];
        tree[lson] += lazy[x];
        tree[rson] += lazy[x];
        lazy[x] = 0;
    }
}

//创建一颗线段树
void Create(int x, int l, int r)
{
    lazy[x] = 0;
    if (l >= r) {
        tree[x] = arr[l];
        return;
    }
    int mid = (l+r) / 2;
    Create(lson, l, mid);
    Create(rson, mid+1, r);
    Push_Up(x);
}

//将pos点的值更新为val
void Update(int x, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {
        tree[x] = val;
        lazy[x] = val;
        return;
    }
    Push_Down(x, l, r);
    int mid = (l + r) / 2;
    if (L <= mid) Update(lson, l, mid, L, R, val);
    if (R > mid) Update(rson, mid+1, r, L, R, val);
    Push_Up(x);
}

//将pos点的值增加val
void Add(int x, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {
        tree[x] += val;
        lazy[x] += val;
        return;
    }
    Push_Down(x, l, r);
    int mid = (l + r) / 2;
    if (L <= mid) Add(lson, l, mid, L, R, val);
    if (R > mid) Add(rson, mid+1, r, L, R, val);
    Push_Up(x);
}

//查询区间[L, R]之间所有值的累加和
void Query(int x, int l, int r, int L, int R)
{
    if (L <= l && r <= R) {
        ans = max(ans, tree[x]);
        return;
    }
    Push_Down(x, l, r);
    int mid = (l + r) / 2;
    if (L <= mid) Query(lson, l, mid, L, R);
    if (R > mid) Query(rson, mid+1, r, L, R);
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        Create(1, 1, n);
        while (m--) {
            ans = INT64_MIN;
            char ch[10];
            int a, b, x;
            scanf("%s", ch);
            if (ch[0] == 'U')  //只判断第一个字符速度更快
            {
                scanf("%d%d%d", &a, &b, &x);
                Update(1, 1, n, a, b, x);
            } else if (ch[0] == 'A') {
                scanf("%d%d%d", &a, &b, &x);
                Add(1, 1, n, a, b, x);
            } else if (ch[0] == 'S') {
                scanf("%d%d%d", &a, &b, &x);
                Add(1, 1, n, a, b, -x);//减去一个数就是加上相反数
            } else {
                scanf("%d%d", &a, &b);
                Query(1, 1, n, a, b);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}