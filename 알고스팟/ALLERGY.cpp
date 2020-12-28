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

ll food[50];
vector<vector<int>>can_Eat(50);
map<string, int>name;
int n, m, ans = 0;

void sol(ll now, int cnt) {
	if (cnt >= ans)
		return;
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if ((now&(1LL << i)) == 0) {
			p = i;
			break;
		}
	}
	if (p == -1) {
		ans = cnt;
		return;
	}
	for (int i = 0; i < can_Eat[p].size(); ++i) {
		sol(now | food[can_Eat[p][i]], cnt + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans = min(n, m);
		memset(food, 0, sizeof(food));
		name.clear();
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			name[s] = i;
		}
		for (int i = 0; i < m; ++i) {
			int k;
			cin >> k;
			while (k--) {
				cin >> s;
				int idx = name[s];
				food[i] |= (1LL << idx);
				can_Eat[idx].push_back(i);
			}
		}
		sol(0, 0);
		cout << ans << '\n';
		for (int i = 0; i < n; ++i) {
			can_Eat[i].clear();
		}
	}

	
	
	return 0;
}