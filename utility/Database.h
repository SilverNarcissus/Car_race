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

    //执行查询命令，查询结果会被保存，调用fetch_one函数取得一行
    //sql: 执行的命令
    //返回值: pair(查询到的行数，查询到的列数)
    pair<int, int> query(string sql);

    //执行增、删、改命令
    //sql: 执行的命令
    bool update(string sql);

    //取得结果的一行
    char **fetch_one();

    //清除取到的数据
    bool free_result();

    //重载输出运算符，可以视为toString方法
    friend ostream& operator<<(ostream& out,const Database& database);

private:
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;
};


#endif //CAR_RACE_DATABASE_H
