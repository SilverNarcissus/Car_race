//
// Created by Silver Narcissus on 2017/9/5.
//

#ifndef CAR_RACE_UTILS_H
#define CAR_RACE_UTILS_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <numeric>

//在命令行执行一条命令
//cmd：命令内容
std::string exec(const char *cmd);

//for template function, declaration and implementation should in the same head file
//按顺序打印出迭代器范围内的内容
//first: 起始范围
//last: 结束范围
//separator: 分隔符, 默认为制表符
template<class _InputIterator>
void display(_InputIterator first, _InputIterator last, const char *separator = "\t") {
    using namespace std;
    cout << endl;
    copy(first, last,
         ostream_iterator<int>(std::cout, separator));
    cout << endl;
}

#endif //CAR_RACE_UTILS_H
