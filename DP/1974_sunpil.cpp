#include<iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
stack < int > stack ;
vector <int> arr;
int N;
int count = 0 ;
int num = 2;
int max = 0;
vector< string> s;
cin >> N;
for(int i = 0 ; i < N ;i++)
   {
    int tmp;
    cin >> tmp;

    if(max < tmp)
    {
        max =  tmp;
    }
    arr.push_back(tmp);
   }

stack.push(1);
s.push_back("+\n");

while( count < arr.size())
{
if((stack.size() != 0) && (stack.top() == arr[count]))
{
    stack.pop();
  s.push_back("-\n");
    count++;
}
else
{
    stack.push(num);
    s.push_back("+\n");
    num++;

    if(stack.top() > max)
    {
        cout<<"NO"<<endl;
        return 0;
    }

}

}

for(string tmp : s)
    cout<<tmp;

return 0;

}