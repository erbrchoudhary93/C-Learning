#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

} Node;


typedef struct
{
    Node *head;
    Node *tail;

} DoublyList;


/* =========================
   INPUT
   ========================= */

int read_int(const char *prompt, int *value)
{
    char buffer[100];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 0;
    }

    char *end;

    errno = 0;

    long number = strtol(buffer, &end, 10);

    if (end == buffer)
    {
        printf("Invalid input.\n");
        return 0;
    }

    while (*end == ' ' ||
           *end == '\t' ||
           *end == '\n')
    {
        end++;
    }

    if (*end != '\0')
    {
        printf("Invalid input. Enter only a number.\n");
        return 0;
    }

    if (errno == ERANGE ||
        number < INT_MIN ||
        number > INT_MAX)
    {
        printf("Number out of range.\n");
        return 0;
    }

    *value = (int)number;

    return 1;
}


/* =========================
   INIT
   ========================= */

void init_list(DoublyList *list)
{
    list->head = NULL;
    list->tail = NULL;
}


/* =========================
   INSERT FRONT
   ========================= */

int insert_front(DoublyList *list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;

    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL)
    {
        list->head->prev = new_node;
    }
    else
    {
        /*
         * Empty list.
         * New node is both head and tail.
         */
        list->tail = new_node;
    }

    list->head = new_node;

    return 1;
}


/* =========================
   INSERT END
   ========================= */

int insert_end(DoublyList *list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;

    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL)
    {
        list->tail->next = new_node;
    }
    else
    {
        /*
         * Empty list.
         * New node is both head and tail.
         */
        list->head = new_node;
    }

    list->tail = new_node;

    return 1;
}


/* =========================
   INSERT AT INDEX
   ========================= */

int insert_at(DoublyList *list, int index, int value)
{
    if (index < 0)
    {
        printf("Invalid index.\n");
        return 0;
    }

    if (index == 0)
    {
        return insert_front(list, value);
    }

    Node *current = list->head;

    /*
     * We need node at index - 1.
     */
    for (int i = 0; i < index - 1; i++)
    {
        if (current == NULL)
        {
            printf("Invalid index.\n");
            return 0;
        }

        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid index.\n");
        return 0;
    }

    /*
     * If inserting after the current tail,
     * we can use insert_end().
     */
    if (current == list->tail)
    {
        return insert_end(list, value);
    }

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;

    new_node->prev = current;
    new_node->next = current->next;

    current->next->prev = new_node;
    current->next = new_node;

    return 1;
}


/* =========================
   DELETE FRONT
   ========================= */

int delete_front(DoublyList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    Node *temp = list->head;

    /*
     * Single node
     */
    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;

        free(temp);

        return 1;
    }

    list->head = list->head->next;

    list->head->prev = NULL;

    free(temp);

    return 1;
}


/* =========================
   DELETE END
   ========================= */

int delete_end(DoublyList *list)
{
    if (list->tail == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    Node *temp = list->tail;

    /*
     * Single node
     */
    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;

        free(temp);

        return 1;
    }

    list->tail = list->tail->prev;

    list->tail->next = NULL;

    free(temp);

    return 1;
}


/* =========================
   DELETE AT INDEX
   ========================= */

int delete_at(DoublyList *list, int index)
{
    if (index < 0)
    {
        printf("Invalid index.\n");
        return 0;
    }

    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    if (index == 0)
    {
        return delete_front(list);
    }

    Node *current = list->head;

    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            printf("Invalid index.\n");
            return 0;
        }

        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid index.\n");
        return 0;
    }

    /*
     * If current is tail,
     * use delete_end().
     */
    if (current == list->tail)
    {
        return delete_end(list);
    }

    current->prev->next = current->next;

    current->next->prev = current->prev;

    free(current);

    return 1;
}


/* =========================
   SEARCH
   ========================= */

int search(DoublyList *list, int target)
{
    Node *current = list->head;

    int index = 0;

    while (current != NULL)
    {
        if (current->data == target)
        {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}


/* =========================
   LENGTH
   ========================= */

int length(DoublyList *list)
{
    int count = 0;

    Node *current = list->head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}


/* =========================
   PRINT FORWARD
   ========================= */

void print_forward(DoublyList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = list->head;

    printf("\nForward: ");

    while (current != NULL)
    {
        printf("%d", current->data);

        if (current->next != NULL)
        {
            printf(" <-> ");
        }

        current = current->next;
    }

    printf(" <-> NULL\n");
}


/* =========================
   PRINT BACKWARD
   ========================= */

void print_backward(DoublyList *list)
{
    if (list->tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = list->tail;

    printf("\nBackward: ");

    while (current != NULL)
    {
        printf("%d", current->data);

        if (current->prev != NULL)
        {
            printf(" <-> ");
        }

        current = current->prev;
    }

    printf(" <-> NULL\n");
}


/* =========================
   CLEAR LIST
   ========================= */

void clear_list(DoublyList *list)
{
    Node *current = list->head;

    while (current != NULL)
    {
        Node *temp = current;

        current = current->next;

        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
}


/* =========================
   PRINT INFO
   ========================= */

void print_info(DoublyList *list)
{
    printf("\n========== LIST INFO ==========\n");

    printf("Length : %d\n", length(list));

    if (list->head != NULL)
    {
        printf("Head   : %d\n", list->head->data);
    }
    else
    {
        printf("Head   : NULL\n");
    }

    if (list->tail != NULL)
    {
        printf("Tail   : %d\n", list->tail->data);
    }
    else
    {
        printf("Tail   : NULL\n");
    }

    printf("===============================\n");
}


/* =========================
   MENU
   ========================= */

void print_menu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("       DOUBLY LINKED LIST V2\n");
    printf("========================================\n");

    printf("1.  Insert Front\n");
    printf("2.  Insert End\n");
    printf("3.  Insert At Index\n");
    printf("4.  Delete Front\n");
    printf("5.  Delete End\n");
    printf("6.  Delete At Index\n");
    printf("7.  Search\n");
    printf("8.  Length\n");
    printf("9.  Print Forward\n");
    printf("10. Print Backward\n");
    printf("11. Clear List\n");
    printf("12. List Info\n");
    printf("0.  Exit\n");

    printf("========================================\n");
}


/* =========================
   MAIN
   ========================= */

int main(void)
{
    DoublyList list;

    init_list(&list);

    int choice;
    int value;
    int index;
    int result;

    while (1)
    {
        print_menu();

        if (!read_int("Enter choice: ", &choice))
        {
            continue;
        }

        switch (choice)
        {
            case 1:

                if (!read_int("Enter value: ", &value))
                    break;

                if (insert_front(&list, value))
                {
                    printf("Inserted at front.\n");
                }

                break;


            case 2:

                if (!read_int("Enter value: ", &value))
                    break;

                if (insert_end(&list, value))
                {
                    printf("Inserted at end.\n");
                }

                break;


            case 3:

                if (!read_int("Enter index: ", &index))
                    break;

                if (!read_int("Enter value: ", &value))
                    break;

                if (insert_at(&list, index, value))
                {
                    printf("Inserted successfully.\n");
                }

                break;


            case 4:

                if (delete_front(&list))
                {
                    printf("Front deleted.\n");
                }

                break;


            case 5:

                if (delete_end(&list))
                {
                    printf("End deleted.\n");
                }

                break;


            case 6:

                if (!read_int("Enter index: ", &index))
                    break;

                if (delete_at(&list, index))
                {
                    printf("Node deleted.\n");
                }

                break;


            case 7:

                if (!read_int("Enter value to search: ", &value))
                    break;

                result = search(&list, value);

                if (result == -1)
                {
                    printf("Value not found.\n");
                }
                else
                {
                    printf("Value found at index %d.\n", result);
                }

                break;


            case 8:

                printf("Length: %d\n", length(&list));

                break;


            case 9:

                print_forward(&list);

                break;


            case 10:

                print_backward(&list);

                break;


            case 11:

                clear_list(&list);

                printf("List cleared.\n");

                break;


            case 12:

                print_info(&list);

                break;


            case 0:

                clear_list(&list);

                printf("Program terminated.\n");

                return 0;


            default:

                printf("Invalid choice. Enter 0-12.\n");
        }
    }
}