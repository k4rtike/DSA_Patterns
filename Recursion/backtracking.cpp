#include<bits/stdc++.h>
using namespace std;

void fun(vector<int> &arr, int n, int idx, vector<int> &temp){

    if(idx == n){
        for(int x : temp)
            cout << x << " ";
        cout << endl;
        return;
    }

    // Not choose
    fun(arr, n, idx+1, temp);

    // Choose
    temp.push_back(arr[idx]);
    fun(arr, n, idx+1, temp);
    temp.pop_back();   // Backtracking
}

int main(){

    vector<int> arr = {1,2,3};
    vector<int> temp;

    fun(arr, arr.size(), 0, temp);

    return 0;
}
