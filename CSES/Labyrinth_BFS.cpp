#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

#define MAX 1001
typedef std::pair<int,int> PII;

using namespace std;
vector< vector<bool> > map;
vector< vector<bool> > visited(MAX, vector<bool>(MAX, false));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
PII memory[MAX][MAX];

int n,m;

bool pointValid (int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m){
        if (map[x][y] && !visited[x][y]) {
            return true;
        }
    }
    return false;
}

bool BFS(int startX, int startY, int endX, int endY) {
    queue<PII> queue;
    PII start = make_pair(startX, startY);
    queue.push(start);
    visited[startX][startY] = true;
    while(!queue.empty()){
        PII current = queue.front();
        queue.pop();
        int currentX = current.first;
        int currentY = current.second;
        //cout << "Visiting: " << currentX << " " << currentY << endl;
        if(currentX == endX && currentY == endY) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if(pointValid(newX, newY)) {
                visited[newX][newY] = true;
                PII newPoint = make_pair(currentX, currentY);
                queue.push(make_pair(newX, newY));
                memory[newX][newY] = newPoint;
            }
        }
    }
    return false;
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
    bool result = BFS(startX, startY, endX, endY);
    if (!result) {
        cout << "NO" << endl;
        return 0;
    } else {
        vector<char> path;
        while (endX != startX || endY != startY) {
            PII previous = memory[endX][endY];
            if (endX == previous.first + 1) {
                path.push_back('D');
            } else if (endX == previous.first - 1) {
                path.push_back('U');
            } else if (endY == previous.second + 1) {
                path.push_back('R');
            } else if (endY == previous.second - 1) {
                path.push_back('L');
            }
            endX = previous.first;
            endY = previous.second;
        }
        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (char direction : path) {
            cout << direction;
        }
    }
}