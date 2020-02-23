#include <stdio.h>



int main()
{
    int arr[1000001] ={0,};
    int n;
    int i = 1;
       scanf("%d",&n);
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    while(i <= n)
    {
        if(arr[i]!=0)
        {
            if(i*3 <= 1000000&& (arr[i*3] == 0  || arr[i*3] > arr[i] +1))
                arr[i*3] = arr[i] +1;
            if(i*2 <=1000000 && (arr[i*2] ==0 || arr[i*2]> arr[i] +1 ))
                arr[i*2] = arr[i] +1;
            if(i+1 <=1000000 && (arr[i+1] ==0 || arr[i+1] > arr[i] +1))
                arr[i+1] = arr[i] +1;
        }
        i++;
    }


    printf("%d\n",arr[n]);


    return 0;
}