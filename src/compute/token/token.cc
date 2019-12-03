//
// Created by 方泓睿 on 2019/12/2.
//

#include "token.h"

#include <utility>
namespace calculator::compute::token {
std::map<Token, std::string> kTokens{ // NOLINT(cert-err58-cpp)
		{Token::kIllegal, "ILLEGAL"},
		{Token::kEOF, "EOF"},
		{Token::kIdent, "IDENT"},
		{Token::kInt, "INT"},
		{Token::kFloat, "FLOAT"},
		{Token::kRParen, ")"},
		{Token::kLParen, "("},
		{Token::kPlus, "+"},
		{Token::kSub, "-"},
		{Token::kMul, "*"},
		{Token::kDiv, "/"},
		{Token::kMod, "%"}
};

auto ToString(Token tok) noexcept -> std::string {
	return kTokens[tok];
}

Scanner::Scanner(std::string in) noexcept : in_(std::move(in)), pos_(0) {}

auto Scanner::Scan() -> std::tuple<size_t, Token, std::string> {
	SkipWhiteSpaces();
	if (pos_ >= in_.size())
		return std::make_tuple(pos_, Token::kEOF, ToString(Token::kEOF));
	auto cur_ch = in_[pos_];
	switch (cur_ch) {
		case 'a' ... 'z':
		case 'A' ... 'Z':
		case '_': return ReadIdent();
		case '0' ... '9': return ReadNumber();
		case '+': return std::make_tuple(pos_++, Token::kPlus, "+");
		case '-': return std::make_tuple(pos_++, Token::kSub, "-");
		case '*': return std::make_tuple(pos_++, Token::kMul, "*");
		case '/': return std::make_tuple(pos_++, Token::kDiv, "/");
		case '%': return std::make_tuple(pos_++, Token::kMod, "%");
		case '(': return std::make_tuple(pos_++, Token::kLParen, "(");
		case ')': return std::make_tuple(pos_++, Token::kRParen, ")");
		default: return std::make_tuple(pos_++, Token::kIllegal, std::string() + cur_ch);
	}
}

template<typename T>
static inline auto IsInClosedRange(const T &value, const T &from, const T &to) -> bool {
	return from <= value && value <= to;
}

auto Scanner::ReadIdent() -> std::tuple<size_t, Token, std::string> {
	auto pos = pos_;
	if (pos_ >= in_.size())
		throw std::runtime_error("Unexpected EOF");
	if (!(in_[pos_] == '_'
			|| IsInClosedRange(in_[pos_], 'A', 'Z')
			|| IsInClosedRange(in_[pos_], 'a', 'z')))
		throw std::runtime_error("Cannot read identifier: not an identifier");
	auto lit = std::string();
	while (pos_ < in_.size() && (in_[pos_] == '_'
			|| IsInClosedRange(in_[pos_], 'A', 'Z')
			|| IsInClosedRange(in_[pos_], 'a', 'z')
			|| IsInClosedRange(in_[pos_], '0', '9')))
		lit += in_[pos_++];
	return std::make_tuple(pos, Token::kIdent, lit);
}

static inline auto IsWhiteSpace(char ch) -> bool {
	switch (ch) {
		case ' ':
		case '\r':
		case '\n': return true;
		default: return false;
	}
}

auto Scanner::SkipWhiteSpaces() -> void {
	while (pos_ < in_.size() && IsWhiteSpace(in_[pos_]))
		pos_++;
}

auto Scanner::ReadNumber() -> std::tuple<size_t, Token, std::string> {
	Token type = Token::kInt;
	auto  pos  = pos_;
	if (pos_ >= in_.size())
		throw std::runtime_error("Unexpected EOF");
	if (!IsInClosedRange(in_[pos_], '0', '9'))
		throw std::runtime_error("Cannot read number: not a number");
	auto lit = std::string();
	while (pos_ < in_.size() &&
			(in_[pos_] == '.' || IsInClosedRange(in_[pos_], '0', '9'))) {
		if (in_[pos_] == '.')
			type = Token::kFloat;
		lit += in_[pos_++];
	}
	return std::make_tuple(pos, type, lit);
}
}

