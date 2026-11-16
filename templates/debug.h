#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <tuple>
#include <type_traits>

namespace cp_debug {

// ANSI escape sequences
inline constexpr const char* RESET = "\033[0m";
inline constexpr const char* BOLD = "\033[1m";
inline constexpr const char* DIM = "\033[2m";
inline constexpr const char* CYAN = "\033[36m";
inline constexpr const char* YELLOW = "\033[33m";
inline constexpr const char* MAGENTA = "\033[35m";
inline constexpr const char* GREEN = "\033[32m";

// Forward declaration
template <typename T>
void print_value(std::ostream& os, const T& value);

// Basic types
inline void print_value(std::ostream& os, const std::string& s) {
  os << '"' << s << '"';
}

inline void print_value(std::ostream& os, const char* s) {
  os << '"' << s << '"';
}

inline void print_value(std::ostream& os, char c) {
  os << '\'' << c << '\'';
}

inline void print_value(std::ostream& os, bool b) {
  os << (b ? "true" : "false");
}

// Pair
template <typename A, typename B>
void print_value(std::ostream& os, const std::pair<A, B>& p) {
  os << "(";
  print_value(os, p.first);
  os << ", ";
  print_value(os, p.second);
  os << ")";
}

// Tuple helper
template <typename Tuple, std::size_t... I>
void print_tuple_helper(std::ostream& os, const Tuple& t, std::index_sequence<I...>) {
  std::size_t idx = 0;
  auto print_elem = [&](const auto& val) {
    if (idx++ > 0) os << ", ";
    print_value(os, val);
  };
  os << "(";
  (print_elem(std::get<I>(t)), ...);
  os << ")";
}

template <typename... Args>
void print_value(std::ostream& os, const std::tuple<Args...>& t) {
  print_tuple_helper(os, t, std::index_sequence_for<Args...>{});
}

// Check for iterable container
template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin()),
                                   decltype(std::declval<T>().end())>> : std::true_type {};

// Fallback for arithmetic and generic types
template <typename T>
void print_value(std::ostream& os, const T& value) {
  if constexpr (is_container<T>::value && !std::is_same_v<T, std::string>) {
    os << "[";
    bool first = true;
    for (const auto& elem : value) {
      if (!first) os << ", ";
      print_value(os, elem);
      first = false;
    }
    os << "]";
  } else {
    os << value;
  }
}

// Debug print helper for variadic arguments
inline void debug_print_vars(std::ostream&, const char*) {}

template <typename Head, typename... Tail>
void debug_print_vars(std::ostream& os, const char* names, const Head& head, const Tail&... tail) {
  while (*names == ' ' || *names == ',') names++;
  const char* next = names;
  int open_parens = 0;
  while (*next) {
    if (*next == '(' || *next == '[' || *next == '{' || *next == '<') open_parens++;
    else if (*next == ')' || *next == ']' || *next == '}' || *next == '>') open_parens--;
    else if (*next == ',' && open_parens == 0) break;
    next++;
  }

  os.write(names, next - names);
  os << " = " << YELLOW;
  print_value(os, head);
  os << RESET;

  if constexpr (sizeof...(tail) > 0) {
    os << ", ";
    debug_print_vars(os, next + (*next == ',' ? 1 : 0), tail...);
  }
}

}  // namespace cp_debug

#define dbg(...) \
  do { \
    std::cerr << cp_debug::DIM << "[" << __FILE__ << ":" << __LINE__ << "] " \
              << cp_debug::CYAN; \
    cp_debug::debug_print_vars(std::cerr, #__VA_ARGS__, __VA_ARGS__); \
    std::cerr << cp_debug::RESET << std::endl; \
  } while (0)
