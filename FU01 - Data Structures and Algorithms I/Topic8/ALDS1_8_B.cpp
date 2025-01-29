#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
// Jimmy - s1312004
// ALDS1_8_B
using namespace std;

const int N = 2e5 + 5;

#define pb push_back

struct Node
{
    int u;
    Node *l;
    Node *r;
};

Node *makeNode(int v);
Node *insertNode(Node *pRoot, int v);
void preOrder(Node *pRoot);
void inOrder(Node *pRoot);
Node *find(Node *pRoot, int v);

Node *makeNode(int v)
{

    // cap phat bo nho cho newNode
    Node *newNode = new Node();
    newNode->u = v;
    newNode->l = newNode->r = NULL;
    return newNode;
}

Node *insertNode(Node *pRoot, int v)
{

    // insert node v vao bst
    if (pRoot == NULL)
    {
        pRoot = makeNode(v);
        // cout << "Making " << pRoot->u << " root" << endl;
        return pRoot;
    }

    // insert node v theo case
    if (v <= pRoot->u)
    {
        pRoot->l = insertNode(pRoot->l, v);
        // cout << "Inserting " << v << " as " << pRoot->u << " left" << endl;
    }
    else
    {
        pRoot->r = insertNode(pRoot->r, v);
        // cout << "Inserting " << v << " as " << pRoot->u << " right" << endl;
    }

    return pRoot;
}

void preOrder(Node *pRoot)
{

    // chay theo pre-order: root -> left -> right
    cout << " " << pRoot->u;
    if (pRoot->l != NULL)
        preOrder(pRoot->l);
    if (pRoot->r != NULL)
        preOrder(pRoot->r);
}

void inOrder(Node *pRoot)
{

    // chay theo in-order: left -> root -> right
    if (pRoot->l != NULL)
        inOrder(pRoot->l);
    cout << " " << pRoot->u;
    if (pRoot->r != NULL)
        inOrder(pRoot->r);
}

Node *find(Node *pRoot, int v)
{

    // duyet theo traversal preOrder: root -> left -> right
    if (pRoot == NULL || pRoot->u == v)
    {
        return pRoot;
    }

    if (v > pRoot->u)
        return find(pRoot->r, v);
    return find(pRoot->l, v);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, v, k;
    Node *root = NULL;

    cin >> t;
    for (int i = 0; i < t; i++)
    {

        char cmd[N];
        cin >> cmd;
        if (strcmp(cmd, "insert") == 0)
        {

            cin >> v;
            root = insertNode(root, v);
            // cout << "Inserting " << v << " into the tree" << endl;
        }
        else if (strcmp(cmd, "find") == 0)
        {

            cin >> k;

            if (find(root, k) == NULL)
                cout << "no" << endl;
            else
                cout << "yes" << endl;
        }
        else if (strcmp(cmd, "print") == 0)
        {

            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}