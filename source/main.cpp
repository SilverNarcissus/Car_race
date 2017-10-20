
//
// Created by Silver Narcissus on 2017/9/7.
//
#include <iostream>
#include "../googletest/include/gtest/gtest.h"
#include "../test/my_test.h"


TEST(database__Test,test1) {
    EXPECT_EQ(-1, test1());
}

TEST(database__Test,test2) {
    EXPECT_EQ(0, test2());
}

TEST(opencv_test,test3) {
    EXPECT_EQ(0, test3());
}

GTEST_API_ int main(int argc, char **argv) {
    using namespace cv;

    std::cout << "Hello opencv!\n";
    std::string path = "../test.jpg";
    Mat image = imread(path);
    namedWindow("test");
    imshow("test", image);
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    waitKey(0);
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
}

//int main(){
//    std::cout<<"Hello World!"<<std::endl;
//    return 0;
//}