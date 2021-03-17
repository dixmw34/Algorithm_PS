#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 0, n = s.size();

    for (int i = 0; i < n; ++i) {
        int test = 1, k = 1;
        while (i - k >= 0 && i + k < n) {
            if (s[i - k] == s[i + k]) {
                test += 2;
                k++;
            }
            else
                break;
        }
        answer = max(answer, test);
    }

    for (int i = 0; i < n; ++i) {
        int test = 0, left = i, right = i + 1;
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                test += 2;
                left--; right++;
            }
            else
                break;
        }
        answer = max(answer, test);
    }

    return answer;
}