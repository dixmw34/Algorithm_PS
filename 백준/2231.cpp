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

vector<int>arr(1000001, 0);

int sol(int num) {
	int sum = 0;
	while (num) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 1000000; i++) {
		int a = i + sol(i);
		if (a < 1000000 && arr[a] == 0)arr[a] = i;
	}

	int n;
	cin >> n;

	cout << arr[n] << '\n';

	return 0;

}