
//
// Created by Silver Narcissus on 2017/9/7.
//
#include <iostream>
#include "../googletest/include/gtest/gtest.h"
#include "../test/my_test.h"

TEST(database__Test,test1) {
    EXPECT_EQ(-1, test1());
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//int main(){
//    std::cout<<"Hello World!"<<std::endl;
//    return 0;
//}