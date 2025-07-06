#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;
vector< vector<bool> > map;
vector< vector<bool> > visited(MAX, vector<bool>(MAX, false));
vector<char> path;
int n,m;

bool DFS(int currentX, int currentY, int endX, int endY){
    // cout << "Visiting: " << currentX << " " << currentY << endl;
    if(currentX < 0 || currentY < 0 || currentX >= n || currentY >= m){
        return false;
    }
    if(map[currentX][currentY] == false || visited[currentX][currentY]){
        return false;
    }
    else{
        visited[currentX][currentY] = true;
        if(currentX == endX && currentY == endY){
            return true;
        }
        else{
            bool result = false;
            result = DFS(currentX + 1, currentY, endX, endY);
            if (result)
            {
                path.push_back('D');
                return true;
            }
            
            result = DFS(currentX - 1, currentY, endX, endY);
            if (result)
            {
                path.push_back('U');
                return true;
            }

            result = DFS(currentX, currentY + 1, endX, endY);
            if (result)
            {
                path.push_back('R');
                return true;
            }

            result = DFS(currentX, currentY - 1, endX, endY);
            if (result)
            {
                path.push_back('L');
                return true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    map.resize(n, vector<bool>(m, false));
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char code;
            cin >> code;
            if (code == 'A') {
                startX = i;
                startY = j;
                map[i][j] = true;
            }
            else if (code == 'B') {
                endX = i;
                endY = j;
                map[i][j] = true;
            }
            else if (code == '#') {
                map[i][j] = false;
            } else if (code == '.') {
                map[i][j] = true;
            }
        }
    }
    if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
        cout << "NO" << endl;
        return 0;
    }
    bool result = def(startX, startY, endX, endY);
    if (!result) {
        cout << "NO" << endl;
        return 0;
    } else {
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (char c : path) {
            cout << c;
        }
    }
    return 0;
}