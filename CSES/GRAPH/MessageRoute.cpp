#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define MAX 100000

vector<int> graph;
vector < vector<int> > parent;


void dfs(int start, int end){

}

int main(){
    int point_num, road_num;
    cin >> point_num >> road_num;
    parent.resize(point_num);
    for(int i = 0 ; i < road_num ; i++){
        int point_a, point_b;
        cin >> point_a >> point_b;
        parent[point_a].push_back(point_b);
        parent[point_b].push_back(point_a);
    }
    queue<int> next_road;
    bool visted[10005] = {0};
    next_road.push(1);
    while(!next_road.empty()){
        int current_point = next_road.front();
        if(current_point == point_num) break;
        for(int i = 0 ; i < parent[current_point].size(); i++){
            if (!visted[parent[current_point][i]]){
                next_road.push(parent[current_point][i]);
                visted[parent[current_point][i]] = true;
            }
        }
        next_road.pop();
    }
    cout << << endl;

}