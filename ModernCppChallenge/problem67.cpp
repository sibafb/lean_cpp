#include <string>
#include <string_view>
#include <memory>
#include <assert.h>

#include <algorithm>

class password_validator
{
public:
    virtual bool validate(std::string_view password) = 0;
    virtual ~password_validator() = default;
};

class length_validator final : public password_validator
{
public:
    explicit length_validator(unsigned int min_length) : length(min_length) {}

    virtual bool validate(std::string_view password) override
    {
        return password.length() >= length;
    }

private:
    unsigned int const length;
};

class password_validator_decorator : public password_validator
{
public:
    explicit password_validator_decorator(
    std::unique_ptr<password_validator> validator) : inner(std::move(validator))
    {
    }

    virtual bool validate(std::string_view password) override
    {
        return inner->validate(password);
    }

private:
    std::unique_ptr<password_validator> inner;
};

class digit_password_validator final : public password_validator_decorator
{
public:
    explicit digit_password_validator(
    std::unique_ptr<password_validator> validator) : password_validator_decorator(
    std::move(validator)) {}
    
    virtual bool validate(std::string_view password) override
    {
        if (!password_validator_decorator::validate(password))
            return false;

        return password.find_first_of("0123456789") != std::string::npos;
    }
};

class case_password_validator final : public password_validator_decorator
{
public:
    explicit case_password_validator(
    std::unique_ptr<password_validator> validator) : password_validator_decorator(
    std::move(validator)) {}

    virtual bool validate(std::string_view password) override
    {
        if (!password_validator_decorator::validate(password))
            return false;
        
        bool const haslower = std::any_of(std::cbegin(password), std::cend(password), islower);
        bool const hasupper = std::any_of(std::cbegin(password), std::cend(password), isupper);

        return haslower && hasupper;
    }
};

class symbol_password_validator final : public password_validator_decorator
{
public:
    explicit symbol_password_validator(std::unique_ptr<password_validator> validator)
                        : password_validator_decorator(std::move(validator)) {}

    virtual bool validate(std::string_view password) override
    {
        if (!password_validator_decorator::validate(password))
            return false;
        
        return password.find_first_of("!@#$%^&*(){}[]?<>") != std::string::npos;
    }
};

int main()
{
    auto validator1 = std::make_unique<digit_password_validator>(std::make_unique<length_validator>(8));

    assert(validator1->validate("abd123!@#"));
    assert(!validator1->validate("avcde!@#"));

    auto validator2 = std::make_unique<symbol_password_validator>(std::make_unique<case_password_validator>(std::make_unique<digit_password_validator>(std::make_unique<length_validator>(8))));

    assert(validator2->validate("Abc123!@#"));
    assert(!validator2->validate("Abc123567"));
}