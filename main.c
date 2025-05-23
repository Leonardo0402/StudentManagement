#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main()
{
    system("chcp 65001");
    Student* head = NULL;
    int choice, id;
    char keyword[NAME_LEN];

    while (1) {
        printf("\n=== 学生管理系统 ===\n");
        printf("1. 添加学生\n");
        printf("2. 查看全部学生\n");
        printf("3. 删除学生\n");
        printf("4. 修改学生\n");
        printf("5. 查询学生\n");
        printf("6. 保存数据到文件\n");
        printf("7. 成绩排序（降序）\n");
        printf("8. 查询学生（姓名模糊）\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&head);
                break;
            case 2:
                printAllStudents(head);
                break;
            case 3:
                printf("输入要删除的学号: ");
                scanf("%d", &id);
                deleteStudentById(&head, id);
                break;
            case 4:
                printf("输入要修改的学号: ");
                scanf("%d", &id);
                modifyStudentById(head, id);
                break;
            case 5:
                printf("输入要查询的学号: ");
                scanf("%d", &id);
                searchStudentById(head, id);
                break;
            case 6:
                saveToFile(head, "students.txt");
                break;
            case 7:
                sortStudentsByScore(&head);
                break;
            case 8:
                printf("输入姓名关键字: ");
                scanf("%s", keyword);
                searchStudentByName(head, keyword);
                break;
            case 0:
                printf("感谢使用，再见！\n");
                exit(0);
            default:
                printf("无效选项，请重新输入。\n");
        }
    }
    return 0;
}
