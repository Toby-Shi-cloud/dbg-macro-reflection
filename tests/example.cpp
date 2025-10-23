#include <dbg.h>
#include <cstdint>
#include <vector>

#if DBG_MACRO_CXX_STANDARD >= 20
// You can use "dbg(...)" with user defined type (with reflection or operator<<)
struct udf {
  enum udf_enum { VALUE10 = 10, VALUE24 = 24 } a;
  double b;
  std::vector<char> c;
};
#endif

// You can use "dbg(..)" in expressions:
int32_t factorial(int32_t n) {
  if (dbg(n <= 1)) {
    return dbg(1);
  } else {
    return dbg(n * factorial(n - 1));
  }
}

int32_t main() {
  std::string message = "hello";
  dbg(message);  // [example.cpp:25 (main)] message = "hello" (std::string)

  const int32_t a = 2;
  const int32_t b = dbg(3 * a) + 1;  // [example.cpp:28 (main)] 3 * a = 6 (int32_t)

  std::vector<int32_t> numbers{b, 13, 42};
  dbg(numbers);  // [example.cpp:31 (main)] numbers = {7, 13, 42} (std::vector<int32_t>)

  dbg("this line is executed");  // [example.cpp:33 (main)] this line is executed

#if DBG_MACRO_CXX_STANDARD >= 20
  udf u = {udf::VALUE24, 3.14, {'a', 'b', 'c'}};
  dbg(u);  // [example.cpp:37 (main)] u = {a = VALUE24 (udf_enum), b = 3.14 (double), c = {'a', 'b', 'c'} (vector)} (udf)
#endif

  factorial(4);

  return 0;
}
