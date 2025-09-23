#include <stdio.h>
#include <stdlib.h>

int main()
{
        // 写入数据到文本文件
        FILE *file = fopen("example.txt", "w");
        if (file == NULL)
        {
                perror("无法打开文件");
                return EXIT_FAILURE;
        }

        fprintf(file, "Hello, World!\n");
        fprintf(file, "这是一个文件操作示例。\n");
        fclose(file);

        // 读取数据从文本文件
        file = fopen("example.txt", "r");
        if (file == NULL)
        {
                perror("无法打开文件");
                return EXIT_FAILURE;
        }

        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
                printf("%s", buffer);
        }

        if (feof(file))
        {
                printf("已到达文件末尾。\n");
        }

        fclose(file);
        return EXIT_SUCCESS;
}