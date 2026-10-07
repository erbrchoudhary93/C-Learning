#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/* =========================
   NODE
   ========================= */

typedef struct Node
{
    int data;
    struct Node *next;

} Node;


/* =========================
   INPUT FUNCTIONS
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

    /* Check conversion error */
    if (end == buffer)
    {
        printf("Invalid input. Please enter a number.\n");
        return 0;
    }

    /* Check extra characters */
    while (*end == ' ' || *end == '\t' || *end == '\n')
    {
        end++;
    }

    if (*end != '\0')
    {
        printf("Invalid input. Please enter only a number.\n");
        return 0;
    }

    /* Check integer range */
    if (errno == ERANGE ||
        number < INT_MIN ||
        number > INT_MAX)
    {
        printf("Number is out of integer range.\n");
        return 0;
    }

    *value = (int)number;

    return 1;
}


/* =========================
   INSERT FRONT
   ========================= */

int insert_front(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;

    new_node->next = *head;

    *head = new_node;

    return 1;
}


/* =========================
   INSERT END
   ========================= */

int insert_end(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return 1;
    }

    Node *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return 1;
}


/* =========================
   INSERT AT INDEX
   ========================= */

int insert_at(Node **head, int index, int value)
{
    if (index < 0)
    {
        printf("Invalid index.\n");
        return 0;
    }

    if (index == 0)
    {
        return insert_front(head, value);
    }

    Node *current = *head;

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

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    new_node->data = value;

    new_node->next = current->next;

    current->next = new_node;

    return 1;
}


/* =========================
   DELETE FRONT
   ========================= */

int delete_front(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    Node *temp = *head;

    *head = (*head)->next;

    free(temp);

    return 1;
}


/* =========================
   DELETE END
   ========================= */

int delete_end(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        return 1;
    }

    Node *current = *head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    Node *temp = current->next;

    current->next = NULL;

    free(temp);

    return 1;
}


/* =========================
   DELETE AT INDEX
   ========================= */

int delete_at(Node **head, int index)
{
    if (index < 0)
    {
        printf("Invalid index.\n");
        return 0;
    }

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    if (index == 0)
    {
        return delete_front(head);
    }

    Node *current = *head;

    for (int i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {
            printf("Invalid index.\n");
            return 0;
        }

        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Invalid index.\n");
        return 0;
    }

    Node *temp = current->next;

    current->next = temp->next;

    free(temp);

    return 1;
}


/* =========================
   SEARCH
   ========================= */

int search(Node *head, int target)
{
    Node *current = head;

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

int length(Node *head)
{
    int count = 0;

    Node *current = head;

    while (current != NULL)
    {
        count++;

        current = current->next;
    }

    return count;
}


/* =========================
   PRINT LIST
   ========================= */

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;

    printf("\nList: ");

    while (current != NULL)
    {
        printf("%d", current->data);

        if (current->next != NULL)
        {
            printf(" -> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}


/* =========================
   FREE ENTIRE LIST
   ========================= */

void free_list(Node **head)
{
    Node *current = *head;

    while (current != NULL)
    {
        Node *temp = current;

        current = current->next;

        free(temp);
    }

    *head = NULL;
}


/* =========================
   MENU
   ========================= */

void print_menu(void)
{
    printf("\n");
    printf("=================================\n");
    printf("       LINKED LIST MANAGER\n");
    printf("=================================\n");

    printf("1. Insert Front\n");
    printf("2. Insert End\n");
    printf("3. Insert At Index\n");
    printf("4. Delete Front\n");
    printf("5. Delete End\n");
    printf("6. Delete At Index\n");
    printf("7. Search\n");
    printf("8. Get Length\n");
    printf("9. Print List\n");
    printf("10. Clear List\n");
    printf("0. Exit\n");

    printf("=================================\n");
}


/* =========================
   MAIN
   ========================= */

int main(void)
{
    Node *head = NULL;

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
                {
                    break;
                }

                if (insert_front(&head, value))
                {
                    printf("Value inserted at front.\n");
                }

                break;


            case 2:

                if (!read_int("Enter value: ", &value))
                {
                    break;
                }

                if (insert_end(&head, value))
                {
                    printf("Value inserted at end.\n");
                }

                break;


            case 3:

                if (!read_int("Enter index: ", &index))
                {
                    break;
                }

                if (!read_int("Enter value: ", &value))
                {
                    break;
                }

                if (insert_at(&head, index, value))
                {
                    printf("Value inserted successfully.\n");
                }

                break;


            case 4:

                if (delete_front(&head))
                {
                    printf("First node deleted.\n");
                }

                break;


            case 5:

                if (delete_end(&head))
                {
                    printf("Last node deleted.\n");
                }

                break;


            case 6:

                if (!read_int("Enter index: ", &index))
                {
                    break;
                }

                if (delete_at(&head, index))
                {
                    printf("Node deleted successfully.\n");
                }

                break;


            case 7:

                if (!read_int("Enter value to search: ", &value))
                {
                    break;
                }

                result = search(head, value);

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

                printf("Length: %d\n", length(head));

                break;


            case 9:

                print_list(head);

                break;


            case 10:

                free_list(&head);

                printf("List cleared.\n");

                break;


            case 0:

                free_list(&head);

                printf("Program terminated.\n");

                return 0;


            default:

                printf("Invalid choice. Please choose 0-10.\n");
        }
    }
}