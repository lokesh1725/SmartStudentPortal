#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    char sql[500];

    char roll_no[20], name[50], dept[20], email[50];
    int year;

    if (sqlite3_open("../database/student_portal.db", &db)) {
        printf("Cannot open database\n");
        return 1;
    }

    printf("Enter Roll Number: ");
    scanf("%s", roll_no);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Department: ");
    scanf("%s", dept);

    printf("Enter Year: ");
    scanf("%d", &year);

    printf("Enter Email: ");
    scanf("%s", email);

    sprintf(sql,
        "INSERT INTO students "
        "(roll_no, name, department, year, email) "
        "VALUES ('%s', '%s', '%s', %d, '%s');",
        roll_no, name, dept, year, email);

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("\nStudent added successfully.\n");
    }

    sqlite3_close(db);
    return 0;
}