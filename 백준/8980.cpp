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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

bool cmp(pi a, pi b) {
	if (a.first > b.first)return true;
	else if (a.first < b.first)return false;
	else {
		return a.second > b.second;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, C, M, s, e, amount, truct, ans = 0;

	cin >> N >> C >> M;
	truct = C;
	vector<vector<pi>>box(N + 1);
	deque<pi>dq;

	while (M--) {
		cin >> s >> e >> amount;
		box[s].push_back(pi(e, amount));
	}

	for (int i = 1; i <= N; i++) {
		truct = C;
		if (!dq.empty()) {
			while(!dq.empty() && dq.front().first == i) {
				ans += dq.front().second;
				dq.pop_front();
			}
			while (!dq.empty()) {
				box[i].push_back(dq.front());
				dq.pop_front();
			}
		}
		sort(box[i].begin(), box[i].end());
		for (int j = 0; j < box[i].size(); j++) {
			int num = min(truct, box[i][j].second);
			dq.push_back(pi(box[i][j].first, num));
			truct -= num;
			if (truct == 0)break;
		}
	}

	cout << ans << '\n';


	return 0;


}