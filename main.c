#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main()
{
    Student* head = NULL;
    int choice, id;

    while (1) {
        printf("\n=== ѧ������ϵͳ ===\n");
        printf("1. ���ѧ��\n");
        printf("2. �鿴ȫ��ѧ��\n");
        printf("3. ɾ��ѧ��\n");
        printf("4. �޸�ѧ��\n");
        printf("5. ��ѯѧ��\n");
        printf("0. �˳�\n");
        printf("��ѡ�����: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&head);
                break;
            case 2:
                printAllStudents(head);
                break;
            case 3:
                printf("����Ҫɾ����ѧ��: ");
                scanf("%d", &id);
                deleteStudentById(&head, id);
                break;
            case 4:
                printf("����Ҫ�޸ĵ�ѧ��: ");
                scanf("%d", &id);
                modifyStudentById(head, id);
                break;
            case 5:
                printf("����Ҫ��ѯ��ѧ��: ");
                scanf("%d", &id);
                searchStudentById(head, id);
                break;
            case 0:
                printf("��лʹ�ã��ټ���\n");
                exit(0);
            default:
                printf("��Чѡ����������롣\n");
        }
    }
    return 0;
}
