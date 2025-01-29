#include <bits/stdc++.h>
#include <cstring>
// ALDS1_8_C
// Jimmy - s1312004
using namespace std;

struct Node
{
    int u;
    Node *l;
    Node *r;
};

Node *makeNode(int v);
Node *insertNode(Node *pRoot, int v);
void inOrder(Node *pRoot);
void preOrder(Node *pRoot);
Node *findNode(Node *pRoot, int v);
Node *deleteNode(Node *pRoot, int v);

Node *makeNode(int v)
{
    Node *newNode = new Node();
    newNode->u = v;
    newNode->l = newNode->r = NULL;
    return newNode;
}

Node *insertNode(Node *pRoot, int v)
{
    // no root
    if (pRoot == NULL)
    {
        pRoot = makeNode(v);
        return pRoot;
    }

    // insert
    if (v <= pRoot->u)
    {
        pRoot->l = insertNode(pRoot->l, v);
    }
    else
    {
        pRoot->r = insertNode(pRoot->r, v);
    }

    return pRoot;
}

void inOrder(Node *pRoot)
{
    // inOrder: left -> root -> right

    if (pRoot->l != NULL)
        inOrder(pRoot->l);
    cout << " " << pRoot->u;
    if (pRoot->r != NULL)
        inOrder(pRoot->r);
}

void preOrder(Node *pRoot)
{
    // preOrder: root -> left -> right

    cout << " " << pRoot->u;
    if (pRoot->l != NULL)
        preOrder(pRoot->l);
    if (pRoot->r != NULL)
        preOrder(pRoot->r);
}

Node *findNode(Node *pRoot, int v)
{
    // duyet theo traversal preOrder: root -> left -> right
    if (pRoot == NULL || pRoot->u == v)
    {
        return pRoot;
    }

    if (v > pRoot->u)
        return findNode(pRoot->r, v);
    return findNode(pRoot->l, v);
}

Node *deleteNode(Node *pRoot, int v)
{
    // no root case;
    if (pRoot == NULL)
    {
        return pRoot;
    }

    if (v < pRoot->u)
    {
        pRoot->l = deleteNode(pRoot->l, v);
        return pRoot;
    }
    else if (v > pRoot->u)
    {
        pRoot->r = deleteNode(pRoot->r, v);
        return pRoot;
    }

    // delete Root itself
    // one-child and no-child node
    if (pRoot->l == NULL)
    {
        Node *p = pRoot->r;
        delete pRoot;
        return p;
    }
    else if (pRoot->r == NULL)
    {
        Node *p = pRoot->l;
        delete pRoot;
        return p;
    }

    // 2-children node -> swap with sucessor and delete (nho nhat trong rightsubtree)
    Node *sParent = pRoot;
    Node *s = pRoot->r;
    while (s->l != NULL)
    {
        sParent = s;
        s = s->l;
    }

    // swap key of sucessor and deletenode
    pRoot->u = s->u;

    // delete the sucessor
    if (sParent->l == s)
    {
        sParent->l = s->r;
    }
    else
    {
        sParent->r = s->r;
    }

    delete s;
    return pRoot;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t, k;
    Node *root = NULL;
    char cmd[50];
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> cmd;
        if (strcmp(cmd, "insert") == 0)
        {

            cin >> k;
            root = insertNode(root, k);
        }
        else if (strcmp(cmd, "find") == 0)
        {

            cin >> k;
            if (findNode(root, k) != NULL)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (strcmp(cmd, "delete") == 0)
        {

            cin >> k;
            root = deleteNode(root, k);
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