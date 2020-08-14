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

vector<vector<int>>road;
vector<bool>visit;
vector<bool>finished;
vector<int>id;
stack<int>s;
vector<vector<int>>SCC;
int idx = 1;

int dfs(int num) {
	visit[num] = true;
	s.push(num);
	id[num] = idx++;
	int idx = id[num];
	for (int i = 0; i < road[num].size(); i++) {
		int next = road[num][i];
		if (!visit[next]) idx = min(idx, dfs(next));
		else if (!finished[next])idx = min(idx, id[next]);
	}
	if (id[num] == idx) {
		vector<int>a;
		while (1) {
			int t = s.top();
			s.pop();
			a.push_back(t);
			finished[t] = true;
			if (t == num)break;
		}
		SCC.push_back(a);
	}
	return idx;
}


bool cmp(vector<int>a, vector<int>b) {
	if (a[0] < b[0])return true;
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E, a, b;
	cin >> V >> E;
	road = vector<vector<int>>(V + 1);
	visit = vector<bool>(V + 1, false);
	finished = vector<bool>(V + 1, false);
	id = vector<int>(V + 1, 0);

	while (E--) {
		cin >> a >> b;
		road[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (!visit[i])dfs(i);
	}


	for (int i = 0; i < SCC.size(); i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}

	sort(SCC.begin(), SCC.end(), cmp);
	
	cout << SCC.size() << '\n';


	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << "-1 \n";
	}


	return 0;


}