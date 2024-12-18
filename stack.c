typedef void * elem_t;
typedef elem_t (*clone_t)(elem_t e);
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

elem_t clone_t(elem_t e) {
    char *original = (char *)e;
    char *copy = malloc(strlen(original) + 1);
    if (copy) {
        strcpy(copy, original);
    }
    return (elem_t)copy;
}

void destroy_t(elem_t e) {
    free(e);
}

void print_t(elem_t e) {
    printf("%s\n", (char *)e);
}


