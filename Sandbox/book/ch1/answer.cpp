/*
解説:
・ASCIIかUnicodeか確認する
-> これによりCSの知識があることをアピールできる
・
*/

#include <string>
#include <set>
#include "main.hpp"

// ASCIIと仮定する
bool is_unique(std::string str) {
    // 鳩の巣原理によって128文字より大きい時は必ずfalse
    if (str.size() > 128) return false;

    // 既に使用済みかを確認するためのstd::setを用意しておく
    // 配列よりは空間計算量を落とせる
    std::set<int> st;
    for (unsigned int idx=0; idx<str.size(); ++idx) {
        // 既に使われていたらfalse
        if (st.count(str[idx]) > 0) return false;
        st.insert(str[idx]);
    }
    return true;    
}