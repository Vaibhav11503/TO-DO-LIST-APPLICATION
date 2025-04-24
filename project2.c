#include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct Node {

    char title[100];

    char date[11];

    struct Node *next;

} Node;



Node *head = NULL;



void create_task() {

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (!new_node) {

        printf("Memory allocation failed!\n");

        return;

    }



    printf("Enter task title: ");

    getchar();

    fgets(new_node->title, sizeof(new_node->title), stdin);

    new_node->title[strcspn(new_node->title, "\n")] = '\0';



    printf("Enter task date (YYYY-MM-DD): ");

    scanf("%s", new_node->date);



    new_node->next = head;

    head = new_node;



    printf("Task created successfully!\n");

}



void read_tasks() {

    if (head == NULL) {

        printf("No tasks available.\n");

        return;

    }



    printf("\nTasks:\n");

    Node *current = head;

    int count = 1;

    while (current != NULL) {

        printf("%d. %s - Date: %s\n", count++, current->title, current->date);

        current = current->next;

    }

}



void sort_tasks() {

    if (head == NULL || head->next == NULL) {

        printf("Not enough tasks to sort.\n");

        return;

    }



    char choice;

    printf("Enter 'd' to sort by Date or 'a' to sort by Title: ");

    getchar();

    scanf("%c", &choice);



    Node *i, *j;

    char temp_title[100], temp_date[11];

    if (choice == 'd') {

        for (i = head; i != NULL; i = i->next) {

            for (j = i->next; j != NULL; j = j->next) {

                if (strcmp(i->date, j->date) > 0) {

                    strcpy(temp_date, i->date);

                    strcpy(i->date, j->date);

                    strcpy(j->date, temp_date);



                    strcpy(temp_title, i->title);

                    strcpy(i->title, j->title);

                    strcpy(j->title, temp_title);

                }

            }

        }

        printf("Tasks sorted by Date successfully!\n");

    } else if (choice == 'a') {

        for (i = head; i != NULL; i = i->next) {

            for (j = i->next; j != NULL; j = j->next) {

                if (strcmp(i->title, j->title) > 0) {

                    strcpy(temp_title, i->title);

                    strcpy(i->title, j->title);

                    strcpy(j->title, temp_title);



                    strcpy(temp_date, i->date);

                    strcpy(i->date, j->date);

                    strcpy(j->date, temp_date);

                }

            }

        }

        printf("Tasks sorted alphabetically by Title successfully!\n");

    } else {

        printf("Invalid input! Please enter 'd' or 'a'.\n");

    }

}



void update_task() {

    int index;

    printf("Enter the task number to update: ");

    scanf("%d", &index);



    Node *current = head;

    int count = 1;

    while (current != NULL && count < index) {

        current = current->next;

        count++;

    }



    if (current == NULL) {

        printf("Invalid task number!\n");

        return;

    }



    printf("Enter new task title: ");

    getchar();

    fgets(current->title, sizeof(current->title), stdin);

    current->title[strcspn(current->title, "\n")] = '\0';



    printf("Enter new task date (YYYY-MM-DD): ");

    scanf("%s", current->date);



    printf("Task updated successfully!\n");

}



void delete_task() {

    int index;

    printf("Enter the task number to delete: ");

    scanf("%d", &index);



    if (head == NULL) {

        printf("No tasks available to delete.\n");

        return;

    }



    Node *current = head;

    Node *prev = NULL;

    int count = 1;



    while (current != NULL && count < index) {

        prev = current;

        current = current->next;

        count++;

    }



    if (current == NULL) {

        printf("Invalid task number!\n");

        return;

    }



    if (prev == NULL) {

        head = current->next;

    } else {

        prev->next = current->next;

    }



    free(current);

    printf("Task deleted successfully!\n");

}



void free_memory() {

    Node *current = head;

    while (current != NULL) {

        Node *temp = current;

        current = current->next;

        free(temp);

    }

    head = NULL;

}



int main() {

    int choice;



    do {

        printf("\nTo-Do List Menu:\n");

        printf("1. Create Task\n");

        printf("2. Read Tasks\n");

        printf("3. Update Task\n");

        printf("4. Delete Task\n");

        printf("5. Sort Tasks (by Date or Title)\n");

        printf("6. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);



        switch (choice) {

            case 1:

                create_task();

                break;

            case 2:

                read_tasks();

                break;

            case 3:

                update_task();

                break;

            case 4:

                delete_task();

                break;

            case 5:

                sort_tasks();

                break;

            case 6:

                printf("Exiting program. Goodbye!\n");

                free_memory();

                break;

            default:

                printf("Invalid choice! Please try again.\n");

        }

    } while (choice != 6);



    return 0;

}