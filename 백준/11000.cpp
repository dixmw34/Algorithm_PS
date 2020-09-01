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
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>>pq;
	vector<pi>arr;
	int n, s, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		arr.push_back(pi(s, t));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (pq.empty())pq.push(arr[i].second);
		else {
			if (pq.top() <= arr[i].first) {
				pq.pop();
			}
			pq.push(arr[i].second);
		}
	}

	cout << pq.size() << '\n';

	return 0;

}