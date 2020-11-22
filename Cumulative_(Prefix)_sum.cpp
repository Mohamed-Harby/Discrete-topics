#include<bits/stdc++.h>
using namespace std;
#define lol ios_base::sync_with_stdio(0);cin.tie(0);

void insert_Zeros(deque<deque<int>> & v){
    int s = v.size();
    for (int i = 0; i < s; i++)  v[i].push_front(0); 
    int l = v[0].size();
    deque<int> d (l, 0);
    v.push_front(d);
}

void Accumealtor(deque<deque<int>>& deq){
    for (int i = 1; i < deq.size(); i++){
        for (int j = 1; j < deq[0].size(); j++){
            deq[i][j] += deq[i][j-1];
        }
    }
    
    for (int j = 1; j < deq[0].size(); j++){
        for (int i = 1; i < deq.size(); i++){
            deq[i][j] += deq[i-1][j];
        }
    }
}

long long sum_range(int Sx,int Sy,int Ex,int Ey,deque<deque<int>>& deq){
    deque<deque<int>> temp = deq;
    insert_Zeros(temp);
    Accumealtor(temp);
    return temp[Ex][Ey] - temp[Ex][Sy-1] - temp[Sx-1][Ey] + temp[Sx-1][Sy-1];
}

int main(){
    lol
    deque<deque<int>> deq = 
    {
        {1,2,3,4},
        {2,4,6,8},
        {1,3,5,7},
    };
    long long res = sum_range(2,2,3,4,deq);
    cout << "RES IS : " << res << endl;
    
}
 
