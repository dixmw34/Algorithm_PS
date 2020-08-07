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

const int MAX = 1000000001;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "";
	char ch;
	int result = INF;
	//vector<bool>visit(900000000, false);

	for (int i = 0; i < 9; i++) {
		cin >> ch;
		s += ch;
	}
	queue<pair<string, int>>q;
	map<int, int>m;
	m.insert(pi(atoi(s.c_str()), 0));
	q.push(make_pair(s, 0));

	while (!q.empty()) {
		s = q.front().first; int time = q.front().second; q.pop();
		if (s == "123456780") {
			cout << time << '\n';
			return 0;
		}
		int num = s.find('0');
		int x = num / 3; int y = num % 3;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < 3 && y + dy[i] >= 0 && y + dy[i] < 3) {
				int swap_num = (x + dx[i]) * 3 + y + dy[i];
				string a = s;
				swap(a[num], a[swap_num]);
				if (m.find(atoi(a.c_str())) == m.end()) {
					m.insert(pi(atoi(a.c_str()), 0));
					q.push(make_pair(a, time + 1));
				}
			}
		}
	}
	
	cout << -1 << '\n';

	return 0;


}