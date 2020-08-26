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

vector<bool>visit(1000000001, false);

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K, key, value, com;

	cin >> N >> M >> K;

	map<int, int>m;

	while (N--) {
		cin >> key >> value;
		m[key] = value;
		visit[key] = true;
	}
	while (M--) {
		cin >> com;
		if (com == 1) {
			cin >> key >> value;
			m[key] = value;
			visit[key] = true;
		}
		else if (com == 2) {
			cin >> key >> value;
			int ans = -1;
			bool check = true;
			for (int i = 0; i <= K; i++) {
				if (key - i >= 0 && visit[key - i]) {
					ans = key - i;
					if (i != 0 && key + i <= 1000000000 && visit[key + i]) {
						check = false;
					}
					break;
				}
				else if (key + i <= 1000000000 && visit[key + i]) {
					ans = key + i;
					break;
				}
			}
			if (check && ans != -1)m[ans] = value;
		}
		else {
			cin >> key;
			int ans = -1;
			bool check = true;
			for (int i = 0; i <= K; i++) {
				if (key - i >= 0 && visit[key - i]) {
					ans = key - i;
					if (i != 0 && key + i <= 1000000000 && visit[key + i]) {
						check = false;
					}
					break;
				}
				else if (key + i <= 1000000000 && visit[key + i]) {
					ans = key + i;
					break;
				}
			}
			if (ans == -1)cout << -1 << '\n';
			else {
				if (check)cout << m[ans] << '\n';
				else cout << "?\n";
			}
		}
	}




	return 0;

}