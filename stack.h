#include <stdlib.h>
#include <stdbool.h>
#include "common.h"

#ifndef STACK_H
#define STACK_H

typedef struct node node;
typedef struct stack stack;
typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

struct stack* stack_create(size_t capacity, clone_t clone, destroy_t destroy, print_t print);
bool stack_destroy(struct stack *s);
bool stack_push(struct stack *s, elem_t elem);
void stack_pop(struct stack *s);
struct node* stack_peek(struct stack *s);
size_t stack_size(struct stack *s);
bool stack_is_empty(struct stack *s);
size_t stack_capacity(struct stack *s);
void stack_print(struct stack *s);

#endif // STACK_H