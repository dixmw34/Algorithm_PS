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

vector<int>scc;
vector<int>id;
vector<bool>finished;
vector<vector<int>>road;
stack<int>s;
int idx;
int scc_num;

int find_scc(int now) {

	id[now] = ++idx;
	int idnum = id[now];
	s.push(now);

	for (int i = 0; i < road[now].size(); i++) {
		int next = road[now][i];
		if (id[next] == -1)idnum = min(idnum, find_scc(next));
		else if (!finished[next])idnum = min(idnum, id[next]);
	}

	if (idnum == id[now]) {
		scc_num++;
		while (1) {
			int t = s.top();
			s.pop();
			scc[t] = scc_num;
			finished[t] = true;
			if (t == now)break;
		}
	}
	return idnum;
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m, x, y;
	cin >> t;
	while (t--) {
		idx = 0;
		scc_num = 0;
		cin >> n >> m;
		scc = vector<int>(n, 0);
		id = vector<int>(n, -1);
		finished = vector<bool>(n, false);
		road = vector<vector<int>>(n);

		while (m--) {
			cin >> x >> y;
			x--; y--;
			road[x].push_back(y);
		}
		for (int i = 0; i < n; i++) {
			if (id[i] == -1)find_scc(i);
		}
		vector<bool>inDegree(scc_num + 1, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < road[i].size(); j++) {
				int next = road[i][j];
				if (scc[i] != scc[next])inDegree[scc[next]] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i <= scc_num; i++) {
			if (!inDegree[i])ans++;
		}
		cout << ans << '\n';
		scc.clear();
		id.clear();
		finished.clear();
		road.clear();
	}



	return 0;
	

}