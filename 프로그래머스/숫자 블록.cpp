#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<int> solution(long long begin, long long end) {
	vector<int> answer(end-begin+1, 1);
	if (begin == 1) {
		answer[0] = 0;
	}

	for (int k = 0; k < answer.size(); ++k) {
		int num = k + begin;
		for (int i = 2; i <= sqrt(num); ++i) {
			if ((num % i) == 0 && (num / i) <= 10000000) {
				answer[k] = num / i;
				break;
			}
				
		}
	}
	return answer;
}