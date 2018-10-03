#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int v) : m_v(v), m_l(nullptr), m_r(nullptr){}
    int m_v;
    Node * m_l, *m_r;
};

Node * insertVal(int val, Node * curr) {
    if(curr == nullptr) return new Node(val);
    if(val < curr->m_v) curr->m_l = insertVal(val, curr->m_l);
    else curr->m_r = insertVal(val, curr->m_r);
    return curr;
}

bool equals(Node *a, Node *b) {
    if(a == nullptr && b == nullptr)  return true;
    if(a == nullptr || b == nullptr)  return false;
    return equals(a->m_l, b->m_l) && equals(a->m_r, b->m_r);
}

bool exist(vector<Node * > & trees, Node * root)
{
    for(auto & tree : trees)
        if(equals(tree, root) && equals(root, tree))
            return true;
    return false;
}

int main() {
    while(true)
    {
    int n,k;
        if(scanf("%d%d", &n, &k) != 2)
            break;
    vector<Node*> trees;

    for (int i = 0; i < n; ++i)
    {
        Node * root = nullptr;

        for (int j = 0; j < k; ++j)
        {
            int val;
            scanf("%d", &val);
            root = insertVal(val, root);
        }

        if(!exist(trees,root))
            trees.emplace_back(root);
    }

    printf("%d\n", (int)trees.size());

    }
    return 0;
}