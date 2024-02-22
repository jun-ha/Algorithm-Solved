#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int numOfDungeons = dungeons.size();
    int maxCount = -1;
    vector<int>idxPermutation;
    for(int i = 0; i < numOfDungeons; i++){
        idxPermutation.push_back(i);
    }
    do{
        int myHP = k;
        int tmpCount = 0;
        for(auto idx : idxPermutation){
            if(dungeons[idx][0] > myHP) break;
            tmpCount++;
            myHP -= dungeons[idx][1];
        }
        if(maxCount < tmpCount) maxCount = tmpCount;
    }while(next_permutation(idxPermutation.begin(), idxPermutation.end()));
    
    return maxCount;
}