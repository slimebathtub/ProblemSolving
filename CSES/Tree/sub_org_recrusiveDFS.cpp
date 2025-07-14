#include<iostream>
#include<vector>
using namespace std;
 
class leaf{
    private:
        leaf* boss = nullptr;
        int employees_count = 0;
        vector<leaf*> subordinates;
 
    public:
        void set_boss(leaf* boss){
            this->boss = boss;
        }
        int get_subordinates_cout(){
            return employees_count;
        }
        void add_subordinates(leaf* employee){
            subordinates.push_back(employee);
        }
        void set_employee_count(int num){
            this -> employees_count = num;
        }
        vector<leaf*> get_sub(){
            return this->subordinates;
        }
};
 
class tree{
    private:
        int num;
        vector<leaf*> employees;
 
    public:
        tree(int num){
            this->num = num;
            employees.resize(num+1, nullptr);
            for(int i = 1 ; i <= num; i++){
                employees[i] = new leaf();
            }
        }
 
        void add_employee(int employee_code, int boss){
            employees[employee_code]->set_boss(employees[boss]);
            employees[boss]->add_subordinates(employees[employee_code]);
        }
 
        int dfs(leaf* current){
            if(current == nullptr){
                return 0;
            }
            int count = 0;
            for(leaf* sub : current->get_sub()){
                count += 1 + dfs(sub);
            }
            current->set_employee_count(count);
            return count;
        }
 
        void travel_tree(){
            dfs(employees[1]);
        }
 
        void output(){
            for(int i = 1; i< employees.size(); i++){
                cout << employees[i]->get_subordinates_cout() << " ";
            }
        }
 
        ~tree(){
            for(int i = 0; i < employees.size(); i++){
                delete employees[i] ;
            }
        }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    tree Tree(n);
    for(int i = 2 ; i <= n ; i++){
        int boss_num;
        cin >> boss_num;
        Tree.add_employee(i, boss_num);
    }
 
    Tree.travel_tree();
    Tree.output();
}
