#ifndef STUDENT_H
#define STUDENT_H


//typedef struct student student;
struct student {
    int id;
    char *name;
    int age;
};

void* student_clone(void* elem);
void student_destroy(void* elem);
void student_print(void* elem);

#endif // STUDENT_H