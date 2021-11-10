/*
  ある文字列が全て固有であるかを判定するアルゴリズムを実装せよ
  文字種に制限があるなら、色々工夫できそう
  今回はASCII全てと仮定する
  -> 時間計算量はO(文字列長さ)、空間計算量はO(文字種)
*/

#include <vector>
#include <string>

#include "main.hpp"

bool is_unique(std::string words)
{
  std::vector<bool> is_used(128, false);
  for (unsigned int idx = 0; idx < words.size(); ++idx)
  {
    if (is_used[words[idx]])
    {
      return false;
    }
    is_used[words[idx]] = true;
  }
  return true;
}

