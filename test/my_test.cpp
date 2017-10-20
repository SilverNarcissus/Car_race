//
// Created by Silver Narcissus on 2017/9/6.
//

#include "my_test.h"

int test1() {
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

    if (db.update("INSERT INTO news VALUE(11,'brilliant','POS')")) {
        return 0;
    }

    std::cout << db;
    return -1;
}

int mul(int a,int b){
    return a*b;
}

int test2() {
    std::vector<int> collection(10, 5);
    collection.push_back(4);
    collection.push_back(3);
    collection.push_back(6);
    display<std::vector<int>::iterator>(collection.begin(), collection.end());
    next_permutation(collection.begin(), collection.end());
    display<std::vector<int>::iterator>(collection.begin(), collection.end());
    cout<<accumulate(collection.begin(), collection.end(), 1, mul);
    return 0;
}

int test3(){
    using namespace cv;

    std::cout << "Hello opencv!\n";
    std::string path = "test.jpg";
    Mat image = imread(path);
    namedWindow("test");
    imshow("test", image);
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    return 0;
}