#include <stdio.h>
#include <stdlib.h>

int main() {

    int choice;

    while (1) {

        printf("\n===== SMART STUDENT PORTAL =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                system("./addstudent");
                break;

            case 2:
                system("./viewstudents");
                break;

            case 3:
                system("./searchstudents");
                break;

            case 4:
                system("./updatestudent");
                break;

            case 5:
                system("./deletestudent");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}