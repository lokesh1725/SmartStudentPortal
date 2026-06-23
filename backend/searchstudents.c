#include <stdio.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {

    for (int i = 0; i < argc; i++) {
        printf("%s: %s\n",
               azColName[i],
               argv[i] ? argv[i] : "NULL");
    }

    return 0;
}

int main() {

    sqlite3 *db;
    char *errMsg = 0;
    char roll[20];
    char sql[200];

    if (sqlite3_open("../database/student_portal.db", &db)) {
        printf("Cannot open database\n");
        return 1;
    }

    printf("Enter Roll Number: ");
    scanf("%s", roll);

    sprintf(sql,
            "SELECT * FROM students "
            "WHERE roll_no='%s';",
            roll);

    sqlite3_exec(db, sql, callback, 0, &errMsg);

    sqlite3_close(db);

    return 0;
}