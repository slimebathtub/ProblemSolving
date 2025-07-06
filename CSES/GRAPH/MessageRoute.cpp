#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define MAX 100005

vector < vector<int> > graph;
vector <int> parent;

int main(){
    int point_num, road_num;
    cin >> point_num >> road_num;
    graph.resize(point_num+1);
    parent.resize(point_num+1);
    for(int i = 0 ; i < road_num ; i++){
        int point_a, point_b;
        cin >> point_a >> point_b;
        graph[point_a].push_back(point_b);
        graph[point_b].push_back(point_a);
    }
    queue<int> next_road;
    bool visted[MAX] = {0};
    next_road.push(1);
    bool end = false;

    while(!next_road.empty()){
        int current_point = next_road.front();
        //cout << "Round: " << current_point << endl;
        next_road.pop();
        vector<int> adj = graph[current_point];
        //cout << "Vistied: " << current_point << endl;
        visted[current_point] = true;
        if(current_point == point_num) {
            end = true;
            break;
        }
        for(int i = 0 ; i < adj.size(); i++){
            /*
            if(adj[i] == point_num){
                parent[adj[i]] = current_point;
                end = true;
                break;
            }
            */
            if (!visted[adj[i]]){
                next_road.push(adj[i]);
                parent[adj[i]] = current_point;
                visted[adj[i]] = true;
                //cout << "adj[i]: " << adj[i] << endl;
            }
        }
        if(end){
            break;
        }
    }
    /*
    cout << "Parent: " << endl;
    for(int i = 1 ; i < parent.size(); i++){
        cout << i << ": " << parent[i] << endl;
    }
    */
    
    if(end){
        //cout << "Answer: " << endl;
        int current = point_num;
        vector<int> path;
        while(current != 0){
            path.push_back(current);
            current = parent[current];
        }
        cout << path.size() << endl;
        int end_num = path.size()-1; // last number = 0
        for(int i = end_num; i >= 0; i--){
            cout << path[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}