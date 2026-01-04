
#include<stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char note[200];
    FILE *fptr;

    while(1) {
        printf("\n--- MY PERSISTENT DIARY ---\n");
        printf("1. Add a Note\n");
        printf("2. Read All Notes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
            case 1:
                fptr = fopen("diary.txt", "a");
                if(fptr == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                printf("Enter your text: ");
                fgets(note, sizeof(note), stdin);
                fprintf(fptr, "%s", note);
                fclose(fptr);
                printf("Saved!\n");
                break;

            case 2:
                fptr = fopen("diary.txt", "r");
                if(fptr == NULL) {
                    printf("Diary is empty or doesn't exist yet.\n");
                    break;
                }
                printf("\n--- YOUR NOTES ---\n");
                while(fgets(note, sizeof(note), fptr)) {
                    printf("- %s", note);
                }
                fclose(fptr);
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
