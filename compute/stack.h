//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_COMPUTE_STACK_H_
#define CALCULATOR_COMPUTE_STACK_H_

#include <stack>

template<typename T>
auto SafePop(std::stack<T> &s) -> T {
	if (s.empty())
		return {};
	auto res = s.top();
	s.pop();
	return res;
}

template<typename T>
auto Pop(std::stack<T> &s) -> T {
	if (s.empty())
		throw std::runtime_error("Cannot pop: stack is empty.");
	auto res = s.top();
	s.pop();
	return res;
}

template<typename T>
auto SafeTop(std::stack<T> &s) -> T {
	if (s.empty())
		return {};
	auto res = s.top();
	return res;
}

template<typename T>
auto Top(std::stack<T> &s) -> T {
	if (s.empty())
		throw std::runtime_error("No elements in stack.");
	auto res = s.top();
	return res;
}

#endif //CALCULATOR_COMPUTE_STACK_H_
