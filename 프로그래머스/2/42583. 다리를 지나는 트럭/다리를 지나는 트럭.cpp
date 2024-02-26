#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int>onTheBridge;
    for(int i = 0; i < bridge_length; i++){
        onTheBridge.push(0);
    }
    
    int elapsedTime = 0;
    int numOfTruck = truck_weights.size();
    int tmpBridgeWeight = 0;
    int idx = 0;
    while(idx < numOfTruck) {
        tmpBridgeWeight -= onTheBridge.front();
        onTheBridge.pop();
        if(tmpBridgeWeight + truck_weights[idx] <= weight){
            onTheBridge.push(truck_weights[idx]);
            tmpBridgeWeight += truck_weights[idx];
            idx++;   
        }
        else onTheBridge.push(0);
        
        elapsedTime++;
    }
    elapsedTime += bridge_length; //last Truck
    
    return elapsedTime;
}