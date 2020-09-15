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


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t, n, num;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>a(n);
		vector<bool>lock(n, false);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) {
			cin >> num;
			if (num)lock[i] = true;
		}
		priority_queue<int>pq;
		for (int i = 0; i < n; ++i) {
			if (!lock[i])pq.push(a[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (!lock[i]) {
				a[i] = pq.top();
				pq.pop();
			}
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	

	return 0;

}