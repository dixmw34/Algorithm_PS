#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		string s;
		cin >> s;
		stack<char>st;
		bool flag = true;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty() || (st.top() != '(')) {
					flag = false;
					break;
				}
				st.pop();
			}
			else if (s[i] == '}') {
				if (st.empty() || (st.top() != '{')) {
					flag = false;
					break;
				}
				st.pop();
			}
			else if (s[i] == ']') {
				if (st.empty() || (st.top() != '[')) {
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())flag = false;

		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}



	return 0;

}