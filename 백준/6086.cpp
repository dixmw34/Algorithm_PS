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

const int MAX = 'z' - 'A' + 1;
vector<vector<ll>>c(MAX, vector<ll>(MAX, 0));
vector<vector<ll>>f(MAX, vector<ll>(MAX, 0));
vector<int>d;
ll result = 0;

void bfs(int start, int end) {
	while (1) {
		d = vector<int>(MAX,-1);
		queue<int>q;
		q.push(start);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			if (now == end)break;
			for (int i = 0; i < MAX; i++) {
				if (c[now][i] - f[now][i] > 0 && d[i] == -1) {
					d[i] = now;
					q.push(i);
					//cout << now << " -> " << i << '\n';
				}
			}
		}
		while (!q.empty())q.pop();
		if (d[end] == -1)break;
		ll flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		result += flow;
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
	}
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	ll z;
	char x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		c[x - 'A'][y - 'A'] += z;
		c[y - 'A'][x - 'A'] += z;
	}

	bfs(0, 'Z' - 'A');

	cout << result << '\n';


	return 0;
	

}