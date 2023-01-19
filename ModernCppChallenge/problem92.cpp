#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include "sha.h"
#include "md5.h"
#include "hex.h"
#include "files.h"

namespace fs = std::filesystem;
template <class Hash>
std::string compute_hash(fs::path const & filepath)
{
    std::string digest;
    Hash hash;

    CryptoPP::FileSource source(
        filepath.c_str(),
        true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest))));
    return digest;
}

int main()
{
    std::string path;
    std::cout << "Path: ";
    std::cin >> path;

    try
    {
        std::cout << "SHA1: "
                  << compute_hash<CryptoPP::SHA1>(path) << std::endl;
        std::cout << "SHA256: "
                  << compute_hash<CryptoPP::SHA256>(path) << std::endl;
        std::cout << "MD5: "
                  << cpmpute_hash<CryptoPP::MD5(path) << std::endl;
    }
    catch (std::exception const & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}