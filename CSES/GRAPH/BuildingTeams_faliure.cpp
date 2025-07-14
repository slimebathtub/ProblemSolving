#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1e5+5;

vector< vector<int> > students; // vector[Student] [friend]
vector<int> student_team_num;
bool visited[MAX] = {false};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int student_num, friendships;
    cin >> student_num >> friendships;
    students.resize(student_num+1);
    student_team_num.resize(student_num+1, -1);
    for(int i = 0 ; i < friendships; i++){
        int stu_a, stu_b;
        cin >> stu_a >> stu_b;
        students[stu_a].push_back(stu_b);
        students[stu_b].push_back(stu_a);
    }

    int current_student = 1;
    visited[current_student] = true;
    student_team_num[current_student] = 0;
    bool suc = true;
    while(current_student <= student_num){
        // if is visited but is not in opposite group: false
        
        cout << "current student: " << current_student << ": " << endl;
        cout << "student team list: " << endl;
        for(int i = 1 ; i <= student_num; i++){
            cout << student_team_num[i]+1 << " ";
        }
        
        vector<int> friend_list = students[current_student];

        if(!visited[current_student]){
            student_team_num[current_student] = 0;
            visited[current_student] = true;
        }

        for(int i = 0 ; i < friend_list.size(); i++){
            int current_friend = friend_list[i];
            // cout << "friend " << current_friend << ": ";
            
            if(visited[current_friend]){
                if(student_team_num[current_friend] == student_team_num[current_student]){
                    suc = false;
                    break;
                }
            } else {
                // cout << "not vistied yet" << endl;
                student_team_num[current_friend] = (student_team_num[current_student]+1)%2;
                visited[current_friend] = true;
            }
            //cout << student_team_num[current_friend] << endl;
        }
        current_student++;
    }
    if(suc){
        for(int i = 1 ; i <= student_num; i++){
            cout << student_team_num[i]+1 << " ";
        }
    } else{
        cout << "IMPOSSIBLE" << endl;
    }
    
}