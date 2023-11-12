
## Cmake

CMakeを使用したビルドは2パターン

1. build ディレクトリを作成してcmake
    ```
    learn_cpp/ModernCppChallenge/problem77_movieTitleTopdf/build$ cmake ..
    ```
    ```
    make -j4 #オプションは適切なものを選ぶ
    ```
1. cmake のbuildコマンドを使用してbuild
    ```
    cmake -S ./ -B ./build/ # ./がCMakeFileの場所 
    ```
    ```
    cmake --build ./build/
    ```

## git の多用コマンド(ブランクが空いたときの備忘)

1. git のブランチ削除
    ```
    git branch -d /branchName
    ```

## GDBの使用方法
 本来は[ドキュメント](https://www.sourceware.org/gdb/documentation/)を見るべきだが備忘のため。
- ビルド時のオプションで
    ```
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    ```
    と記載する。

- 実行ファイルを読み込んで起動
    ```
    gdb ./build/problemXX
    ```
- breakを貼る
    ```
    (gdb) break problemXX.cpp:999
    ```
    ※999は行数指定。
- run をする。breakがあればそこで止まる。
    ```
    (gdb) run
    ```
- break pointでのローカル変数の確認
    ```
    (gdb) info locals
    ```
- ブレーク停止時の各種コマンド
    - プログラム継続
        ```
        (gdb) c
        ```
    - バックトレースの確認
        ```
        (gdb) bt 
        ```
    - break時にvaruablesの中身を表示するコマンド
        ```
        (gdb) print price
        ```
    - ステップイン
        ```
        (gdb) s
        ```
    - ステップ実行
        ```
        (gdb) n
        ```

### coredump の使い方
　ArchWikiの[コアダンプ](https://wiki.archlinux.jp/index.php/%E3%82%B3%E3%82%A2%E3%83%80%E3%83%B3%E3%83%97)の記述
- コアダンプのリスト表示
    ```
    coredumpctl list
    ```
- 最後のコアダンプをGDBで読み込み
    ```
    coredumpctl gdb -1
    ```