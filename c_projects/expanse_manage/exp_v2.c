#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100
#define FILE_NAME "expenses.dat"

typedef struct {
    int id;
    long long amount_paise;
    char category[50];
    char description[100];
} Expense;


/* ---------- INPUT HELPERS ---------- */

void read_string(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}


long long read_amount()
{
    double amount;

    while (1) {
        printf("Enter amount (₹): ");

        if (scanf("%lf", &amount) == 1 && amount >= 0) {
            while (getchar() != '\n');

            return (long long)(amount * 100 + 0.5);
        }

        printf("Invalid amount. Try again.\n");

        while (getchar() != '\n');
    }
}


int read_choice()
{
    int choice;

    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        return -1;
    }

    while (getchar() != '\n');

    return choice;
}


/* ---------- EXPENSE FUNCTIONS ---------- */

void add_expense(Expense expenses[], int *count)
{
    if (*count >= MAX_EXPENSES) {
        printf("\nExpense limit reached!\n");
        return;
    }

    Expense *expense = &expenses[*count];

    expense->id = *count + 1;

    expense->amount_paise = read_amount();

    read_string(
        "Enter category: ",
        expense->category,
        sizeof(expense->category)
    );

    read_string(
        "Enter description: ",
        expense->description,
        sizeof(expense->description)
    );

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

        printf("\nID          : %d\n",
               expenses[i].id);

        printf("Amount      : ₹%lld.%02lld\n",
               expenses[i].amount_paise / 100,
               expenses[i].amount_paise % 100);

        printf("Category    : %s\n",
               expenses[i].category);

        printf("Description : %s\n",
               expenses[i].description);
    }

    printf("\n==============================\n");
}


void total_expense(Expense expenses[], int count)
{
    long long total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount_paise;
    }

    printf(
        "\nTotal Expense = ₹%lld.%02lld\n",
        total / 100,
        total % 100
    );
}


/* ---------- FILE FUNCTIONS ---------- */

void save_expenses(Expense expenses[], int count)
{
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        printf("\nError: Could not open file for writing.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);

    fwrite(
        expenses,
        sizeof(Expense),
        count,
        file
    );

    fclose(file);

    printf("\nExpenses saved successfully.\n");
}


void load_expenses(Expense expenses[], int *count)
{
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("\nNo previous expense data found.\n");
        return;
    }

    fread(count, sizeof(int), 1, file);

    if (*count < 0 || *count > MAX_EXPENSES) {
        printf("\nInvalid data file.\n");

        *count = 0;

        fclose(file);
        return;
    }

    fread(
        expenses,
        sizeof(Expense),
        *count,
        file
    );

    fclose(file);

    printf(
        "\n%d expenses loaded successfully.\n",
        *count
    );
}


/* ---------- MAIN ---------- */

int main()
{
    Expense expenses[MAX_EXPENSES];

    int count = 0;
    int choice;

    load_expenses(expenses, &count);

    while (1) {

        printf("\n");
        printf("======= PERSONAL EXPENSE TRACKER =======\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expense\n");
        printf("4. Save Expenses\n");
        printf("5. Load Expenses\n");
        printf("6. Exit\n");
        printf("========================================\n");

        choice = read_choice();

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
                save_expenses(expenses, count);
                break;

            case 5:
                load_expenses(expenses, &count);
                break;

            case 6:
                save_expenses(expenses, count);

                printf("\nGoodbye!\n");

                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}