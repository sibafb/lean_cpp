50問に絞る

以下51問
2数学　１　２
4言語機能　15　16　17　18　
8文字列と正規表現　23-30
7ストリームとファイルシステム　32　33　34　35　36　37　38
4日付　39　40　42　43
5アルゴリズム　45　46　51　57　58
6並列処理　61-66
5デザインパターン　67-71
4データシリアライゼーション　73-7６
1データベース　85
ユーザ資格情報　91
ファイルハッシュ　92
暗号化と復号　93
96　98


# Q＆A

### std::string_viewの意味

https://cpprefjp.github.io/reference/string_view/basic_string_view.html
を見てみると、文字列リテラルに対して便利な関数を使用できるクラスのようだ。

### std::optionalとは何か

std::optional<std::string>とすると、有効な文字列が入っている場合に文字列が取り出せ、無効な際には当然値が入っていない

以下の文献によると下記のように使える

```
{
std::optional<std::string> optstr;
    std::cout << std::boolalpha << optstr.has_value() << std::endl; // "false"
}
{
    std::optional<std::string> optstr = "Hello, optional!"s;
    std::cout << std::boolalpha << optstr.has_value() << std::endl; // "true"
}
```

型を使って意味を表現する
https://qiita.com/niina/items/6f3a4ea02d591b886148
std::optional のモナド的操作
https://zenn.dev/acd1034/articles/221118-monadic-operation-for-optional

### cctypeの中身

isdigit,isnumalpha,isupper,islowerなどが含まれる。
https://cplusplus.com/reference/cctype/

###  