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

bool cmp(pi a, pi b) {
	if (a.first > b.first)return true;
	else if (a.first < b.first)return false;
	else {
		return a.second > b.second;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, a, b, ans = 0;
	vector<pi>arr;
	priority_queue<int>pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back(pi(a, b));
	}

	sort(arr.begin(), arr.end(), cmp);
	int day = arr[0].first;
	int j = 0;

	for (int i = day; i >= 1; i--) {
		while (j < N && arr[j].first == i) {
			pq.push(arr[j++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';


	return 0;


}