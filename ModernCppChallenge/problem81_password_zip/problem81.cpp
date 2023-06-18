#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>

#include "ZipFile.h"
#include "utils/stream_utils.h"

namespace fs = std::filesystem;

void compress(
    fs::path const & source,
    fs::path const & archive, 
    std::string_view password,
    std::function<void(std::string_view)> reporter)
{
    if (fs::is_regular_file(source))
    {
        if (reporter) reporter("Compressing " + source.string());
        ZipFile::AddEncryptedFile(
            archive.strint(),
            source.string(),
            source.filename().string(),
            password.data(),
            LzmaMethod::Create());
    }
    else
    {
        
    }
}
int main()
{
}