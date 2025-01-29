// Jimmy - s1312004
// ALDS1_13_B

#include <iostream>
#include <queue>
#include <array>
#include <unordered_map>

using namespace std;

struct Tstate
{
    // array<int,9> arr;
    int p0;
    int encoded;
};

const Tstate invalid_state = {-1, -1};

const int N = 20;
int pw10[10];

unordered_map<int, int> pre;

int swap9digit(int n, int i, int j)
{
    int pi = (n / pw10[8 - i]) % 10;
    int pj = (n / pw10[8 - j]) % 10;
    n = n - pi * pw10[8 - i] - pj * pw10[8 - j] + pi * pw10[8 - j] + pj * pw10[8 - i];
    return n;
}

Tstate up(Tstate s)
{
    if (s.p0 < 3)
        return {-1, -1};
    s.encoded = swap9digit(s.encoded, s.p0, s.p0 - 3);
    s.p0 -= 3;
    return s;
}
Tstate down(Tstate s)
{

    if (s.p0 + 3 > 8)
        return {-1, -1};
    s.encoded = swap9digit(s.encoded, s.p0, s.p0 + 3);
    s.p0 += 3;
    return s;
}

Tstate right(Tstate s)
{
    if (s.p0 == 2 || s.p0 == 5 || s.p0 == 8)
        return {-1, -1};
    s.encoded = swap9digit(s.encoded, s.p0, s.p0 + 1);
    s.p0++;
    return s;
}

Tstate left(Tstate s)
{
    if (s.p0 == 0 || s.p0 == 3 || s.p0 == 6)
        return {-1, -1};
    s.encoded = swap9digit(s.encoded, s.p0, s.p0 - 1);
    s.p0--;
    return s;
}

const int final_state = 123456780;

void show(Tstate s)
{
    array<int, 9> a;
    for (int i = 8; i >= 0; i--)
    {
        a[i] = s.encoded % 10;
        s.encoded /= 10;
    }
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
        if (i % 3 == 2)
            cout << "\n";
    }
}

Tstate get_state()
{
    int encoded = 0;
    int p0 = -1;
    for (int i = 0; i < 9; i++)
    {
        int t;
        cin >> t;
        // cout<<t<<" ";
        encoded = encoded * 10 + t;
        if (t == 0)
            p0 = i;
    }
    // cout<<"\n"<<encoded<<"\n";
    return {p0, encoded};
}

void solve()
{
    pw10[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        pw10[i] = pw10[i - 1] * 10;
        // cout<<pw10[i]<<" ";
    }
    // cout<<"\n";
    // cout<<swap9digit(12345678,0,8)<<"\n";

    Tstate start = get_state();
    // cout<<down(start).encoded;
    queue<pair<Tstate, int>> q;
    // show(start);
    q.push({start, 0});
    auto BFS = [&]()
    {
    while(q.size())
    {
        auto tmp=q.front();
        Tstate u = tmp.first;
        int d = tmp.second;
        q.pop();
        if (u.encoded==final_state)
        {
            cout<<d<<"\n";
            return ;
        }
        vector<Tstate> next_states= {up(u),down(u),left(u),right(u)};
        for(auto&c:next_states)
        if (c.encoded!=-1&&!pre.count(c.encoded))
        {
            q.push({c,d+1});
            // cout<<u.encoded<<" "<<c.encoded<<"\n";
            if(!pre.count(c.encoded))
            pre[c.encoded]=u.encoded;
        }
    } };
    BFS();

    // int tmp = final_state;
    // while(tmp!=start.encoded)
    // {
    //     cout<<pre[tmp]<<" "<<tmp<<"\n";
    //     show({0,tmp});
    //     tmp = pre[tmp];
    // }
    // show({0,tmp});
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //	freopen("taskname.INP", "r", stdin);
    //	freopen("taskname.OUT", "w", stdout);

    solve();

    return 0;
}