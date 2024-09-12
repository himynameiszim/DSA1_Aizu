//ALDS1_5_C
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

const double Pi = acos(-1);
const int N = 1e9 + 2;
int cnt = 0;
vector<int> vt;

struct Tpoint
{
    double x, y;
    Tpoint(double x = 0, double y = 0) : x(x), y(y) {}
    Tpoint operator+(Tpoint p)
    {
        return Tpoint(x + p.x, y + p.y);
    }
    Tpoint operator-(Tpoint p)
    {
        return Tpoint(x - p.x, y - p.y);
    }
    Tpoint operator*(double a)
    {
        return Tpoint(x * a, y * a);
    }
    Tpoint operator/(double a)
    {
        return Tpoint(x / a, y / a);
    }
    double dist(Tpoint p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
    double angel(Tpoint p)
    {
        return atan2(p.y - y, p.x - x);
    }
    void print()
    {
        cout << fixed << setprecision(8) << x << " " << y << "\n";
    }
};

void koch(int d, Tpoint p1, Tpoint p2)
{
    if (d == 0)
    {
        p1.print();
    }
    Tpoint s = (p1 * 2 + p2) / 3, t = (p1 + p2 * 2) / 3;
    // The idea is convert to polar coordinate and centerlize s
    double r = s.dist(t);
    double theta = s.angel(t);
    Tpoint u = Tpoint(r * cos(Pi / 3 + theta), r * sin(Pi / 3 + theta)) + s;

    if (d > 0)
    {
        koch(d - 1, p1, s);
        koch(d - 1, s, u);
        koch(d - 1, u, t);
        koch(d - 1, t, p2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    koch(n, Tpoint(0, 0), Tpoint(100, 0));
    Tpoint(100, 0).print();

    return 0;
}