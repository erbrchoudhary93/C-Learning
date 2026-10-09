
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} CircularList;

void init_list(CircularList *list) {
    list->head = NULL;
    list->tail = NULL;
}

int insert_front(CircularList *list, int value) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        return 0;
    }

    node->data = value;

    if (list->head == NULL) {
        node->next = node;
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head = node;
        list->tail->next = list->head;
    }

    return 1;
}

int insert_end(CircularList *list, int value) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        return 0;
    }

    node->data = value;

    if (list->head == NULL) {
        node->next = node;
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->tail->next = node;
        list->tail = node;
    }

    return 1;
}

int delete_front(CircularList *list) {
    if (list->head == NULL) {
        return 0;
    }

    Node *temp = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }

    free(temp);
    return 1;
}

int delete_end(CircularList *list) {
    if (list->head == NULL) {
        return 0;
    }

    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return 1;
    }

    Node *current = list->head;

    while (current->next != list->tail) {
        current = current->next;
    }

    Node *temp = list->tail;

    current->next = list->head;
    list->tail = current;

    free(temp);
    return 1;
}

void display(const CircularList *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    const Node *current = list->head;

    printf("Circular List: ");

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("(back to head)\n");
}

int count_nodes(const CircularList *list) {
    if (list->head == NULL) {
        return 0;
    }

    int count = 0;
    const Node *current = list->head;

    do {
        count++;
        current = current->next;
    } while (current != list->head);

    return count;
}

void clear_list(CircularList *list) {
    while (list->head != NULL) {
        delete_front(list);
    }
}

int main(void) {
    CircularList list;
    init_list(&list);

    int choice;
    int value;

    while (1) {
        printf("\n--- Circular Linked List Manager ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete from front\n");
        printf("4. Delete from end\n");
        printf("5. Display list\n");
        printf("6. Count nodes\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1:
            case 2:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid value. Exiting.\n");
                    clear_list(&list);
                    return 1;
                }

                if (choice == 1) {
                    if (insert_front(&list, value)) {
                        printf("Inserted at front.\n");
                    } else {
                        printf("Memory allocation failed.\n");
                    }
                } else {
                    if (insert_end(&list, value)) {
                        printf("Inserted at end.\n");
                    } else {
                        printf("Memory allocation failed.\n");
                    }
                }
                break;

            case 3:
                if (delete_front(&list)) {
                    printf("First node deleted.\n");
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 4:
                if (delete_end(&list)) {
                    printf("Last node deleted.\n");
                } else {
                    printf("List is empty.\n");
                }
                break;

            case 5:
                display(&list);
                break;

            case 6:
                printf("Total nodes: %d\n", count_nodes(&list));
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    clear_list(&list);
    printf("All nodes freed. Goodbye!\n");

    return 0;
}