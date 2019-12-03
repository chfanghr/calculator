//
// Created by 方泓睿 on 2019/12/2.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#ifndef CALCULATOR_COMPUTE_TOKEN_TOKEN_H_
#define CALCULATOR_COMPUTE_TOKEN_TOKEN_H_

#include <cstdint>
#include <string>
#include <utility>
#include <tuple>
#include <map>

namespace calculator::compute::token {
enum class Token : int32_t {
	kIllegal = 0,
	kEOF,

	kLParen,
	kRParen,

	kPlus,
	kSub,
	kMul,
	kDiv,
	kMod,

	kFloat,
	kInt,

	kIdent,
};

auto ToString(Token tok) noexcept -> std::string;

class Scanner {
 private:
	std::string in_;
	size_t      pos_;
 public:
	explicit Scanner(std::string in) noexcept;

	auto Scan() -> std::tuple<size_t, Token, std::string>;
 private:
	auto ReadIdent() -> std::tuple<size_t, Token, std::string>;
	auto ReadNumber() -> std::tuple<size_t, Token, std::string>;
	auto SkipWhiteSpaces() -> void;
};

extern std::map<Token, std::string> kTokens;
}
#endif //CALCULATOR_COMPUTE_TOKEN_TOKEN_H_
#pragma clang diagnostic pop