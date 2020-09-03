#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, k = 0;

    for (int i = 0; i < name.size(); i++) {
        if (name[i] != 'A') {
            k++;
            answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        }

    }
    if (k == name.size()) {
        return answer + k - 1;
    }
    else {
        int i = 0;
        while (k) {
            if (name[i] != 'A') {
                name[i] = 'A';
                if (--k == 0)break;
            }
            int left = 0;
            while (left < name.size()) {
                if (name[(i - left + name.size()) % name.size()] != 'A')break;
                left++;
            }
            int right = 0;
            while (right < name.size()) {
                if (name[(right + i) % name.size()] != 'A')break;
                right++;
            }
            if (left < right) {
                i = (i - left + name.size()) % name.size();
                answer += left;
            }
            else {
                i = (right + i) % name.size();
                answer += right;
            }
        }
    }


    return answer;
}