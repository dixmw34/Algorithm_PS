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

	int N, M, ans = 0;
	
	cin >> N;
	vector<int>crane(N+1);
	crane[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> crane[i];
	}
	sort(crane.begin(), crane.end());

	cin >> M;
	vector<int>box(M);
	for (int i = 0; i < M; i++) {
		cin >> box[i];
	}
	sort(box.begin(), box.end());
	ans = (M + N - 1) / N;

	if (box[M - 1] > crane[N]) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		int num = box.end() - upper_bound(box.begin(), box.end(), crane[i-1]);
		if (num % (N+1- i) != 0)num = num / (N+1 - i) + 1;
		else num = num / (N+1 - i);
		ans = max(ans, num);
	}

	cout << ans << '\n';


}