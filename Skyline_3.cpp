#include <bits/stdc++.h>
using namespace std;
#define case0 get<0>(input[i])+get<2>(input[i])<get<0>(input[i+1])
#define case1 get<1>(input[i])<=get<1>(input[i+1])
#define case2 get<0>(input[i+1])+get<2>(input[i+1])<=get<0>(input[i])+get<2>(input[i])
#define case3 get<0>(input[i])+get<2>(input[i])<get<0>(input[i+2])
#define push1(n,i) skyline.push_back(get<n>(input[i]))
#define push2(n,i,N,I) skyline.push_back(get<n>(input[i])-get<N>(input[I]))
#define pushM(n,i) skyline.push_back(get<n>(input[i])*-1)
vector<tuple<int, int, int>> input;vector<int> skyline;int N, check, num=0;
void getInput(){
    cin >> N;
    for(int i=0; i<N; i++){int one, two, three;cin >> one >> two >> three;input.push_back(make_tuple(one, two, three));
    }sort(input.begin(),input.end());
}
void getSkyline(){
    push1(0,0);push1(1,0);
    for(int i=0;i<N-1;i++) {
        if(case0)num=0;else num=1;
        switch(num){
        case 0:
            push1(2,i);pushM(2,i);skyline.push_back(get<0>(input[i+1])-(get<0>(input[i])+get<2>(input[i])));push1(1,i+1);
            break;
        case 1:
            if(case1){
                if(case2){
                    skyline.push_back(get<0>(input[i+1])-(get<0>(input[i-1])+get<2>(input[i-1])));push2(1,i+1,1,i);push1(2,i+1);push2(1,i,1,i+1);
                    if(case3&&i<N-2){
                        skyline.push_back(get<0>(input[i])+get<2>(input[i])-(get<0>(input[i+1])+get<2>(input[i+1])));pushM(1,i);
                        skyline.push_back(get<0>(input[i+2])-(get<0>(input[i])+get<2>(input[i])));push1(1,i+2);i++;check=1;
                    }else{
                        if(i<N-2){skyline.push_back(get<1>(input[i+2])-(get<0>(input[i])+get<0>(input[i+1])+get<2>(input[i+1])));push2(1,i+2,1,i);i++;}
                    }
                }else{push2(0,i+1,0,i);push2(1,i+1,1,i);}
            }else{
                if(case2){check = 1;
                    swap(get<0>(input[i]),get<0>(input[i+1]));swap(get<1>(input[i]),get<1>(input[i+1]));swap(get<2>(input[i]),get<2>(input[i+1]));
                }else {push1(2,i);push2(1,i+1,1,i);}
            } break;
        default:
            break;
        }
    }
    if(check){push1(2,N-1);pushM(2, N-1);
    }else{skyline.push_back((get<0>(input[N-2])+get<2>(input[N-2]))-(get<0>(input[N-1])+get<2>(input[N-1])));pushM(1,N-2);}
}
void printSkyline(){for(int i=0; i<skyline.size(); i++) cout<<skyline[i]<<" ";}
int main(){
    getInput();
    getSkyline();
    printSkyline();
    return 0;
}