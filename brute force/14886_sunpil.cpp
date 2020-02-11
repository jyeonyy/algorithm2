#include <iostream>
#include <stack>
using namespace std;
int cal[4];
int main()
{
    int N;
    stack< int > s ;
    cin>>N;
    for(int i = 0 ; i < N ; i++)
    {
        int tmp;
        cin>>tmp;
        s.push(tmp);
    }

    for(int i = 0 ; i < 4; i++)
    {
        cin >> cal[i]
    }

    return 0;
}