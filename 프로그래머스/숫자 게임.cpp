#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int j = n - 1;

    for (int i = n-1; i >= 0; --i) {
        if (A[i] < B[j]) {
            j--;
            answer++;
        }
    }

    return answer;
}