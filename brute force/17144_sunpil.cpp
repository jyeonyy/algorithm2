#include <iostream>
#include <vector>
using namespace std;
int posX[] = {-1,0,1,0};
int posY[] = {0,1,0,-1};

int nearCount(vector< vector<int> > &table ,int i, int j)
{
    int result = 0;
    for(int  i =0 ; i < 4 ; i++)
    {
        if(posX[i]+i > 0 && posX[i]+i <table[0].size() && posY[i]+j > 0 && posY[i]+j <table.size())
        {
            if(table[posX[i]+i][posY[i]+j]!=-1)
                result++;

        }
    }
    return result;
}

void dust(vector< vector<int> > &table)
{
vector< vector<int> > tmp;
tmp.resize(table.size());
for(int  i = 0 ; i < table.size();i++)
    tmp[i].resize(table[0].size());
//주위
for(int  i = 0 ; i < table.size() ; i++)
{
    for(int  j = 0 ; j < table[0].size() ; j++)
    {
    
    for(int  i =0 ; i < 4 ; i++)
    {
        if(posX[i]+i > 0 && posX[i]+i <table[0].size() && posY[i]+j > 0 && posY[i]+j <table.size())
        {
            if(table[posX[i]+i][posY[i]+j]!=-1)
                tmp[posX[i]+i][posY[i]+j] += table[i][j]/5;
            else
            {
                tmp[posX[i]+i][posY[i]+j] = -1;
            }
        }
    }
    }
}
//줄인 값 더하기 
for(int  i = 0 ; i < table.size() ; i++)
{
    for(int  j = 0 ; j < table[0].size() ; j++)
    {
        if(table[i][j]!= -1)
        {
            tmp[i][j] += (table[i][j] - (table[i][j]/5)*nearCount(table,i,j));
        }
    }
}
table = tmp;
}
void aircleaner(vector< vector<int> > &table,const pair<int,int>  &f,const pair<int,int>  &s)
{
//반시계
int i = f.first;
int j = f.second;
do{



}while(i == f.first && j == f.second)



//시계


}
int calSum(vector< vector<int> > &table)
{
int result = 0;
    for(int  i= 0 ; i < table.size();i++)
    {
        for(int j = 0 ; j < table[0].size();j++)
        {
            if(table[i][j]!=-1)
                result += table[i][j];
        }
    }
    return result;
}
int main()
{
int R,C,T;
vector< vector<int> > table;
pair<int,int> cleaner[2];
int cleanerCount = 0;
cin>>R>>C>>T;
for(int i = 0 ; i <R ; i++ )
{
    vector<int> tmp;
    for(int  j = 0 ; j < C ;j++)
    {
        int num;
        cin>>num;
        if(num == -1)
        {
            cleaner[cleanerCount].first = i;
            cleaner[cleanerCount].second = j;
            cleanerCount++;
        }
        tmp.push_back(num);
    }
    table.push_back(tmp);
}
while(T > 0)
{
    //먼지 계산
    dust(table);
    // 공기 청정기
    aircleaner(table,cleaner[0],cleaner[1]);
    T--;
}
cout<<calSum(table)<<endl;
return 0;
}
