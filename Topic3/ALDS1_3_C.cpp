//ALDS1_3_C
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

struct Tnode
{
    Tnode *next;
    Tnode *prev;
    int val;
    Tnode(int v, Tnode *n = nullptr, Tnode *p = nullptr) : val(v), next(n), prev(p) {}
};
string isNull(Tnode *head) { return head == nullptr ? "nullptr" : "ptr"; }
struct Tdlist
{
    Tnode *head;
    Tnode *tail;
    Tdlist() : head(nullptr), tail(nullptr) {}

    void Insert(int u)
    {
        if (head == nullptr)
        {
            head = new Tnode(u, nullptr, nullptr);
            tail = head;
        }
        else
        {
            auto tmp = new Tnode(u, head, nullptr);
            head->prev = tmp;
            head = tmp;
        }
    }
    void Delete(int u)
    {
        if (head == nullptr)
            return;
        Tnode *cur = head;
        while (cur != nullptr)
        {
            if (cur->val == u)
            {
                if (cur->prev == nullptr)
                {
                    head = cur->next;
                    head->prev = nullptr;
                    delete cur;
                    return;
                }
                else if (cur->next == nullptr)
                {
                    tail = cur->prev;
                    tail->next = nullptr;
                    delete cur;
                    return;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                    return;
                }
            }
            cur = cur->next;
        }
    }
    void deleteLast()
    {
        if (tail == nullptr)
            return;
        auto tmp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete tmp;
    }
    void deleteFirst()
    {
        if (head == nullptr)
            return;
        auto tmp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete tmp;
    }
    void print()
    {
        Tnode *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->val;
            tmp = tmp->next;
            if (tmp != nullptr)
                cout << " ";
        }
        cout << "\n";
        // if(tail!=nullptr)cout<<"tail:"<<tail->val<<"\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Tdlist dlist;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int u;
            cin >> u;
            dlist.Insert(u);
        }
        else if (s == "delete")
        {
            int u;
            cin >> u;
            dlist.Delete(u);
        }
        else if (s == "deleteFirst")
        {
            dlist.deleteFirst();
        }
        else if (s == "deleteLast")
        {
            dlist.deleteLast();
        }
        // dlist.print();
    }
    dlist.print();
    return 0;
}