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
	if (a.first == b.first)return a.second > b.second;
	else return a.first < b.first;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b, c, d;
	cin >> n;
	vector<pi>arr(n);
	deque<pi>dq;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		arr[i] = pi(a*100 + b, c*100 + d);
	}

	sort(arr.begin(), arr.end(), cmp);
	dq.push_back(pi(0, 301));

	for (int i = 0; i < n; i++) {
		if (dq.back().second >= arr[i].first&& dq.back().second < arr[i].second) {
			if (dq.size() >= 2 && dq[dq.size() - 2].second >= arr[i].first) {
				dq.pop_back();
			}
			dq.push_back(arr[i]);
			if (dq.back().second >= 1201) {
				cout << dq.size() - 1 << '\n';
				return 0;
			}
		}
	}

	cout << 0 << '\n';

	/*
	if (dq.back().second <= month[11] + 30) {
		cout << 0 << '\n';
		return 0;
	}*/

	
	

	return 0;

}