#include "sqlite3.h"
#include <unistd.h>

void createTable() {
	sqlite3 *db;
	char *err_msg = 0;
	char *tableSql = "CREATE TABLE Projects(id INT PRIMARY KEY, name TEXT, progress INT);"
			 "CREATE TABLE Tasks(parentid INT, id INT PRIMARY KEY, name TEXT, val INT, completed INT);";

	int rc = sqlite3_open("data.db", &db);

	if (rc != SQLITE_OK) {
		printf("Error=%s", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	rc = sqlite3_exec(db, tableSql, 0, 0, &err_msg);

	if (rc != SQLITE_OK) {
		printf("error=%s", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return;
	}
}

void insertProject(char *arg) {
	sqlite3 *db;
	char *err_msg = 0;
	char *sql = sqlite3_mprintf("INSERT INTO Projects VALUES (%d, '%q', %d);", 0, arg, 10);

	int rc = sqlite3_open("data.db", &db);

	if (rc != SQLITE_OK) {
		printf("Error=%s", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return;
	}

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

	if (rc != SQLITE_OK) {
		printf("Error=%s", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return;
	}
}

void all(int *mod, char *arg) {
	printf("Showing all with modifiers: [%d, %d, %d] and argument: %s", mod[0], mod[1], mod[2], arg);
}

void new(int *mod, char *arg) {
	if ( access("data.db", F_OK) == 0) {
		printf("Creating project called: %s", arg);
		insertProject(arg);
	} else {
		fopen("data.db", "w+");
		createTable();
	}
	printf("Creating new with modifiers: [%d, %d, %d] and argument: %s", mod[0], mod[1], mod[2], arg);
}

void delete(int *mod, char *arg) {
	printf("Deleting with modifiers: [%d, %d, %d] and argument: %s", mod[0], mod[1], mod[2], arg);
}

void modify(int *mod, char *arg) {
	printf("Modifiying with modifiers: [%d, %d, %d] and argument: %s", mod[0], mod[1], mod[2], arg);
}

