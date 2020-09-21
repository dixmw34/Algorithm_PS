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
#include <climits>

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

int par[100];

double dis(pair<double, double>a, pair<double, double>b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		
		int n;
		cin >> n;
		double left = 2000.0, right = 0.0;
		vector<pair<double, double>>arr(n);
		priority_queue<pair<double, pi>>pq;

		for (int i = 0; i < n; ++i) {
			par[i] = i;
			cin >> arr[i].first >> arr[i].second;
			for (int j = 0; j < i; ++j) {
				pq.push(make_pair(-dis(arr[j], arr[i]), pi(j, i)));
			}
		}

		double ans = 0.0;

		while (!pq.empty()) {
			double l = -pq.top().first;
			int x = pq.top().second.first, y = pq.top().second.second;
			pq.pop();

			x = find(x);
			y = find(y);
			if (x != y) {
				ans = l;
				par[x] = par[y] = min(x, y);
			}
		}

		printf("%.2lf\n", ans);
	}
	

	return 0;

}