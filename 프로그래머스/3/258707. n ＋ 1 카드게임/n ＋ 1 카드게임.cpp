#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000
int N;
int leftCoin;
int throwAbleCard1, throwAbleCard2;

vector<bool>hand(MAX_N, false);
vector<bool>chooseAble(MAX_N, false);

bool handCheck(){
    for(int i = 1; i <= N/2; i++){
        if(hand[i] && hand[N+1-i]) {
            throwAbleCard1 = i;
            throwAbleCard2 = N+1-i;
            return true;
        }
    }
    return false;
}
void throwCards(){
    if(throwAbleCard1 + throwAbleCard2 != N+1) {
        cerr << "error" << endl;
        exit(-1);
    }
    hand[throwAbleCard1] = false;
    hand[throwAbleCard2] = false;
    cout << "throw cards : " << throwAbleCard1 << " " << throwAbleCard2 << endl;
}
void drawCard(vector<int>& cards, int amount, int idx){
    cout << "draw cards : ";
    for(int i = 0; i < amount; i++){
        chooseAble[cards[idx+i]] = true;
        cout << cards[idx+i] << " ";
    }
    cout << endl;
}
bool chooseAbleCheck(){
    for(int i = 1; i <= N; i++){
        if(hand[i] && chooseAble[N+1-i]){
            throwAbleCard1 = i;
            throwAbleCard2 = N+1-i;
            hand[N+1-i] = true;
            chooseAble[N+1-i] = false;
            leftCoin--;
            return true;
        }
    }
    if(leftCoin >= 2){
        for(int i = 1; i <= N; i++){
            if(chooseAble[i] && chooseAble[N+1-i]){
                hand[i] = true;
                hand[N+1-i] = true;
                chooseAble[i] = false;
                chooseAble[N+1-i] = false;
                throwAbleCard1 = i;
                throwAbleCard2 = N+1-i;
                leftCoin -= 2;
                return true;
            }
        }   
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    N = cards.size();
    leftCoin = coin;
    int round = 0;
    
    int idx;
    for(idx = 0; idx < N/3; idx++){
        hand[cards[idx]] = true;
    }
    
    while(1) {
        round++;
        cout << "\nRound : " << round << endl << "-------------------\n";
        if(idx >= N) break;
        int drawAmount = 2;
        drawCard(cards, drawAmount, idx);
        idx += drawAmount;
        
        if(handCheck()){
            throwCards();
        }
        else if(leftCoin >= 1 && chooseAbleCheck()){
            throwCards();
        }
        else{
            break;
        }
    }
    
    
    return round;
}