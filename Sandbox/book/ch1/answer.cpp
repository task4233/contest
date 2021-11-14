/*
解説:
・ASCIIかUnicodeか確認する
-> これによりCSの知識があることをアピールできる

・先頭から使われている文字を保持しておく O(n), O(1)
・全ての文字について、他の文字と比較する O(n^2), O(1)
・ソートして隣あう文字が同じか確認する O(nlogn), O(n)
*/

#include <string>
#include <set>
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