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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, num, ans = 0;
	priority_queue<int>pq;

	cin >> n;
	while (n--) {
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty()) {
		if (pq.size() >= 3) {
			for (int i = 0; i < 2; i++) {
				ans += pq.top();
				pq.pop();
			}
			pq.pop();
		}
		else {
			while (!pq.empty()) {
				ans += pq.top();
				pq.pop();
			}
		}
	}

	cout << ans << '\n';


	return 0;

}