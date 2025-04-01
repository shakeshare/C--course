#include <stdio.h> 
 
int main(int argc, char *argv[]) { 
// 打印参数数量 
printf("参数数量: %d\n", argc); 
// 打印每个参数 
for (int i = 0; i < argc; i++) { 
printf("参数 %d: %s\n", i, argv[i]); 
} 
return 0; 
}