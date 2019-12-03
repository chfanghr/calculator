//
// Created by 方泓睿 on 2019/12/3.
//

#include "engine.h"

namespace calculator {
auto Engine::History() noexcept -> std::deque<double> & {
	return history_;
}

auto Engine::History() const noexcept -> const std::deque<double> & {
	return history_;
}

auto Engine::ClearHistory() noexcept -> void {
	history_.clear();
}

auto Engine::PushHistory(double res) noexcept -> void {
	history_.push_front(res);
}

auto Engine::GetHistory(size_t idx) const -> double {
	return history_[idx];
}

}