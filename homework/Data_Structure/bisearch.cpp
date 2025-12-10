#include <stdio.h> 
int biSearch(int n, int a[], int key)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
       printf("%d ", a[mid]); 
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

//在 n 个整数的有序数组a中查找key，若成功则返回元素下标，否则返回-1 
int main() {//评测系统中使用这里定义的main函数进行测试 
int i, n, key; 
int a[101]; 
scanf("%d%d",&n,&key); 
for(i=0;i<n;i++) 
scanf("%d", &a[i]); 
int position = biSearch(n, a, key); 
if (-1 == position)    
//查找失败 
printf("[Not found]\n"); 
else  
printf("[Found at index %d]\n",position);    
return 0; 
} 