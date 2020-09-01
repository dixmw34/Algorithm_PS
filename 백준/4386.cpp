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
typedef pair<double, double> pd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<int>par(100);

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	double a, b, ans = 0;
	vector<pd>arr;
	priority_queue<pair<double, pi>>pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		par[i] = i;
		for (int j = 0; j < arr.size(); j++) {
			double r = pow((arr[j].first - a), 2) + pow((arr[j].second - b), 2);
			pq.push(make_pair(-r, pi(j, i)));
		}
		arr.push_back(pd(a, b));
	}
	while (!pq.empty()) {
		double r = -pq.top().first;
		int x = pq.top().second.first, y = pq.top().second.second;
		pq.pop();
		x = find(x); y = find(y);
		if (x != y) {
			par[x] = par[y] = min(x, y);
			ans += sqrt(r);
		}
	}
	printf("%.5lf\n", ans);

	return 0;

}