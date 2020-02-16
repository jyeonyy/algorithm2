#include <iostream>
#include <queue>
using namespace std;
void print(const queue<int> & q);
enum BAT{
    OUT,
    HIT1,
    HIT2,
    HIT3,
    HOMERUN
};
int  batterTable[100][9] = {0,}; //i 는 이닝 j는 타자 순서
int N;
int maxScore = 0;
void calScore(queue<int> & order)
{
int inning = 0;
int score =0;
while(inning < N)
{
int out = 0 ;
vector<int> base(3); //base에는 타자 유무
while(out <3)
{
int better = order.front();
int hit = batterTable[inning][better];
order.pop();
if(hit == OUT)
{
    out++;
}
else if(hit == HIT1)
{
for(int i = 2 ; i >= 0 ; i--)
{
    if(base[i] ==1){
    if(i+1 >2)
        score++;
    else
      base[i+1] =1;

    base[i] = 0;
    } 
}
base[0] = 1;
}
else if(hit == HIT2)
{
for(int i = 2 ; i >= 0 ; i--)
{
      if(base[i] ==1){
    if(i+2 >2)
        score++;
    else
      base[i+2] =1;

    base[i] = 0;
  } 
}
base[1] = 1;

}
else if(hit == HIT3)
{
for(int i = 2 ; i >= 0 ; i--)
{
    if(base[i]==1){
    if(i+3 >2)
        score++;
    else
      base[i+3] =1;

    base[i] = 0; 
    }
}
base[2] = 1;
}
else
{
for(int i = 2 ; i >= 0 ; i--)
{
    if(base[i] == 1)
      {
            score++;
            base[i]=0;
      }
}
 score++; 
}
order.push(better);
}
inning++;
}
if(maxScore < score)
    maxScore = score;
}

int visit[9] ={0,};
void permutation(int i,queue<int> order) //i는 선수 번호
{
 visit[i] = 1;
 order.push(i);

 if(order.size() == 9)
{
    calScore(order);
}
else if(order.size() ==3)
{
    permutation(0,order);
}
else
{
    for(int  k =1  ; k < 9 ; k++)
    {
        if(visit[k] == 0)
            permutation(k,order);

    }
}
visit[i] = 0;
} 
int main()
{
cin>>N;
for(int  i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j < 9 ; j++)
        cin>>batterTable[i][j];
}

for(int i = 1 ; i < 9 ; i++)
{
    queue<int> q;
    permutation(i,q);
}

cout<<maxScore;

return 0;
}



void print(const queue<int> & q)
{
    queue<int> tmp =q;

    while(!tmp.empty())
    {
        cout<<tmp.front()<<" ";
        tmp.pop();
    }
    cout<<endl;



}