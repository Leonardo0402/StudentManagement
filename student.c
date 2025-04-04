//
// Created by 20385 on 2025/4/2.
//

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student* createStudent(int id, const char* name, const char* gender, int age, float score, const char* className)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if(!newStudent)
    {
        fprintf(stderr, "内存分配失败!\n");
        exit(EXIT_FAILURE);
    }
    newStudent->id = id;
    strncpy(newStudent->name, name, NAME_LEN);
    strncpy(newStudent->gender, gender, sizeof(newStudent->gender));
    newStudent->age = age;
    newStudent->score = score;
    strncpy(newStudent->className, className, NAME_LEN);
    newStudent->next = NULL;
    return newStudent;
}

void printStudent(const Student* s)
{
    if(!s)  return ;
    printf("学号：%d\n", s->id);
    printf("姓名：%d\n", s->name);
    printf("性别：%d\n", s->gender);
    printf("年龄：%d\n", s->age);
    printf("成绩：%d\n", s->score);
    printf("班级：%d\n", s->className);
    printf("------------------------\n");
}

void addStudent(Student** head)
{
    int id, age;
    float score;
    char name[NAME_LEN], gender[10], className[NAME_LEN];

    printf("请输入学号: ");
    scanf("%d", &id);
    printf("请输入姓名: ");
    scanf("%s", name);
    printf("请输入性别: ");
    scanf("%s", gender);
    printf("请输入年龄: ");
    scanf("%d", &age);
    printf("请输入成绩: ");
    scanf("%f", &score);
    printf("请输入班级: ");
    scanf("%s", className);

    Student* newStudent = createStudent(id, name, gender, age, score, className);

    if(*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        Student* temp = *head;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("学生添加成功！\n");
}

void printAllStudents(const Student* head)
{
    if(!head)
    {
        printf("当前无学生信息。\n");
        return ;
    }
    const Student* temp = head;
    while(temp)
    {
        printStudent(temp);
        temp = temp->next;
    }
}

void deleteStudentById(Student** head, int id)
{
    Student* curr = head;
    while(curr)
    {
        if(curr->id == id)
        {
            printf("输入新姓名: "); scanf("%s", curr->name);
            printf("输入新性别: "); scanf("%s", curr->gender);
            printf("输入新年龄: "); scanf("%d", &curr->age);
            printf("输入新成绩: "); scanf("%f", &curr->score);
            printf("输入新班级: "); scanf("%s", curr->className);
            printf("修改成功。\n");
            return;
        }
        curr = curr->next;
    }
    printf("未找到学号为 %d 的学生。\n", id);
}
void modifyStudentById(Student* head, int id)
{
    Student* curr = head;
    while(curr)
    {
        if(curr->id = id)
        {
            printf("输入新姓名: "); scanf("%s", curr->name);
            printf("输入新性别: "); scanf("%s", curr->gender);
            printf("输入新年龄: "); scanf("%d", &curr->age);
            printf("输入新成绩: "); scanf("%f", &curr->score);
            printf("输入新班级: "); scanf("%s", curr->className);
            printf("修改成功。\n");
            return;
        }
        curr = curr->next;
    }
    printf("未找到学号\n");
}
void searchStudentById(const Student* head, int id)
{
    Student* curr = head;
    while(curr)
    {
        if(curr->id = id)
        {
            printStudent(curr);
            return ;
        }
        curr = curr->next;
    }
    printf("未找到学号\n");
}
