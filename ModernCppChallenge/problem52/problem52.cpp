//問題
// ``文字列の文字の順列生成
// 与えられた文字列を文字に分解して並び替え、すべての順列をコンソールに出力する関数を書きなさい。この関数
// では、再帰を使うものと使わないものの２つのバージョンを作りなさい。

#include <iostream>
#include <string>
#include <algorithm>

//recursive function
std::string print_charactors_recursive(std::string &input)
{
    if (!input.empty())
    {
        std::sort(std::begin(input),std::end(input));
        char first_char = input[0];
        std::cout<<first_char<<std::endl;
        input.erase(0);
        return print_charactors_recursive(input);
    }
    else{
        return 0;
    }
}

//non-recursive function
void print_sorted_charactors(const std::string &str)
{
    std::string output_string = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (output_string.empty())
        {
            output_string.insert(0, str, i, 1);
            std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        if (output_string.at(0) > str.at(i))
        {
            output_string.insert(0, str, i, 1);
            std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        if (output_string.back() < str.at(i))
        {
            output_string.insert(output_string.length(), str, i, 1);
            std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        {
            for(int j =1; j < output_string.length();j++)
            {
                std::cout << "str.at(i) :" << str.at(i) << "  output_string.at(j)  :" << output_string.at(j) << std::endl; 
                if(str.at(i) < output_string.at(j))
                {
                    std::cout << "hit ! str.at(i) :" << str.at(i) << "  output_string.at(j)  :" << output_string.at(j) << std::endl; 
                    output_string.insert(j, str, i, 1);
                    std::cout <<"output:" << output_string << std::endl;
                    break;
                }
            }
        }
    }
    std::cout <<"output:" << output_string << std::endl;
}

int main()
{
 std::string abcde = "afbcde";
 printf("print_charactors_recursive");
 //print_charactors_recursive(abcde);
 printf("print_sorted_charactors\n");
 print_sorted_charactors("fgyuiuislruiesruiea");
}