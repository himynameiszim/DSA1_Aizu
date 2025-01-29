// ALDS1_7_A
// Jimmy - s1312004

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int parent = -1;
    // int leftMostChild = -1;
    // int rightSibling = -1;
    int numChild = 0;
    vector<int> child;
};

Node root;

// int getDepth(Node rootedTree[], int id, int depth = 0){
//     Node p = rootedTree[id];
//     if(p.parent == -1)
//         return depth;
//     for(Node k = p->parent; k != NULL; k = k.parent){
//         depth++;
//     }
//     return 0;
// }

int main()
{
    // freopen("sample.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, id, k, tmp;
    cin >> t;
    Node rootedTree[t];

    for (int i = 0; i < t; i++)
    {
        cin >> id >> k;
        rootedTree[id].numChild += k;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            rootedTree[tmp].parent = id;
            rootedTree[id].child.push_back(tmp);
        }
    }

    for (int i = 0; i < t; i++)
    {
        int depth = 0;
        vector<int>::iterator it;
        // depth = getDepth(rootedTree, i, depth);
        cout << "node " << i << ": parent = " << rootedTree[i].parent << ", depth = ";
        Node *p = &rootedTree[i];
        while (p->parent != -1)
        {
            depth++;
            p = &rootedTree[p->parent];
        }
        cout << depth << ", ";
        if (rootedTree[i].parent == -1)
            cout << "root, [";
        else if (rootedTree[i].parent >= 0 && rootedTree[i].numChild > 0)
            cout << "internal node, [";
        else if (rootedTree[i].parent >= 0 && rootedTree[i].numChild == 0)
            cout << "leaf, [";
        if (rootedTree[i].numChild == 0)
            cout << "]";
        else if (rootedTree[i].numChild == 1)
        {
            for (auto &it : rootedTree[i].child)
                cout << it << "]";
        }
        else if (rootedTree[i].numChild > 1)
        {
            auto it = rootedTree[i].child.begin();
            advance(it, rootedTree[i].child.size() - 1);
            for (vector<int>::iterator v = rootedTree[i].child.begin(); v != it; v++)
                cout << *v << ", ";
            cout << rootedTree[i].child.back() << "]";
        }
        cout << "\n";
    }
    return 0;
}