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

const int MAX = 200000;
int n;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, q;
	char ch;
	map<int, int>m;
	vector<int>arr(MAX + 1, 0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (arr[0] == 0) {
			m.insert(pi(a, 0));
		}
		arr[a]++;
	}

	int two = 0, four = 0;
	for (auto i : m) {
		int num = i.first;
		if (arr[num] >= 8) {
			four += 2;
		}
		else if (arr[num] >= 6) {
			two++;
			four++;
		}
		else if (arr[num] >= 4) {
			four++;
		}
		else if (arr[num] >= 2) {
			two++;
		}
	}

	
	cin >> q;
	while (q--) {
		cin >> ch >> a;
		if (ch == '+') {
			if (arr[a]++ == 0) {
				m.insert(pi(a, 0));
			}
			else if (arr[a] == 2) {
				two++;
			}
			else if (arr[a] == 4) {
				two--;
				four++;
			}
			else if (arr[a] == 6) {
				two++;
			}
			else if (arr[a] == 8) {
				two--;
				four++;
			}
		}
		else {
			if (--arr[a] == 0) {
				m.erase(m.find(a));
			}
			else if (arr[a] == 1) {
				two--;
			}
			else if (arr[a] == 3) {
				two++;
				four--;
			}
			else if (arr[a] == 5) {
				two--;
			}
			else if (arr[a] == 7) {
				two++;
				four--;
			}
		}
		if (four >= 2 || (four >= 1 && two >= 2)) {
			cout << "YES" << '\n';
		}
		else cout << "NO\n";
	}

	return 0;


}