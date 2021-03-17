#include <string>
#include <vector>

using namespace std;

int cal(int num) {
    int result = 0;
    while (num) {
        if (num % 2)result++;
        num /= 2;
    }
    return result;
}


int solution(int n) {
    int test = cal(n);
    while (++n) {
        if (cal(n) == test) {
            return n;
        }
    }
}