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
    snprintf(newStudent->name, NAME_LEN, "%s", name);
    snprintf(newStudent->gender, sizeof(newStudent->gender), "%s", gender);
    newStudent->age = age;
    newStudent->score = score;
    snprintf(newStudent->className, NAME_LEN, "%s", className);
    newStudent->next = NULL;
    return newStudent;
}

void printStudent(const Student* s)
{
    if(!s)  return ;
    printf("学号：%d\n", s->id);
    printf("姓名：%s\n", s->name);
    printf("性别：%s\n", s->gender);
    printf("年龄：%d\n", s->age);
    printf("成绩：%.2f\n", s->score);
    printf("班级：%s\n", s->className);
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
    Student* curr = *head;
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
    const Student* curr = head;
    while(curr)
    {
        if(curr->id == id)
        {
            printStudent(curr);
            return ;
        }
        curr = curr->next;
    }
    printf("未找到学号\n");
}

void saveToFile(const Student* head, const char* filename)
{
    FILE* fp = fopen(filename, "w");
    if(!fp)
    {
        perror("文件打开失败");
        return ;
    }
    const Student* curr = head;
    while(curr)
    {
        fprintf(fp, "%d %s %s %d %.2f %s\n", curr->id, curr->name, curr->gender, curr->age, curr->score, curr->className);
        curr = curr->next;
    }
    fclose(fp);
    printf("数据已保存到文件 %s。\n", filename);
}
void loadFromFile(Student** head, const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if(!fp) return ;
    int id, age;
    float score;
    char name[NAME_LEN], gender[10], className[NAME_LEN];
    while(fscanf(fp, "%d %49s %9s %d %f %49s", &id, name, gender, &age, &score, className) == 6)
    {
        Student* newStudent = createStudent(id, name, gender, age, score, className);
        if(*head == NULL)
        {
            *head = newStudent;
        }
        else
        {
            Student* temp = *head;
            while(temp->next)   temp = temp->next;
            temp->next = newStudent;
        }
    }
    fclose(fp);
    printf("数据已从文件 %s加载。\n", filename);
}

void sortStudentByScore(Student** head)
{
    if(!head || *head)  return ;
    Student *i, *j;
    for(i = *head; i != NULL; i++)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(j->score > i->score)
            {
                Student *temp = i;
                *i = *j;
                *j = *temp;
                Student* tmpNext = i->next;
                i->next = j->next;
                j->next = tmpNext->next;
            }
        }
    }
    printf("已经按照成绩降序排列");
}

void searchStudentByName(const Student* head, const char* keyword)
{
    const Student* curr = head;
    int found = 0;
    while(curr)
    {
        if(strstr(curr->name, keyword))
        {
            printStudent(curr);
            found = 1;
        }
        curr = curr->next;
    }
    if(found)
    {
        printf("未找到包含名字的关键字 \"s\"的姓名\n", keyword);
    }
}