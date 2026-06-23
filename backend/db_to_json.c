#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

FILE *fp;
int first = 1;

int callback(void *data, int argc, char **argv, char **azColName)
{
    if (!first)
        fprintf(fp, ",\n");

    fprintf(fp,
        "  {\n"
        "    \"id\": %s,\n"
        "    \"roll_no\": \"%s\",\n"
        "    \"name\": \"%s\",\n"
        "    \"department\": \"%s\",\n"
        "    \"year\": %s,\n"
        "    \"email\": \"%s\"\n"
        "  }",
        argv[0] ? argv[0] : "0",
        argv[1] ? argv[1] : "",
        argv[2] ? argv[2] : "",
        argv[3] ? argv[3] : "",
        argv[4] ? argv[4] : "0",
        argv[5] ? argv[5] : "");

    first = 0;

    return 0;
}

int main()
{
    sqlite3 *db;
    char *errMsg = 0;

    if (sqlite3_open("../database/student_portal.db", &db))
    {
        printf("Cannot open database\n");
        return 1;
    }

    fp = fopen("../frontend/src/data/students.json", "w");

    if (fp == NULL)
    {
        printf("Cannot create JSON file\n");
        sqlite3_close(db);
        return 1;
    }

    fprintf(fp, "[\n");

    char *sql =
        "SELECT id, roll_no, name, department, year, email "
        "FROM students;";

    sqlite3_exec(db, sql, callback, 0, &errMsg);

    fprintf(fp, "\n]\n");

    fclose(fp);

    sqlite3_close(db);

    printf("students.json updated successfully.\n");

    return 0;
}