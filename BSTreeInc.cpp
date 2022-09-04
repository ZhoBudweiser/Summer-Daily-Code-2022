# include<iostream>
using namespace std;

typedef struct node{
    int val;
    node* lChild;
    node* rChild;
} *BiTree;

void create(BiTree &T, int x, BiTree pT) {
    if (!T) {
        T = new node;
        T->val = x;
        if (pT) cout << pT->val << endl;
        else cout << -1 << endl;
        T->lChild = NULL;
        T->rChild = NULL;
        return;
    }
    if (x == T->val) {
        return;
    }
    if (x < T->val) {
        create(T->lChild, x, T);
    }
    if (x > T->val) {
        create(T->rChild, x, T);
    }
}

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n; 
    while (cin >> n) {
        BiTree T = NULL;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            create(T, num, NULL);
        }
    }
    return 0;
}
