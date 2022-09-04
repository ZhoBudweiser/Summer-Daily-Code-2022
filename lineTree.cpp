#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000+5;
int tree[maxn << 2]; //定义线段树结点
int arry[maxn];//输入的数据
int ans;
int n,m;

#define lson x << 1
#define rson (x << 1) + 1


//向上合并
void Push_Up(int x){
    tree[x] = tree[lson] + tree[rson];
}

//创建一颗线段树
void Create(int x, int l, int r){
    if (l >= r) {
        tree[x] = arry[l];
        return;
    }
    int mid = (l+r) >> 1;
    Create(lson, l, mid);
    Create(rson, mid+1, r);
    Push_Up(x);
}

//将pos点的值更新为val
void Update(int x, int l, int r, int pos, int val){
    if (l >= r) {
        tree[x] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos) Update(lson, l, mid, pos, val);
    else Update(rson, mid+1, r, pos, val);
    Push_Up(x);
}

//将 pos点的值增加val
void Add(int x, int l, int r, int pos, int val){
    if (l >= r) {
        tree[x] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos) Add(lson, l, mid, pos, val);
    else Add(rson, mid+1, r, pos, val);
    Push_Up(x);
}

//查询[L,R]区间所有值的累加
void Query(int x, int l, int r, int L, int R){
    if (L <= l && r <= R) {
        ans += tree[x];
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= L) Query(lson, l, mid, L, R);
    if (R > mid) Query(rson, mid+1, r, L, R);
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    while(cin>>n>>m){
        for(int i = 1; i <=n; i++) cin>>arry[i];
        Create(1,1,n);
        while(m--){
            string op;
            int a,b;
            cin>>op>>a>>b;

            if(op == "Query"){
                ans = 0;
                Query(1,1,n,a,b);
                cout<<ans<<endl;
            }
            else if(op == "Add"){
                Add(1,1,n,a,b);
            }
            else if (op == "Update"){
                Update(1,1,n,a,b);
            }
            else if (op == "Sub"){
                Add(1,1,n,a,-1*b);
            }
        }
    }

    return 0;
}