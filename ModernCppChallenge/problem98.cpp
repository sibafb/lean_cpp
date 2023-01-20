#include <iostream>
#include <string>
#include <string_view>

#include "curl_easy.h"
#include "curl_exception.h"

class imap_connection
{
public:
    imap_connection(std::string const & url, unsigned short const port, std::string_view user, std::string_view pass)
            : url(url), port(port), user(user), pass(pass) {}

    std::string get_folders();
    std::vector<unsigned int> fetch_unread_uids(std::string_view folder);
    std::string fetch_email(std::string_view folder, unsigned int uid);

private:
    void setup_easy(curl::curl_easy& easy)
    {
        easy.add<CURLOPT_PORT>(port);
        easy.add<CURLOPT_USERNAME>(user.c_str());
        easy.add<CURLOPT_PASSWORD>(pass.c_str());
        easy.add<CURLOPT_USE_SSL>(CURLUSESSL_ALL);
        easy.add<CURLOPT_SSL_VERIFYPEER>(0L);
        easy.add<CURLOPT_SSL_VERIFYHOST>(0L);
        easy.add<CURLOPT_USERAGENT>("libvurl-agent/1.0");
    }

    std::string const url;
    unsigned short const port;
    std::string const user;
    std::string const pass;
};

std::string imap_connection::get_folders()
{
    std::stringstream str;
    try
    {
        curl::curl_ios<std::stringstream> writer(str);

        curl::curl_easy easy(writer);
        easy.add<CURLOPT_URL>(url.c_str());
        setup_easy(easy);

        easy.perform();
    }
    catch (curl::curl_easy_exception const & error)
    {
        error.print_traceback();
    }
    return str.str();
}

int main()
{
    imap_connection imap("imaps://imap.gmail.com",993, "...(your username)...", "...(your username)...");
    auto folders = imap.get_folders();
    std::cout << folders << std::endl;

    auto uids = imap.fetch_unread_uids("inbox");
    if (!uids.empty())
    {
        auto email = imap.fetch_email("inbox", uids.back());
        std::cout << email << std::endl;
    }
}