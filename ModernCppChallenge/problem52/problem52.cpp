//問題
// ``文字列の文字の順列生成
// 与えられた文字列を文字に分解して並び替え、すべての順列をコンソールに出力する関数を書きなさい。この関数
// では、再帰を使うものと使わないものの２つのバージョンを作りなさい。

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

//recursive function
std::string print_charactors_recursive(std::string &input)
{
    if (input.size() >= 2)
    {
        char to_remove_char = 'z' + 1;
        int to_remove_idx = input.length() + 1;
        for(int i = 0 ; i < input.length(); i++)
        {
            if(to_remove_char > input.at(i))
            {
                to_remove_char = input.at(i);
                to_remove_idx = i;
            }
        }
        std::cout<< input.at(to_remove_idx) <<std::endl;
        input.erase(to_remove_idx,1);
        // std::cout<< input <<std::endl;
        return print_charactors_recursive(input);
    }
    else{
        std::cout<<input.at(0) <<std::endl;
        return "0";
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
            //std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        if (output_string.at(0) > str.at(i))
        {
            output_string.insert(0, str, i, 1);
            //std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        if (output_string.back() < str.at(i))
        {
            output_string.insert(output_string.length(), str, i, 1);
            //std::cout <<"output:" << output_string << std::endl;
            continue;
        }else
        {
            for(int j =1; j < output_string.length();j++)
            {
                //std::cout << "str.at(i) :" << str.at(i) << "  output_string.at(j)  :" << output_string.at(j) << std::endl; 
                if(str.at(i) < output_string.at(j))
                {
                    //std::cout << "hit ! str.at(i) :" << str.at(i) << "  output_string.at(j)  :" << output_string.at(j) << std::endl; 
                    output_string.insert(j, str, i, 1);
                    //std::cout <<"output:" << output_string << std::endl;
                    break;
                }
            }
        }
    }
    std::cout <<"output:" << output_string << std::endl;
}

// answer
void print_permutation(std::string str)
{
    std::sort(std::begin(str), std::end(str));

    do
    {
        std::cout << str << std::endl;
    } while (std::next_permutation(std::begin(str),std::end(str)));
}

int main()
{
 std::string str = "afbcde";
 std::cout << "print_charactors_recursive" << std::endl;
 print_charactors_recursive(str);
 std::cout << "print_sorted_charactors" << std::endl;
 print_sorted_charactors(str.c_str());
 
 print_permutation(str.c_str());
}