#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> tops) {
    pair<int, int>beforeCases; //#1 last triangle is part of diamond #2 not part of diamond
    if(tops[0] == 0){
        beforeCases.first = 1;
        beforeCases.second = 2;
    }
    if(tops[0] == 1){
        beforeCases.first = 1;
        beforeCases.second = 3;
    }
    for(int i = 1; i < n; i++){
        int partOfDiamond = beforeCases.first % 10007;
        int notPartOfDiamond = beforeCases.second % 10007;
        int totalCases = (partOfDiamond + notPartOfDiamond) % 10007;
        if(tops[i] == 0){ 
            beforeCases.first = totalCases;
            beforeCases.second = (totalCases + notPartOfDiamond) % 10007;
        }
        else{
            beforeCases.first = totalCases;
            beforeCases.second = ((totalCases*2) % 10007 + notPartOfDiamond) % 10007;
        }
    }
    
    return (beforeCases.first + beforeCases.second) % 10007;
}