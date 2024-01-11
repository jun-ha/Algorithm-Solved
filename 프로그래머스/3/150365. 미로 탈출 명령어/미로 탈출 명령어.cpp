#include <string>
#include <vector>
#include <cstdlib>
#define DOWN 0
#define LEFT 1
#define RIGHT 2
#define UP 3

using namespace std;

bool canMove(int n, int m, int x, int y, int r, int c, int leftStep, int move) {
    if (move == DOWN) x = x + 1;
    if (move == LEFT) y = y - 1;
    if (move == RIGHT) y = y + 1;
    if (move == UP) x = x - 1;
    int xabs = abs(x - r);
    int yabs = abs(y - c);

    if (1 <= x && x <= n && 1 <= y && y <= m && xabs + yabs <= leftStep-1) {
        return true;
    }
    return false;

}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int leftStep = k;
    while (leftStep) {  
        if (canMove(n, m, x, y, r, c, leftStep, DOWN)) {
            x = x + 1;
            answer += "d";
        }
        else if (canMove(n, m, x, y, r, c, leftStep, LEFT)) {
            y = y - 1;
            answer += "l";
        }
        else if (canMove(n, m, x, y, r, c, leftStep, RIGHT)) {
            y = y + 1;
            answer += "r";
        }
        else if (canMove(n, m, x, y, r, c, leftStep, UP)) {
            x = x - 1;
            answer += "u";
        }
        else {
            answer = "impossible";
            break;
        }
        leftStep--;
    }
    if (x != r && y != c) answer = "impossible";
    return answer;
}