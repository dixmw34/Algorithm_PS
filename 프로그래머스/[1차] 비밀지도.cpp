#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));

    for (int i = 0; i < n; i++) {
        int num = (arr1[i] | arr2[i]);
        int idx = n - 1;
        while (idx >= 0) {
            if (num % 2 == 1)answer[i][idx] = '#';
            num /= 2; idx--;
        }
    }

    return answer;
}