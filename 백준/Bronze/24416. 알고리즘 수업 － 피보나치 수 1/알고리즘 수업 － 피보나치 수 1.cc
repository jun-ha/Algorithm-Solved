#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
vector<int>f(41, 0);
ll fibonacci(int n){
    for(int i = 3; i <= n;i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main(void){
    f[1] = 1;
    f[2] = 1;
    int a, b;
    cin >> a >> b;
    cout << fibonacci(a) << ' ' << a-2;
    return 0;
}