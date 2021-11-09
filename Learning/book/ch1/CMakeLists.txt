# 基本的な設定
cmake_minimum_required(VERSION 3.13)
project(test_example_project)
# Google Test ライブラリを探す
find_package(GTest)
# 今回作成する実行ファイルexample_test, ソースファイルはmain.cppのみ
add_executable(example_test main.cpp)
# gtest と gtest_main, pthreadをリンクします。
target_link_libraries(example_test ${GTEST_BOTH_LIBRARIES} pthread)
target_include_directories(example_test PUBLIC ${GTEST_INCLUDE_DIRS})