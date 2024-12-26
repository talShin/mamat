#include stdlib.h

struct node {
    elem_t data;
    struct node *next;
};

struct stack {
    struct node *top;
    size_t size;
    size_t capacity;
    clone_t clone;
    destroy_t destroy;
    print_t print;
};

// Create a stack, need to provide the capacity of the stack and more
struct stack* stack_create (size_t capacity) {
    stack* s = (stack*)malloc(sizeof(stack));
    if (NULL == s) {
        return NULL;
    }
    s->top = NULL;
    s->size = 0;
    s->capacity = capacity;
    return s;
}

bool stack_destroy (struct stack *s) {
    if (NULL == s) {
        return false;
    }
    while (NULL != s->top) {
        struct node *tmp = s->top;
        s->top = s->top->next;
        s->destroy(tmp->data);
        free(tmp);
    }
    free(s);
    return true;
}

bool stack_push (struct stack *s, elem_t elem) {
    if (NULL == s) {
        return false;
    }
    if (s->size >= s->capacity) {
        return false;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (NULL == new_node) {
        return false;
    }
    new_node->data = s->clone(elem);
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
    return true;
}

void stack_pop (struct stack *s) {
    if (NULL == s || NULL == s->top) {
        return;
    }
    struct node *tmp = s->top;
    s->top = s->top->next;
    s->destroy(tmp->data);
    free(tmp);
    s->size--;
}

node* stack_peek (struct stack *s) {
    if (NULL == s || NULL == s->top) {
        return NULL;
    }
    return s->top;
}

size_t stack_size (struct stack *s) {
    if (NULL == s) {
        return 0;
    }
    return s->size;
}

bool stack_is_empty (struct stack *s) {
    if (NULL == s) {
        return true;
    }
    return 0 == s->size;
}

size_t stack_capacity (struct stack *s) {
    if (NULL == s) {
        return 0;
    }
    return s->capacity;
}

void stack_print (struct stack *s) {
    if (NULL == s) {
        return;
    }
    struct node *tmp = s->top;
    while (NULL != tmp) {
        s->print(tmp->data);
        tmp = tmp->next;
    }
}