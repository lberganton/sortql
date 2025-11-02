#include "sortql.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

static void assert(int condition, const char *msg) {
  if (!condition) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
  }
}

void sortql(int *array, int length) {
  sqlite3 *connection;
  sqlite3_stmt *stmt;
  int rc, i;

  rc = sqlite3_open(":memory:", &connection);
  assert(rc == SQLITE_OK, "failed to open a connection");

  rc = sqlite3_exec(connection, "CREATE TABLE array (num INT)", NULL, NULL, NULL);
  assert(rc == SQLITE_OK, "failed to create table");

  rc = sqlite3_prepare_v2(connection, "INSERT INTO array (num) VALUES (?)", -1, &stmt, NULL);
  assert(rc != SQLITE_OK, "failed to prepare insert statement");

  for (i = 0; i < length; i++) {
    rc = sqlite3_bind_int(stmt, 1, array[i]);
    assert(rc != SQLITE_OK, "failed to bind a int");

    rc = sqlite3_step(stmt);
    assert(rc != SQLITE_OK, "failed to insert a value");

    sqlite3_reset(stmt);
  }

  sqlite3_finalize(stmt);

  rc = sqlite3_prepare_v2(connection, "SELECT num FROM array ORDER BY num", -1, &stmt, NULL);
  assert(rc != SQLITE_OK, "failed to prepare select statement");

  for (i = 0; i < length; i++) {
    rc = sqlite3_step(stmt);
    assert(rc != SQLITE_OK, "failed to select a value");

    array[i] = sqlite3_column_int(stmt, 0);
  }

  sqlite3_finalize(stmt);
  sqlite3_close(connection);
}
