# include<iostream>
using namespace std;

typedef struct node{
    int val;
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

void preOrder(BiTree &T) {
    if (T) {
        cout << T->val << " ";
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

void inOrder(BiTree &T) {
    if (T) {        
        inOrder(T->lChild);
        cout << T->val << " ";
        inOrder(T->rChild);
    }
}

void postOrder(BiTree &T) {
    if (T) {        
        postOrder(T->lChild);        
        postOrder(T->rChild);
        cout << T->val << " ";
    }
}

void drop(BiTree &T) {
    if (T) {
        drop(T->lChild);
        drop(T->rChild);
        delete T;
    }
}

bool isSame (BiTree &T1, BiTree &T2) {
    if (T1 && T2) {
        return isSame(T1->lChild, T2->lChild) && isSame(T1->rChild, T2->rChild) && T1->val == T2->val;
    } else if (!T1 && !T2) {
        return true;
    } else {
        return false;
    }
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
            BiTree T1 = NULL;
            cin >> s;
            for (int i = 0; i < s.size(); i++) {
                create(T1, s[i] - '0');
            }
            if (isSame(T, T1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            drop(T1);
        }
        drop(T);
    }


    return 0;
}
