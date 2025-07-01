#include<iostream>
using namespace std;
typedef long long ll;
#define MAXN 100000
#define MAXM 100
ll mod = 1e9 + 7;

int dp[MAXM+2][MAXN+2] = {0};

int main(){
    int n, upper_bound;
    cin >> n >> upper_bound;
    for(int j = 0 ; j < n ; j++){
        int num;
        cin >> num;

        // Initialize the first column of dp table
        if (j == 0){
            if (num == 0){
            for (int i = 1; i <= upper_bound; i++){
                dp[i][j] = 1;
            }
            } else if (num != 0){
                dp[num][j] = 1;
            }
            continue;
        }

        // Initialize the dp table for the current number
        int previous = j-1;
        int current = j;
        for (int i = 1; i <= upper_bound; i++) {
            if(dp[i][previous] > 0){
                if( i-1 > 0) dp[i-1][current] = (dp[i-1][current] + dp[i][previous]) % mod;
                dp[i][current] = (dp[i][current] + dp[i][previous]) % mod;
                if(i+1 <= upper_bound) dp[i+1][current] = (dp[i+1][current] + dp[i][previous]) % mod;
            }
        }
        if(num != 0){
            for (int i = 1; i <= upper_bound; i++) {
                if (i != num) {
                    dp[i][current] = 0;
                }
            }
        }
    }

    /*
    cout << "DP Table:" << endl;
    for (int i = 1; i <= upper_bound; i++){
        for(int j = 0 ; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    int sum = 0;
    for(int i = 1; i <= upper_bound; i++){
        sum = (sum + dp[i][n-1])%mod;
    }
    cout << sum << endl;
    return 0;
}