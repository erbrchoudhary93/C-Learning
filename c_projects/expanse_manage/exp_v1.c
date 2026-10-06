#include <stdio.h>

#define MAX_EXPENSES 100

typedef struct {
    int id;
    float amount;
    char category[50];
    char description[100];
} Expense;


void add_expense(Expense expenses[], int *count)
{
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }

    Expense *expense = &expenses[*count];

    expense->id = *count + 1;

    printf("\nEnter amount: ");
    scanf("%f", &expense->amount);

    printf("Enter category: ");
    scanf("%49s", expense->category);

    printf("Enter description: ");
    scanf("%99s", expense->description);

    (*count)++;

    printf("\nExpense added successfully!\n");
}


void view_expenses(Expense expenses[], int count)
{
    if (count == 0) {
        printf("\nNo expenses found.\n");
        return;
    }

    printf("\n========== EXPENSES ==========\n");

    for (int i = 0; i < count; i++) {

        printf("\nID          : %d\n", expenses[i].id);
        printf("Amount      : %.2f\n", expenses[i].amount);
        printf("Category    : %s\n", expenses[i].category);
        printf("Description : %s\n", expenses[i].description);
    }

    printf("\n==============================\n");
}


void total_expense(Expense expenses[], int count)
{
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Expense = %.2f\n", total);
}


int main()
{
    Expense expenses[MAX_EXPENSES];

    int count = 0;
    int choice;

    while (1) {

        printf("\n");
        printf("======= PERSONAL EXPENSE TRACKER =======\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expense\n");
        printf("4. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {

            case 1:
                add_expense(expenses, &count);
                break;

            case 2:
                view_expenses(expenses, count);
                break;

            case 3:
                total_expense(expenses, count);
                break;

            case 4:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}