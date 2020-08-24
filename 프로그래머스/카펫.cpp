#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    for (int i = 3; i < 2500; i++) {
        for (int j = 3; j <= i; j++) {
            int a = (i + j - 2) * 2;
            int b = (i - 2)*(j - 2);
            if (a == brown && b == yellow) {
                return { i, j };
            }
        }
    }
}