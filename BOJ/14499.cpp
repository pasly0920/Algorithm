#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> map;
vector<int> dice;  

//   0
// 4 1 5
//   2
//   3

int getNextDiceBase(int nowDiceBase, int direction) {
    switch(nowDiceBase) {
        case 0:
            if(direction == 1)
                return 5;
            else if(direction == 2)
                return 4;
            else if (direction == 3)
                return 3;
            else
                return 1;
        case 1:
            if(direction == 1)
                return 5;
            else if(direction == 2)
                return 4;
            else if (direction == 3)
                return 0;
            else
                return 2;
        case 2:
            if(direction == 1)
                return 5;
            else if(direction == 2)
                return 4;
            else if (direction == 3)
                return 1;
            else
                return 3;
        case 3:
            if(direction == 1)
                return 5;
            else if(direction == 2)
                return 4;
            else if (direction == 3)
                return 2;
            else
                return 0;
        case 4:
            if(direction == 1)
                return 1;
            else if(direction == 2)
                return 5;
            else if (direction == 3)
                return 0;
            else
                return 2;
        case 5:
            if(direction == 1)
                return 4;
            else if(direction == 2)
                return 1;
            else if (direction == 3)
                return 0;
            else
                return 2;
    }
}

int getDiceTop(int diceBase) {
    switch (diceBase)
    {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5: 
            return 4;
    }
}

int main(){
    int N, M, x, y, K;
    cin>>N>>M>>y>>x>>K;

    map.assign(N, vector<int>(M, 0));
    dice.assign(6, 0);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>map[i][j];
    
    int C;
    int nowY = 0;
    int nowX = 0;
    int nowDiceBase = 1;
    for(int i=0; i<K; i++){
        cin>>C;

        int nextY = nowY;
        int nextX = nowX;
        
        switch (C)
        {
            case 1:
                nextX++;
                break;
            case 2:
                nextX--;
                break;
            case 3:
                nextY--;
                break;
            case 4:
                nextY++;
                break;
        }

        if(nextY >= N || nextY < 0 || nextX >=M || nextX < 0)
            continue;
        
        int nextDiceBase = getNextDiceBase(nowDiceBase, C);
        if(map[nextY][nextX] == 0){
            map[nextY][nextX] = dice[nextDiceBase];
        }else{
            dice[nextDiceBase] = map[nextY][nextX];
            map[nextY][nextX] = 0;
        }   
        cout<<dice[getDiceTop(nextDiceBase)]<<'\n';

        nowY = nextY;
        nowX = nextX;
        nowDiceBase = nextDiceBase;
    }
}