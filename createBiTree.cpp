# include<iostream>
using namespace std;

typedef struct node {
	char val;
	node *l, *r;
} *BiTree, BiNode;

void create(BiTree &T, string s1, string s2) {
	if (s1 != "") {
		T = new BiNode;
		T->val = s1[0];
		int index = s2.find(T->val);
		create(T->l, s1.substr(1, index), s2.substr(0, index));
		create(T->r, s1.substr(1+index), s2.substr(1+index));
	}else {
		T = NULL;
	}
}

void postOrder(BiTree &T) {
	if (T) {
		postOrder(T->l);
		postOrder(T->r);
		cout << T->val;		
	}
}

int main() {

    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    
    string pre, post;
    while (cin >> pre >> post) {
    	BiTree T;
		create(T, pre, post);
		postOrder(T);
		cout << endl;
	}

    return 0;
}
