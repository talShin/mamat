#include "common.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    elem_t data;
    struct node *next;
};

struct stack{
    struct node *top;
    size_t size;
    size_t capacity;
    clone_t clone;
    destroy_t destroy;
    print_t print;
};

stack* stack_create (size_t capacity, clone_t clone, destroy_t destroy, print_t print){
    stack *s = (stack*)malloc(sizeof(stack));
    if (s == NULL){
        return NULL;
    }
    s->top = NULL;
    s->size = 0;
    s->capacity = capacity;
    s->clone = clone;
    s->destroy = destroy;
    s->print = print;
    return s;
}

bool stack_destroy(stack *s){
    if (s == NULL){
        return false;
    }
    while (s->top != NULL){
        struct node *tmp = s->top;
        s->top = s->top->next;
        s->destroy(tmp->data);
        free(tmp);
    }
    free(s);
    return true;
}

bool stack_push(stack *s, elem_t elem){
    if (s == NULL || s->size == s->capacity){
        return false;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL){
        return false;
    }
    new_node->data = s->clone(elem);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    return true;
}

void stack_pop(stack *s){
    if (s == NULL || s->top == NULL){
        return;
    }
    struct node *tmp = s->top;
    s->top = s->top->next;
    s->destroy(tmp->data);
    free(tmp);
    s->size--;
}

struct node* stack_peek(stack *s){
    if (s == NULL || s->top == NULL){
        return NULL;
    }
    return s->top;
}

size_t stack_size(stack *s){
    if (s == NULL){
        return 0;
    }
    return s->size;
}

bool stack_is_empty(stack *s){
    if (s == NULL){
        return true;
    }
    return s->size == 0;
}

size_t stack_capacity(stack *s){
    if (s == NULL){
        return 0;
    }
    return s->capacity;
}

void stack_print(stack *s){
    if (s == NULL){
        return;
    }
    struct node *tmp = s->top;
    while (tmp != NULL){
        s->print(tmp->data);
        tmp = tmp->next;
    }
}