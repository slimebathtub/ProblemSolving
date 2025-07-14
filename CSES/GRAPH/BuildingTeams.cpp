#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 1e5+5;

struct point{
    int team = -1;
    vector<int> friends;
    bool visited = false;
};

class Graph{
    private:
        int student_num;
        vector<point> points;

    public:
        Graph(int student_num){
            this -> student_num = student_num;
            points.resize(student_num+5);
        }

        void add_friedn_ship(int a, int b){
            points[a].friends.push_back(b);
            points[b].friends.push_back(a);
        }

        bool color_friends(point* current_point){
            vector<int> curr_friend = current_point -> friends;
            int target_team_num = (current_point -> team+1)%2;
            for (int fr : curr_friend){
                //cout << "check: " << fr << endl;
                if(!points[fr].visited){
                    points[fr].team = target_team_num;
                    //points[fr].visited = true;
                } else {
                    if (points[fr].team != target_team_num){
                        return false;
                    }
                }
                //cout << "current friend: " << endl;
                //print();
            }
            return true;
        }

        bool color_graph(int start){
            queue<point*> wait_list;
            wait_list.push(&points[start]);
            
            while (!wait_list.empty()){
                point* curr = wait_list.front();
                wait_list.pop();
                curr->visited = true;
                bool suc = color_friends(curr);
                
                for (int pt_num : curr->friends){
                    if(!points[pt_num].visited){
                        wait_list.push(&points[pt_num]);
                    }
                }
                
                if(!suc) return false;
            }
            return true;
        }
        
        bool color_whole_graph(){
            bool suc = true;
            for(int i = 1 ; i <= student_num; i++){
                if(!points[i].visited){
                    points[i].team = 0;
                    //cout << "now coloring " << i << endl;
                    suc = color_graph(i);
                    if(suc == false ) return false;
                }
            }
            return true;
        }

        void print(){
            for(int i = 1 ; i <= student_num ; i++){
                cout << points[i].team+1 << " ";
            }
            cout << endl;
        }
};

int main(){
    
    int stu_num, line_num;
    cin >> stu_num >> line_num;
    Graph graph(stu_num);
    for(int i = 0 ; i < line_num; i++){
        int stu_a, stu_b;
        cin >> stu_a >> stu_b;
        graph.add_friedn_ship(stu_a, stu_b);
    }
    //graph.print();

    bool suc = graph.color_whole_graph();

    if(suc){
        graph.print();
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}