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