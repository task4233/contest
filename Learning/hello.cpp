#include <iostream>
#include <vector>
#define MESSAGE "hello "

int main()
{
  std::vector<int> vec{1,2,3,4,5};
  for (auto e : vec) {
    std::cout << MESSAGE << __FILE__ << " " << e << std::endl;
  }
  return 0;
}
