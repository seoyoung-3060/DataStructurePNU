#include <bits/stdc++.h>
using namespace std;
deque<queue<int> > board_list;//대기list
vector<int> airplane;//이륙list
int N;
void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        queue<int> temp;
        int inp;
        while(true){
            cin >> inp;
            if(inp==0) break;
            temp.push(inp);
        } //input ok!
        board_list.push_back(temp);
    }
}

void Airport(){
    bool check = true;
    while(!board_list.empty()){
        vector<pair<int, int> > front_comp;
        for(int i=0; i<N; i++) if(!board_list[i].empty()) front_comp.push_back(make_pair(board_list[i].front(),i));
        if(front_comp.empty()) break;
        sort(front_comp.begin(),front_comp.end());//오름차순정렬
        // cout << "front comp = " << front_comp[0].first << " " << front_comp[0].second << endl; //checking
        airplane.push_back(front_comp[0].first);
        board_list[front_comp[0].second].pop();
    }
}
void Output(){
    for(auto x: airplane){
        cout << x << endl;
    }
}
int main(){
    Input();
    Airport();
    Output();
    return 0;
}