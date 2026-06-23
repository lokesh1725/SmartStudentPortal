#include <stdio.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    char *errMsg = 0;

    char roll_no[20];
    char new_email[50];
    char sql[300];

    if (sqlite3_open("../database/student_portal.db", &db)) {
        printf("Cannot open database\n");
        return 1;
    }

    printf("Enter Roll Number: ");
    scanf("%s", roll_no);

    printf("Enter New Email: ");
    scanf("%s", new_email);

    sprintf(sql,
            "UPDATE students "
            "SET email='%s' "
            "WHERE roll_no='%s';",
            new_email, roll_no);

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Student updated successfully.\n");
    }

    sqlite3_close(db);

    return 0;
}