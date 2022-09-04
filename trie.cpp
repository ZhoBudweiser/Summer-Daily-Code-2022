# include<iostream>
# include<queue>
using namespace std;

const int maxn = 26;
typedef struct Node {
    int count;
    struct Node *next[maxn];
} *TrieTree;

void initTrie(TrieTree &T) {
    T->count = 1;
    for (int i = 0; i < maxn; i++) {
        T->next[i] = NULL;
    }
}

void create(TrieTree T, string s) {
    TrieTree p = T;
    if (!p) return;
    for (char ch : s) {
        int pos = ch - 'a';
        if (p->next[pos] == NULL) {
            TrieTree q = new Node;
            initTrie(q);
            p->next[pos] = q;
            p = q;
        } else {
            p->next[pos]->count++;
            p = p->next[pos];
        }
    }
}

int find(TrieTree T) {
    int num = 0;
    queue<TrieTree> q;
    q.push(T);
    while (!q.empty()) {
        TrieTree p = q.front();
        q.pop();
        bool isSon = true;
        for (int i = 0; i < maxn; i++) {
            if (p->next[i]) {
                q.push(p->next[i]);
                isSon = false;
            }
        }
        if (isSon) {
            num++;
        }
    }

    return num;
}

int main() {

    ios::sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n;
    while (cin >> n) {
        if (0 == n) break;
        TrieTree root = new Node;
        initTrie(root);
        while (n--) {
            string s;
            cin >> s;
            create(root, s);
        }
        cout << find(root) << endl;
    }


    return 0;
}
