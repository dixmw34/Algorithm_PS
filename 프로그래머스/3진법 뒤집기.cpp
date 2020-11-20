#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	string a = "";
	while (n) {
		a = to_string(n % 3) + a;
		n /= 3;
	}
	int test = 1;
	for (int i = 0; i < a.size(); ++i) {
		answer += (a[i] - '0')*test;
		test *= 3;
	}

	return answer;
}