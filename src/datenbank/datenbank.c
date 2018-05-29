#include <mysql.h>
#include <stdio.h>

struct Person {
  char *name;
  char *vorname;
} Person;

int main() {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *server = "localhost";
  char *user = "testo";
  char *password = "1337"; /* set me first */
  char *database = "dbtest";
  conn = mysql_init(NULL);
  /* Connect to database */
  if (!mysql_real_connect(conn, server,
        user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  /* send SQL query */
  if (mysql_query(conn, "show tables")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }
  res = mysql_use_result(conn);

  /* output table name */
  printf("MySQL Tables in mysql database:\n");
  while ((row = mysql_fetch_row(res)) != NULL)
    printf("%s \n", row[0]);

  if (mysql_query(conn, "SELECT * FROM personen")) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  } else {
    printf("working\n");
  }

  MYSQL_RES *result = mysql_store_result(conn);
  MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result);

	for (int i = 0; i < mysql_num_fields(result); i++) {
		MYSQL_FIELD *column = mysql_fetch_field(result);
		printf("Column number %i is named : %s\n", i + 1, column->name);
	}

  /* close connection */
  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}
