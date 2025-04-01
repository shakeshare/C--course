#include <stdio.h> 
   
int main() { 
        int a = 5;              // 二进制表示为 0101 
        int b = 3;              // 二进制表示为 0011 
        int c; 
   
        // 按位与操作 
       c = a & b;              // 结果为 0001，即 1 
       printf("a & b = %d\n", c); 
   
        // 按位或操作 
       c = a | b;              // 结果为 0111，即 7 
       printf("a | b = %d\n", c); 
   
        // 按位异或操作 
       c = a ^ b;              // 结果为 0110，即 6 
       printf("a ^ b = %d\n", c); 
   
        // 按位取反操作 
       c = ~a;                    // 结果为  ......1010，取决于 
       printf("~a = %d\n", c); 
   
        // 左移操作 
       c = a << 1;            // 结果为 1010，即 10 (5*2) 
       printf("a << 1 = %d\n", c); 
   
        // 右移操作（有符号数） 
       c = a >> 1;            // 结果为 0010，即 2 (5/2) 
       printf("a >> 1 = %d\n", c); 
   
        return 0; 
} 