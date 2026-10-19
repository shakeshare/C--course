# Contact Manager

课程大作业：一个使用 C++ 编写的联系人记录管理程序。

## 目录

- `src/txl.cpp`：源代码
- `data/Saving file.txt`：示例数据

## 编译与运行

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra src\txl.cpp -o build\contact-manager.exe
build\contact-manager.exe
```
