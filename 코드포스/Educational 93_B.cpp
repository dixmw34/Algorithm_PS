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

	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int Alice = 0, Bob = 0;

		priority_queue<int>pq;

		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				num++;
			}
			else {
				if (num > 0)pq.push(num);
				num = 0;
			}
		}
		if (num > 0)pq.push(num);

		int size = pq.size();

		for (int i = 0; i < size; i++) {
			if (i % 2 == 0)Alice += pq.top();
			else Bob += pq.top();
			pq.pop();
		}
		cout << Alice << '\n';
	}



	return 0;
	

}