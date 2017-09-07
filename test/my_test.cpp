//
// Created by Silver Narcissus on 2017/9/6.
//
#include <iostream>
#include "../utility/Database.h"
#include "../utility/utils.h"

int test1(){
    std::cout << "Hello, World!" << std::endl;
    std::cout << exec("python /Users/SilverNarcissus/Desktop/test.py") << std::endl;
    Database db(const_cast<char *>("localhost"), const_cast<char *>("root"), const_cast<char *>("xue199714"),
                const_cast<char *>("python"));
//    pair<int, int> row_column = db.query("INSERT INTO news VALUE(10,'brilliant','POS')");
//
//
//    for (int i = 0; i < row_column.first; i++) {
//        char **row = db.fetch_one();
//        for (int j = 0; j < row_column.second; j++) {
//            cout << row[j] << " ";
//        }
//        cout << endl;
//    }

    if(db.update("INSERT INTO news VALUE(11,'brilliant','POS')")){
        return 0;
    }

    return -1;
}