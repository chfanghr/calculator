//
// Created by 方泓睿 on 2019/12/2.
//

#ifndef CALCULATOR_COMPUTE_STACK_H_
#define CALCULATOR_COMPUTE_STACK_H_

#include <stack>
#include <stdexcept>

template<typename T>
class Stack : public std::stack<T> {
 public:
	Stack(std::initializer_list<T> l) : std::stack<T>(l) {}
	Stack() : std::stack<T>() {}

	auto Pop() -> T {
		if (!*this)
			throw std::runtime_error("The stack is empty, nothing to pop.");
		T res = this->top();
		this->pop();
		return res;
	}

	auto SafePop() -> T {
		if (!*this)
			return {};
		T res = this->top();
		this->pop();
		return res;
	}

	auto Push(const T &v) -> void {
		this->push(v);
	}

	auto Top() const -> T {
		if (!*this)
			throw std::runtime_error("The stack is empty.");
		return this->top();
	}

	[[nodiscard]]auto SafeTop() const -> T {
		if (!*this)
			return {};
		return this->top();
	}

	[[nodiscard]]auto TopRef() -> T & {
		if (!*this)
			throw std::runtime_error("The stack is empty.");
		return this->top();
	}

	[[nodiscard]]auto TopRef() const -> const T & {
		if (!*this)
			throw std::runtime_error("The stack is empty.");
		return this->top();
	}

	explicit operator bool() const {
		return !this->empty();
	}
};

#endif //CALCULATOR_COMPUTE_STACK_H_
