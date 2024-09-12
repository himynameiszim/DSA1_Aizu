//ALDS1_4_D
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> s(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s[i] = t;
    }

    auto chia = [&](long long thred)
    {
        int cnt = 0;
        long long tmp = 0;
        for (auto &t : s)
        {
            if (tmp + t <= thred)
                tmp += t;
            else
            {
                if (t > thred)
                    return 10000000;
                // cout<<"tmp"<<" "<<tmp<<"\n";
                tmp = t;
                cnt++;
            }
            // cout<<t<<" "<<tmp<<"\n";
        }

        // cout<<"chia"<<" "<<thred<<" "<<cnt<<"\n";
        if (tmp)
            cnt++;
        // cout<<"chia:"<<" "<<thred<<" "<<cnt<<"\n";
        return cnt;
    };
    auto chat = [&]()
    {
        long long l = 0, r = 1e18;
        while (r - l > 1)
        {
            long long mid = (l + r) / 2;
            if (chia(mid) >= k + 1)
                l = mid;
            else
                r = mid;
        }
        return r;
    };
    cout << chat() << "\n";
    return 0;
}