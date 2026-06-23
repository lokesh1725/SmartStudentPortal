#include <stdio.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {

    for (int i = 0; i < argc; i++) {
        printf("%s: %s\n",
               azColName[i],
               argv[i] ? argv[i] : "NULL");
    }

    printf("---------------------\n");

    return 0;
}

int main() {

    sqlite3 *db;
    char *errMsg = 0;

    if (sqlite3_open("../database/student_portal.db", &db)) {
        printf("Cannot open DB\n");
        return 1;
    }

    char *sql = "SELECT * FROM students;";

    sqlite3_exec(db, sql, callback, 0, &errMsg);

    sqlite3_close(db);

    return 0;
}