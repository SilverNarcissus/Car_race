//
// Created by Silver Narcissus on 2017/9/5.
//

#include "Database.h"

using namespace std;

Database::Database(char *host, char *user, char *pwd, char *db_name) {
    connection = mysql_init(nullptr); // 初始化数据库连接变量

    if (connection == nullptr) {
        cout << "Error:" << mysql_error(connection);
        exit(1);
    }

    connection = mysql_real_connect(connection, host,
                                    user, pwd, db_name, 3306, nullptr, 0);
    if (connection == nullptr) {
        cout << "Error:" << mysql_error(connection);
        exit(1);
    }
}

Database::~Database() {
    if (connection != nullptr)  // 关闭数据库连接
    {
        mysql_close(connection);
    }
}

pair<int, int> Database::query(string sql) {
    // mysql_query()执行成功返回0，失败返回非0值。与PHP中不一样
    if (mysql_query(connection, sql.c_str())) {
        cerr << "Query Error:" << mysql_error(connection);
        return make_pair(-1,-1);
    } else {
//      result = mysql_use_result(connection); // 获取结果集
        result = mysql_store_result(connection);
//        // mysql_field_count()返回connection查询的列数
//        for (int i = 0; i < mysql_affected_rows(connection); ++i) {
//            // 获取下一行
//            if (row <= 0) {
//                break;
//            }
//            // mysql_num_fields()返回结果集中的字段数
//            for (int j = 0; j < mysql_num_fields(result); ++j) {
//                cout << row[j] << " ";
//            }
//            cout << endl;
//        }
//        // 释放结果集的内存
//        mysql_free_result(result);
    }
    cout << mysql_num_rows(result) << mysql_num_fields(result) << endl;
    return make_pair(mysql_num_rows(result), mysql_num_fields(result));
}

bool Database::update(string sql){
    if (mysql_query(connection, sql.c_str())) {
        cerr << "Query Error:" << mysql_error(connection);
        return false;
    }
    return true;
}

char **Database::fetch_one() {
    row = mysql_fetch_row(result);

//    if (row <= 0) {
//        cerr << "Fetch error" << endl;
//    }

    return row;

}

bool Database::free_result() {
    mysql_free_result(result);
    return true;
}

ostream& operator<<(ostream& out,const Database& database)
{
    out << "Database connector!"<<endl;
    return out;
}