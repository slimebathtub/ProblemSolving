#include<iostream>
#include<vector>
using namespace std;
#define MAX 100001

vector<int> adj[MAX];
vector<bool> visited(MAX, 0);
vector< vector<int> > group;

void dfs(int current, int groupIndex = 0){
    visited[current] = true;
    for(int i = 0; i < adj[current].size(); i++){
        // cout << "Visiting: " << adj[current][i] << endl;
        if(!visited[adj[current][i]]){
            group[groupIndex].push_back(adj[current][i]);
            dfs(adj[current][i]);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int groupCount = 0;
    for(int i = 1; i <= n ; i++){
        if (visited[i]) continue;
        else{
            group.push_back(vector<int>());
            group[groupCount].push_back(i);
            dfs(i, groupCount);
            groupCount++;
        }
    }
    /*
    for ( int i = 0; i < groupCount; i++) {
        cout << "Group " << i + 1 << ": ";
        if (group.size() <= 0) {
            cout << "No groups" << endl;
            continue;
        }
        if (group[i].empty()) {
            cout << "No members" << endl;
            continue;
        } else{
            for (int j = 0; j < group[i].size(); j++) {
                cout << group[i][j] << " ";
            }
        }
    }
    */
    cout << groupCount-1 << endl;
    for (int i = 0; i < groupCount - 1; i++) {
        cout << group[i][0] << " " << group[i + 1][0] << endl;
    }
}