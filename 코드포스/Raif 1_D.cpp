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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int a[100001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, h;
	vector<pi>ans;
	queue<pi>two, three;
	cin >> n;
	h = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1) {
			if (!two.empty()) {
				int x = two.front().first, y = two.front().second;
				ans.push_back(pi(x, y));
				ans.push_back(pi(x, i));
				two.pop();
				continue;
			}
			else if (!three.empty()) {
				int x = three.front().first, y = three.front().second;
				ans.push_back(pi(x, y));
				ans.push_back(pi(x, i));
				three.pop();
			}
			ans.push_back(pi(h, i));
			h++;
		}
		else if (a[i] == 2) {
			if (!three.empty()) {
				int x = three.front().first, y = three.front().second;
				ans.push_back(pi(x, y));
				ans.push_back(pi(x, i));
				three.pop();
			}
			two.push(pi(h, i));
			h++;
		}
		else if (a[i] == 3) {
			if (!three.empty()) {
				int x = three.front().first, y = three.front().second;
				ans.push_back(pi(x, y));
				ans.push_back(pi(x, i));
				three.pop();
			}
			three.push(pi(h, i));
			h++;
		}
	}

	if (!two.empty() || !three.empty() || h > n + 1 || ans.size() > 2 * n) {
		cout << -1 << '\n';
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}


	return 0;

}