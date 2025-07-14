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

        void dfs(leaf* current){
            vector<leaf*> order;
            vector<leaf*> stack;
            stack.reserve(num);
            order.reserve(num);
            stack.push_back(employees[1]);
            while(!stack.empty()){
                leaf*now = stack.back();
                order.push_back(now);
                stack.pop_back();
                for (leaf* emp : now->get_sub()){
                    stack.push_back(emp);
                }
            }
            for(int i = order.size()-1; i >= 0; i--){
                leaf* now = order[i];
                int count = 0;
                for(leaf* sub : now->get_sub()){
                    count += 1 + sub->get_subordinates_cout();
                }
                now->set_employee_count(count);
            }
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