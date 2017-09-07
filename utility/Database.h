//
// Created by Silver Narcissus on 2017/9/5.
//

#ifndef CAR_RACE_DATABASE_H
#define CAR_RACE_DATABASE_H

#include<iostream>
#include<string>
#include<mysql.h>

using namespace std;

class Database {

public:
    Database(char *host, char *user, char *pwd, char *db_name);

    ~Database();

    pair<int, int> query(string sql);

    bool update(string sql);

    char **fetch_one();

    bool free_result();

private:
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;
};


#endif //CAR_RACE_DATABASE_H
