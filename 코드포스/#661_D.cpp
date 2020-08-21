#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	string s;

	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int>ans;
		stack<int>one;
		stack<int>zero;

		for (int i = 0; i < n; i++) {
			int idx = one.size() + zero.size() + 1;
			if (s[i] == '0') {
				if (one.empty()) {
					ans.push_back(idx);
					zero.push(idx);
				}
				else {
					ans.push_back(one.top());
					zero.push(one.top());
					one.pop();
				}
			}
			else {
				if (zero.empty()) {
					ans.push_back(idx);
					one.push(idx);
				}
				else {
					ans.push_back(zero.top());
					one.push(zero.top());
					zero.pop();
				}
			}
		}

		cout << one.size() + zero.size() << '\n';

		for (int i = 0; i < n; i++)cout << ans[i] << ' ';
		cout << '\n';
	}



	return 0;

}