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

vector<vector<pi>>l(100), back(100);
bool arrived[100];

void is_arrived() {
	memset(arrived, 0, sizeof(arrived));
	arrived[1] = true;
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < back[now].size(); ++i) {
			int next = back[now][i].first;
			if (arrived[next] == false) {
				arrived[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int v, w, a, b, d;
		cin >> v >> w;
		while (w--) {
			cin >> a >> b >> d;
			l[a].push_back(pi(b, d));
			back[b].push_back(pi(a, d));
		}

		is_arrived();

		vector<int>Min(v, INF), Max(v, -INF);
		Min[0] = Max[0] = 0;
		bool min_cycle = false, max_cycle = false;

		for (int k = 0; k <= v; ++k) {
			for (int i = 0; i < v; ++i) {
				if (Min[i] == INF) continue;
				//Min
				for (int j = 0; j < l[i].size(); ++j) {
					int next = l[i][j].first, new_val = Min[i] + l[i][j].second;
					if (Min[next] > new_val) {
						if (k == v && arrived[next])min_cycle = true;
						Min[next] = new_val;
					}
				}
				//Max
				for (int j = 0; j < l[i].size(); ++j) {
					int next = l[i][j].first, new_val = Max[i] + l[i][j].second;
					if (Max[next] < new_val) {
						if (k == v && arrived[next])max_cycle = true;
						Max[next] = new_val;
					}
				}


			}
		}

		if (Min[1] == INF) {
			cout << "UNREACHABLE\n";
		}
		else {
			if (min_cycle)
				cout << "INFINITY ";
			else
				cout << Min[1] << ' ';

			if (max_cycle)
				cout << "INFINITY\n";
			else
				cout << Max[1] << '\n';
		}
		
		for (int i = 0; i < v; ++i) {
			l[i].clear();
			back[i].clear();
		}

	}


	
	return 0;

}