//ALDS1_3_A
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<long long> st;
	string s;
	getline(cin, s);
	stringstream ss;
	ss << s;

	auto toInt = [](string s)
	{int u=0;for(auto&c:s)u=u*10+c-'0';return u; };
	while (ss >> s)
	{
		if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
		{
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (s[0] == '+')
				st.push(a + b);
			else if (s[0] == '-')
				st.push(a - b);
			else if (s[0] == '*')
				st.push(a * b);
			else if (s[0] == '/')
				st.push(a / b);
		}
		else if (s[0] >= '0' && s[0] <= '9')
			st.push(toInt(s));
		else
			break;
	}
	cout << st.top() << "\n";
	return 0;
}
