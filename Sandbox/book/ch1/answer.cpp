/* 1
解説:
・ASCIIかUnicodeか確認する
-> これによりCSの知識があることをアピールできる

・先頭から使われている文字を保持しておく O(n), O(1)
・全ての文字について、他の文字と比較する O(n^2), O(1)
・ソートして隣あう文字が同じか確認する O(nlogn), O(n)
*/

#include <string>
#include <set>
#include <algorithm>
#include "main.hpp"

// ASCIIと仮定する
// 最悪時間計算量はO(len(str))
// 空間計算量はO(文字セットの種類)
// bool is_unique(std::string str) {
//     // 鳩の巣原理によって128文字より大きい時は必ずfalse
//     if (str.size() > 128) return false;

//     // 既に使用済みかを確認するためのstd::setを用意しておく
//     // 配列よりは空間計算量を落とせる
//     std::set<int> st;
//     for (unsigned int idx=0; idx<str.size(); ++idx) {
//         // 既に使われていたらfalse
//         if (st.count(str[idx]) > 0) return false;
//         st.insert(str[idx]);
//     }
//     return true;    
// }

// bitsetを使うことで空間計算量を落とす
// 時間計算量はO(len(str))
// 空間計算量はO(log(文字セットの種類))
bool is_unique(std::string str) {
    if (str.size() > 128) return false;

    // ASCII文字と仮定すると、高々8ビットで使用したかを確認できる
    int used = 0;
    for (unsigned int idx=0; idx<str.size(); ++idx) {
        int val = str[idx] - 'a';
        if (used & (1 << val)) {
            return false;
        }
        used |= (1 << val);
    }
    return true;
}

/* 2
2つの文字列が与えられた時に、片方がもう片方の文字列の並べ替えになっているかを確認する

解法
1: 両方ソートして同じかを比較する O(nlogn), (n)
2: 同じ文字種の数を数える O(n), O(1)
*/

// 1
bool is_sorting_words(std::string s, std::string t) {
    // 文字列長が等しくなければそもそも並べ替えても等しくならない
    if (s.size() != t.size()) return false;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    for (unsigned int idx=0; idx < s.size(); ++idx) {
        if (s[idx] != t[idx]) return false;
    }
    return true;
}

// 2: main.cppで実装ずみ

/* 3
文字列をURLパーセントエンコーディングしてね( -> %20)

解法:
1. 1度空白文字列の数を数えてメモリを確保してから、置き換えを行う

C++のstd::stringはmutableなのであまり気にしなくておk
*/

// 1
std::string replace_space(std::string words) {
    std::string res = "";
    unsigned int ri = 0;

    for (unsigned int idx=0; idx<words.size(); ++idx) {
        if (words[idx] == ' ') {
            res += "%20";
        } else {
            res += words[idx];
        }
    }
    return res;
}

/* 4
文字列が回文の順列かを確認する

解法
1. ハッシュテーブルを用いて各文字が何回出現するかを確認し、そのような文字列が複数存在しないことを確認する
2. 1.における後半の確認操作を前半の処理と共に実施する
3. 文字種の出現回数が偶数か奇数か知れれば良いのでbitsetで出現回数を管理し、
   最後に1引いたものとANDをとったときに0になっていなければビットが2つ以上立っていることになる(すなわち、奇数が2つ以上あるということ)
*/

bool is_palindrome_permutation(std::string words) {
    int used = 0;
    for (unsigned int idx=0; idx<words.size(); ++idx) {
        // 出現するのはASCII文字列(小文字のみ)と仮定する
        // 出現したらXORをかけることでビット列を反転できる
        used ^= (1 << (words[idx] - 'a'));
    }

// 立っているビットが高々1つしかないことを保証する
    return (used & (used - 1)) == 0;
}