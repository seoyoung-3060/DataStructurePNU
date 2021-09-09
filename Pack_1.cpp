#include <bits/stdc++.h>
using namespace std;
void findMax(int W[], int H[], int *max, int *second, int *max_idx, int *second_idx, int *last_idx, int *f_h, int *s_h){
    for(int i=0; i<3; i++) {
        cin >> W[i] >> H[i];
        if(*max <= W[i] && W[i] >= H[i]) {
            *max = W[i]; *max_idx = i; *f_h = H[i];
        } else if(*max <= H[i] && W[i] <= H[i]){
            *max = H[i]; *max_idx = i; *f_h = W[i]; 
        }
    }
    for(int i=0; i<3; i++){
        if(i == *max_idx) i++;
        if(*second <= W[i] && H[i] <= W[i]) {
            *second = W[i]; *second_idx = i; *s_h = H[i];
        } else if(*second <= H[i] && W[i] <= H[i]){
            *second = H[i]; *second_idx = i; *s_h = W[i];
        }
    }

    if(*max_idx + *second_idx == 1) *last_idx = 2;
    else if(*max_idx + *second_idx == 2) *last_idx = 1;
    else *last_idx = 0;
}

int main(){
    int W[3], H[3], max, second, last, max_idx, second_idx, last_idx, max_h, second_h, last_h, result = 0;
    findMax(W, H, &max, &second, &max_idx, &second_idx, &last_idx, &max_h, &second_h);
    
    if(W[last_idx] >= H[last_idx]) { last = W[last_idx]; last_h = H[last_idx];}
    else { last = H[last_idx]; last_h = W[last_idx]; }

    if(max >= second + last) {
        if(second_h >= last_h) result = max*max + (max_h+second_h)*(max_h+second_h);
        else result = max*max + (max_h+last_h)*(max_h+last_h);
    } else {
        if(second_h >= last_h) result = (second+last)*(second+last) + (max_h+second_h)*(max_h+second_h);
        else result= (second+last)*(second+last) + (max_h+last_h)*(max_h+last_h);
    }

    cout << result;
}