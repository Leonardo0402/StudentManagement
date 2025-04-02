//
// Created by 20385 on 2025/4/2.
//

#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LEN 50
#define MAX_STUDENTS 100

typedef struct Student {
    int id; // 学号
    char name[NAME_LEN]; // 姓名
    char gender[10]; // 性别
    int age;
    float score;
    char className[NAME_LEN]; // 班级
    struct Student* next;
}Student;

Student* createStudent(int id, const char* name, const char* gender, int age, float score, const char* className);
void printStudent(const Student* s);

#endif
