#include <stdio.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    char *errMsg = 0;

    char roll_no[20];
    char sql[200];

    if (sqlite3_open("../database/student_portal.db", &db)) {
        printf("Cannot open database\n");
        return 1;
    }

    printf("Enter Roll Number to Delete: ");
    scanf("%s", roll_no);

    sprintf(sql,
            "DELETE FROM students "
            "WHERE roll_no='%s';",
            roll_no);

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        printf("SQL Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Student deleted successfully.\n");
    }

    sqlite3_close(db);

    return 0;
}