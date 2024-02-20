#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int numOfApple = score.size();
    sort(score.begin(), score.end());
    int startIdx = numOfApple % m;
    int money = 0;
    while(startIdx < numOfApple){
        int boxScore = score[startIdx];
        money += boxScore * m;
        startIdx += m;
    }
    return money;
}