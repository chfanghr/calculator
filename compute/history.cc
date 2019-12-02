//
// Created by 方泓睿 on 2019/12/2.
//

#include "history.h"

std::deque<double> kResHistory;

auto ClearHistory() -> void {
	kResHistory.clear();
}

auto GetHistory(size_t back) -> double {
	if (back >= kResHistory.size())
		throw std::runtime_error("History underflow");
	return kResHistory[back];
}

auto PushHistory(double res) -> void {
	kResHistory.push_front(res);
}