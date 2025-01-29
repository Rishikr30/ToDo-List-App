#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

// Structure to store task information
struct Task {
    char description[MAX_LENGTH];
    int completed;
    int id;
};

// Global variables
struct Task tasks[MAX_TASKS];
int taskCount = 0;

// Function prototypes
void addTask();
void viewTasks();
void markTaskComplete();
void deleteTask();
void saveTasksToFile();
void loadTasksFromFile();
void displayMenu();

int main() {
    int choice;
    
    // Load existing tasks from file
    loadTasksFromFile();
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskComplete();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                saveTasksToFile();
                printf("Tasks saved. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== To-Do List Manager ===\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Delete Task\n");
    printf("5. Save and Exit\n");
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    
    printf("Enter task description: ");
    fgets(tasks[taskCount].description, MAX_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; // Remove newline
    tasks[taskCount].completed = 0;
    tasks[taskCount].id = taskCount + 1;
    taskCount++;
    
    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list!\n");
        return;
    }
    
    printf("\nTask List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", 
            tasks[i].id,
            tasks[i].completed ? 'X' : ' ',
            tasks[i].description);
    }
}

void markTaskComplete() {
    int id;
    viewTasks();
    
    if (taskCount == 0) return;
    
    printf("Enter task ID to mark as complete: ");
    scanf("%d", &id);
    getchar(); // Clear input buffer
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printf("Task marked as complete!\n");
            return;
        }
    }
    
    printf("Task not found!\n");
}

void deleteTask() {
    int id;
    viewTasks();
    
    if (taskCount == 0) return;
    
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    getchar(); // Clear input buffer
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    
    printf("Task not found!\n");
}

void saveTasksToFile() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d,%d,%s\n", 
            tasks[i].id,
            tasks[i].completed,
            tasks[i].description);
    }
    
    fclose(file);
}

void loadTasksFromFile() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        return; // File doesn't exist yet
    }
    
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) && taskCount < MAX_TASKS) {
        char *token = strtok(line, ",");
        tasks[taskCount].id = atoi(token);
        
        token = strtok(NULL, ",");
        tasks[taskCount].completed = atoi(token);
        
        token = strtok(NULL, "\n");
        strcpy(tasks[taskCount].description, token);
        
        taskCount++;
    }
    
   fclose(file);
}
