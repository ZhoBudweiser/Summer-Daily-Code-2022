# include<iostream>
using namespace std;

typedef struct node{
    char val;
    node* lChild;
    node* rChild;
} *BiTree;

void create(BiTree &T) {
    char c;
    cin >> c;
    if (c == '#') {
        T = NULL;
        return;
    }
    T = new node;
    T->val = c;
    create(T->lChild);
    create(T->rChild); 
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
    
    BiTree T;
    create(T);
    inOrder(T); cout << endl;

    return 0;
}
