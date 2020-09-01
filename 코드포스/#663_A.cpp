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


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	stack<int>s;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>visit(n + 1, false);
		int num = max(n - 1, 1);
		s.push(num);
		visit[num] = true;
		for (int i = 1; i < n; i++) {
			for (int j = max(1, n - num); j <= n; j++) {
				if (!visit[j]) {
					s.push(j);
					num = j;
					visit[j] = true;
					break;
				}
			}
		}
		while (!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << '\n';
		visit.clear();
	}


	return 0;


}