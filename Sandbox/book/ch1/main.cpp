/* 1: 重複のある文字列
  ある文字列が全て固有であるかを判定するアルゴリズムを実装せよ
  文字種に制限があるなら、色々工夫できそう
  今回はASCII全てと仮定する
  -> 時間計算量はO(文字列長さ)、空間計算量はO(文字種)
*/

// #include "main.hpp"

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

/* 3
 * 文字列内に出現する全ての空白文字を%20で置換するメソッドを書け
 *
 * 前から走査するだけで良い
 * 時間計算量はO(len(words)), 空間計算量はO(len(words))
 */

#include <iostream>

std::string replace_space(std::string words) {
	std::string res = "";
	unsigned int wi = 0;
	while (wi < words.size()) {
		if (words[wi] == ' ') {
			res += "%20";
		} else {
			res += words[wi];
		}
		++wi;
	}
	return res;
}

/* 4
 * 与えられた文字列が回文の順列になるか答えるメソッドを書け
 *
 * 前から出てきた回数をカウントして奇数の文字が2文字以上存在しないことを示せば良い
 * 時間計算量はO(len(words))空間計算量はO(len(words))
 *
 */

bool is_palindrome_permutation(std::string words) {
	std::map<char, int> cnt;
	for (unsigned int idx = 0; idx < words.size(); ++idx) {
		cnt[words[idx]]++;
	}

	bool odd = false;
	for (auto x : cnt) {
		if (x.second % 2 == 0) continue;
		if (odd) return false;
		odd = true;
	}
	return true;
}

/* 5
* 文字の挿入、編集、削除、置き換え操作1回で文字列が作れるか
* 前から1文字ずつみていき、変更点がどれだけあるかを確認する
* 文字列をswapすると、挿入と削除は同じ操作
* O(1)
*/

bool can_be_made(std::string before, std::string after) {
	if (before.size() > after.size()) {
		std::string tmp = before;
		before = after; 
		after = tmp;
	}
	unsigned int bi=0, ai=0;
	bool done = false;
	while(bi < before.size() && ai < after.size()) {
		if (before[bi] == after[ai]) {
			++bi; ++ai;
			continue;
		}
		if (before[bi] == after[ai+1]) {
			++bi; ai += 2;
			if (done) return false;
			done = true;
			continue;
		}
		if (before[bi+1] == after[ai+1]) {
			bi += 2;
			ai += 2;
			if (done) return false;
			done = true;
			continue;
		}
		return false;
	}
	return true;
}

/* 6
文字列を圧縮する
O(N)
*/

std::string compress(std::string words) {
	std::string res = "";
	for (unsigned idx=0; idx<words.size(); ++idx) {
		unsigned cnt = 1;
		for (;idx+1 < words.size() && words[idx] == words[idx+1]; ++idx, ++cnt);
		res += words[idx] + std::to_string(cnt);
	}

	if (res.size() < words.size()) return res;
	return words;
}

/* 7
文字列を90度時計回りに回転する

*/

