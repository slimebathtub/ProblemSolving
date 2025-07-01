#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int upperBound = 1000000;

bool available(ll num) {
    return num >= 1 && num <= upperBound;
}

ll solve(vector<ll> &a, int currentIndex, int endIndex, int currentNum, int endNum){
    ll result = 0;
    if (currentIndex == endIndex && currentNum == endNum) {
        return 1;
    } else if (currentIndex == endIndex && currentNum != endNum ){
        return 0;
    } else if (currentIndex == endIndex && endIndex == -1){
        return 1;
    }

    ll lowerPossible = currentNum - 1;
    ll middlePossible = currentNum;
    ll upperPossible = currentNum + 1;
    
    if (!available(lowerPossible) || !available(middlePossible) || !available(upperPossible)) {
        return 0;
    }
    cout << "Current Index: " << currentIndex << ", Current Num: " << currentNum << endl;
    cout << "Lower Possible: " << lowerPossible << ", Middle Possible: " << middlePossible << ", Upper Possible: " << upperPossible << endl;
    ll lowerPossibility = solve(a, currentIndex + 1, endIndex, lowerPossible, endNum) %mod;
    ll middlePossibility = solve(a, currentIndex + 1, endIndex, middlePossible, endNum) %mod;
    ll upperPossibility = solve(a, currentIndex + 1, endIndex, upperPossible, endNum) %mod;
    
    result = (lowerPossibility + middlePossibility + upperPossibility) % mod;

    return result;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> upperBound;
    vector<ll> numList(n);
    for (int i = 0; i < n; i++) {
        cin >> numList[i];
    }
    ll result = 1;
    int start_index = -1;
    int end_index = -1;
    int start_num = -1;
    int end_num = -1;
    for (int i = 0 ; i < n ; i++){
        if (numList[i] == 0){
            if(start_index == -1){
                if( i - 1 >= 0 && numList[i-1] != 0){
                    start_index = i - 1;
                    start_num = numList[i-1];
                } else if ( i - 1 < 0){
                    start_index = i;
                    start_num = -1;
                }
            }
            if (end_index == -1){
                if (i + 1 < n && numList[i+1] != 0){
                    end_index = i + 1;
                    end_num = numList[i+1];
                } else if (i + 1 >= n){
                    end_index = i;
                    end_num = -1;
                }
            }
        }
        if (start_index == 0) {
            for (int j = 0; j < upperBound ;j++){
                ll possibilities = solve(numList, start_index, end_index, j, end_num);
            }
        }
        if (start_index != -1 && end_index != -1) {
            cout << "Calculating possibilities from index " << start_index << " to " << end_index << endl;
            cout << "start_index: " << start_index << ", start_num: " << start_num << endl;
            cout << "end_index: " << end_index << ", end_num: " << end_num << endl;
            cout << "Calculating possibilities..." << endl;
            ll possibilities = solve(numList, start_index, end_index, start_num, end_num);
            //cout << "Possibilities: " << possibilities << endl;
            if (result == 1) {
                result = possibilities;
            } else {
                result = (result * possibilities) % mod;
            }
            start_index = -1;
            end_index = -1;
        }
    }
    cout << result << endl;
}