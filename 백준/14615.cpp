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

vector<vector<int>>arr, back;
vector<bool>visit_o, visit_n;

void sol(int n) {
	queue<int>q;
	q.push(1);
	visit_o[1] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < arr[now].size(); ++i) {
			if (!visit_o[arr[now][i]]) {
				visit_o[arr[now][i]] = true;
				q.push(arr[now][i]);
			}
		}
	}

	q.push(n);
	visit_n[n] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < back[now].size(); ++i) {
			if (!visit_n[back[now][i]]) {
				visit_n[back[now][i]] = true;
				q.push(back[now][i]);
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m, x, y;
	cin >> n >> m;
	arr = vector<vector<int>>(n + 1);
	back = vector<vector<int>>(n + 1);
	while (m--) {
		cin >> x >> y;
		arr[x].push_back(y);
		back[y].push_back(x);
	}
	visit_o = vector<bool>(n + 1, false);
	visit_n = vector<bool>(n + 1, false);

	sol(n);

	int t, num;
	cin >> t;
	while (t--) {
		cin >> num;
		if (visit_o[num] && visit_n[num])cout << "Defend the CTP\n";
		else cout << "Destroyed the CTP\n";
	}

	return 0;

}