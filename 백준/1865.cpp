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

const int MIN = -1e9 - 1;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m, w, start, end, cost;
	
	cin >> t;

	while (t--) {
		cin >> n >> m >> w;
		vector<vector<pi>>road(n + 1);

		while (m--) {
			cin >> start >> end >> cost;
			road[start].push_back(pi(end, cost));
			road[end].push_back(pi(start, cost));
		}

		while (w--) {
			cin >> start >> end >> cost;
			road[start].push_back(pi(end, -cost));
		}

		bool is_cycle = false;
		vector<int>time(n + 1, INF);
		time[1] = 0;

		for (int k = 0; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < road[i].size(); j++) {
					int next = road[i][j].first;
					int new_val = time[i] + road[i][j].second;
					if (time[next] > new_val) {
						time[next] = new_val;
						if (k == n)is_cycle = true;
					}
				}
			}
		}

		if (is_cycle)cout << "YES\n";
		else cout << "NO\n";


	}


	return 0;

}