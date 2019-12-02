//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR__HISTORY_H_
#define CALCULATOR__HISTORY_H_

#include <deque>

extern std::deque<double> kResHistory;

auto ClearHistory() -> void;

auto GetHistory(size_t back) -> double;

auto PushHistory(double res) -> void;

#endif //CALCULATOR__HISTORY_H_
