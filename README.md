# 学生管理系统（C语言）

本项目为一个基于 C 语言编写的学生信息管理系统，使用链表管理数据，支持基本的增删改查、排序、模糊查询与文件持久化。

---

## ✅ 功能特性

- 添加学生信息
- 删除学生信息（按学号）
- 修改学生信息
- 查询学生（按学号 / 姓名模糊匹配）
- 成绩排序（降序）
- 学生信息显示（列表格式）
- 文件保存 / 加载（`students.txt`）

---

## 📁 文件结构

```
.
├── main.c              // 主函数（菜单、交互）
├── student.c           // 功能实现（链表增删改查、IO等）
├── student.h           // 结构体与函数声明
├── students.txt        // 数据持久化文件（程序自动生成）
└── README.md           // 项目说明文件
```

---

## 🚀 编译与运行

使用 `gcc` 进行编译：

```bash
gcc main.c student.c -o student_sys
./student_sys
```

或者使用 CMake + Ninja：

```bash
mkdir build && cd build
cmake ..
ninja
./StudentManagement.exe
```

---

## 💡 示例

```
=== 学生管理系统 ===
1. 添加学生
2. 查看全部学生
3. 删除学生
4. 修改学生
5. 查询学生（按学号）
6. 保存数据到文件
7. 成绩排序（降序）
8. 查询学生（姓名模糊）
0. 退出
```

---

## 📦 TODO / 拓展方向

- [ ] 添加排序选择：升序 / 按姓名 / 按年龄等
- [ ] 图形界面支持（Win32 / Qt）
- [ ] 网络功能（上传到远程服务器）

---
