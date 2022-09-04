# include<iostream>
using namespace std;

typedef struct node{
    int val;
    bool tag;
    node* lChild;
    node* rChild;
} *BiTree;

void create(BiTree &T, int x) {
    if (!T) {
        T = new node;
        T->val = x;
        T->lChild = NULL;
        T->rChild = NULL;
        return;
    }
    if (x == T->val) {
        return;
    }
    if (x < T->val) {
        create(T->lChild, x);
    }
    if (x > T->val) {
        create(T->rChild, x);
    }
}

void reset(BiTree &T) {
    if (T) {
        reset(T->lChild);
        reset(T->rChild);
        T->tag = false;
    }
}

void drop(BiTree &T) {
    if (T) {
        drop(T->lChild);
        drop(T->rChild);
        delete T;
    }
}

bool check(BiTree T, int x) {
    if (T) {
        if (T->val == x) {
            T->tag = true;
            return true;
        }
        if (!T->tag) {
            return false;
        }
        T->tag = true;
        if (x > T->val)
            return check(T->rChild, x);
        else if (x < T->val)
            return check(T->lChild, x);
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n; 
    while (cin >> n) {
        BiTree T = NULL;
        if (0 == n) {
            break;
        }
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            create(T, s[i] - '0');
        }
        while (n--) {
            reset(T);
            bool flag = true;
            cin >> s;
            for (int i = 0; s[i]; i++) {
                if (!check(T, s[i] - '0')) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        drop(T);
    }


    return 0;
}
