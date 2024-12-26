#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//struct student {
//    int id;
//    char *name;
//    int age;
//};

void* student_clone(void* elem){
    struct student *s = (struct student*)malloc(sizeof(struct student));
    if (s == NULL){
        return NULL;
    }
    struct student *tmp = (struct student*)elem;
    s->id = tmp->id;
    s->name = (char*)malloc(strlen(tmp->name) + 1);
    if (s->name == NULL){
        free(s);
        return NULL;
    }
    strcpy(s->name, tmp->name);
    s->age = tmp->age;
    return s;
}

void student_destroy(void* elem){
    struct student *s = (struct student*)elem;
    free(s->name);
    free(s);
}

void student_print(void* elem){
    struct student *s = (struct student*)elem;
    printf("student name: %s, age: %d, id: %d.\n", s->name, s->age, s->id);
}