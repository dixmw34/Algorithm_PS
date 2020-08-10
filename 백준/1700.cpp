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

	int N, K, num, ans = 0, start = 0;
	
	cin >> N >> K;

	vector<int>arr(K);
	vector<int>tap;
	vector<queue<int>>list(K+1);

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		list[arr[i]].push(i);
	}

	for (int i = 0; i < K; i++) {
		bool change = true;

		pi max_num = pi(0, 0);
		for (int j = 0; j < tap.size(); j++) {
			if (tap[j] == arr[i]) {
				change = false;
				break;
			}

			if(list[tap[j]].empty())max_num = pi(INF, j);
			else if (max_num.first < list[tap[j]].front()) {
				max_num = pi(list[tap[j]].front(), j);
			}
		}
		if (change) {
			if (tap.size() < N) {
				tap.push_back(arr[i]);
			}
			else {
				tap[max_num.second] = arr[i];
				ans++;
			}
		}
		list[arr[i]].pop();
		
	}

	cout << ans << '\n';

	return 0;


}