#include <bits/stdc++.h>
#include <cstring>
// Jimmy - s1312004
// ALDS1_8_A
using namespace std;

const int N = 2e5 + 5;

struct Node
{
    int u;
    Node *l;
    Node *r;
};

Node *makeNode(int v);
Node *insert(Node *pRoot, int v);

Node *makeNode(int v)
{ // make new node

    Node *newNode = new Node();
    newNode->u = v;
    newNode->l = newNode->r = NULL;
    return newNode;
}

Node *insert(Node *pRoot, int v)
{

    if (pRoot == NULL)
    { // in case tree is empty
        pRoot = makeNode(v);
        // cout << "making " << pRoot->u << " root" << endl;
        return pRoot;
    }

    if (v <= pRoot->u)
    { // insert v with value comparison
        pRoot->l = insert(pRoot->l, v);
        // cout << "inserting " << v << " into " << pRoot->u << " left" << endl;
    }
    else
    {
        pRoot->r = insert(pRoot->r, v);
        // cout << "inserting " << v << " into " << pRoot->u << " right" << endl;
    }

    return pRoot;
}

void preOrder(Node *pRoot)
{

    // pre-order traversal: Root -> Left -> Right
    cout << " " << pRoot->u;
    if (pRoot->l != NULL)
        preOrder(pRoot->l);
    if (pRoot->r != NULL)
        preOrder(pRoot->r);
}

void inOrder(Node *pRoot)
{

    // in-order traversal: Left -> Root -> Right
    if (pRoot->l != NULL)
        inOrder(pRoot->l);
    cout << " " << pRoot->u;
    if (pRoot->r != NULL)
        inOrder(pRoot->r);
}

signed main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    Node *root = NULL;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        char s[N];
        cin >> s;

        if (strcmp(s, "insert") == 0)
        {

            int v;
            cin >> v;
            // insert() v into tree;
            root = insert(root, v);
        }
        else if (strcmp(s, "print") == 0)
        {

            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }

    return 0;
}