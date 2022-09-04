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

int leaf(BiTree &T) {
    if (!T)
        return 0;
    if (!T->lChild && !T->rChild)
        return 1;
    return leaf(T->lChild) + leaf(T->rChild);
} 

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    int n; 
    while (cin >> n) {
        BiTree T = NULL;
        while (n--) {
            int num;
            cin >> num;
            create(T, num);
        }
        preOrder(T);
        cout << endl;
        inOrder(T);
        cout << endl;   
        postOrder(T);
        cout << endl;
    }


    return 0;
}
