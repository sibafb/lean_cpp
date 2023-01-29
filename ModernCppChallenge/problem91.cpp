#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include "sha.h"
#include "md5.h"
#include "hex.h"
#include "files.h"

#include <filesystem>

namespace fs = std::filesystem;

struct user
{
    int id;
    std::string username;
    std::string password;
    std::string firstname;
    std::string lastname;
};

std::string get_hash(std::string const & password)
{
    CryptoPP::SHA512 sha;
    CryptoPP::byte digest[CryptoPP::SHA512::DIGESTSIZE];

   sha.CalculateDigest(digest, reinterpret_cast<CryptoPP::byte const*>(password.c_str()), password.length());

    CryptoPP::HexEncoder encoder;
    std::string result;

    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    return result;
}

int mian()
{
    std::vector<user> const users
    {
        {
            101, "scarface",
            "07A8D53ADAB635ADDF39BAEACFB799FD7C5BFDEE365F3AA721B7E25B54A4E87D419ADDEA34BC3073BAC472DCF4657E50C0F6781DDD8FE883653D10F7930E78FF",
            "Tony", "Montana"
        },
        {
            202, "neo",
            "C2CC277BCC10888ECEE90F0F09EE9666199C2699922EFB41EA7E88067B2C075F3DD3FBF3CFE9D0EC6173668DD83C111342F91E941A2CADC46A3A814848AA9B05",
            "Thomas","Anderson"
        },
        {
            303, "godfather",
            "0EA7A0306FE00CD22DF1B835796EC32ACC702208E0B052B15F9393BCCF5EE9ECD8BAAF27840D4D3E6BCC3BB3B009259F6F73CC77480C065DDE67CD9BEA14AA4D",
            "Vito", "Corleone"
        }
    };
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    auto hash = get_hash(password);

    auto pos = std::find_if(
        std::cbegin(users), std::cend(users),
        [username, hash](user const & u) { return u.username == username && u.password == hash; });

    if (pos != std::cend(users))
        std::cout << "Login successful!" << std::endl;
    else
        std::cout << "INvalid username or password" << std::endl;
}