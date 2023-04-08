#include <stdio.h>
#include <malloc.h>

struct link {
    int value;
    struct link * next;
};

void link_add(struct link *root, int val) {
    struct link *tmp = root;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(struct link));
    tmp->next->value = val;
}

void link_print(struct link *root) {
    struct link *tmp = root;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        printf("value: %d\n", tmp->value);
    }
}

void link_free(struct link *root) {
    struct link *tmp;
    struct link *pre;
    while (root->next != NULL) {
        tmp = root->next;
        printf("free value: %d\n", tmp->value);
        root->next = tmp->next;
        free(tmp);

    }
}

int main(int argc, char *argv[]) {
    struct link root = {};
    for (int i = 0; i < 10; i++) {
        link_add(&root, i);
    }
    link_print(&root);
    link_free(&root);
    return 0;
}