/*
  ある文字列が全て固有であるかを判定するアルゴリズムを実装せよ
  文字種に制限があるなら、色々工夫できそう
  今回はASCII全てと仮定する
  -> 時間計算量はO(文字列長さ)、空間計算量はO(文字種)
*/

#include "main.hpp"

#include <string>
#include <vector>

bool is_unique(std::string words) {
	std::vector<bool> is_used(128, false);
	for (unsigned int idx = 0; idx < words.size(); ++idx) {
		if (is_used[words[idx]]) {
			return false;
		}
		is_used[words[idx]] = true;
	}
	return true;
}

/* 2
 * 2つの文字列が与えられた時、片方がもう片方の並べ替えになっているか決定するメソッドを実装せよ
 *
 * mapで各文字の出現回数を持っておくだけ
 * 時間計算量はO(max(len(a), len(b)), 最大空間計算量も同じ
 */

#include <map>

bool is_sorting_words(std::string a, std::string b) {
	std::map<char, int> cnt;
	for (unsigned int idx = 0; idx < a.size(); ++idx) {
		cnt[a[idx]]++;
	}

	for (unsigned int idx = 0; idx < b.size(); ++idx) {
		cnt[b[idx]]--;
	}

	for (auto x : cnt) {
		if (x.second != 0) return false;
	}
	return true;
}
