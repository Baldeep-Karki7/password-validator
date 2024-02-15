#include <iostream>

bool checkUcase(std::string pass)
{
    for (char c : pass)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

bool checkLcase(std::string pass)
{
    for (char c : pass)
    {
        if (islower(c))
        {
            return true;
        }
    }
    return false;
}

bool checkDigit(std::string pass)
{
    for (char c : pass)
    {
        if (isdigit(c))
        {
            return true;
        }
    }
    return false;
}

bool checkSpecialChar(std::string pass)
{
    for (char c : pass)
    {
        if (!(isalnum(c)))
        {
            return true;
        }
    }
    return false;
}

bool validate(std::string pass)
{
    if (pass.length() < 7)
    {
        std::cout << "Length of password must be equal to or greater than 7"
                  << "\n"
                  << std::endl;
        return false;
    }

    bool hasUcase = false;
    bool hasLcase = false;
    bool hasdigit = false;
    bool hasSpecialChar = false;

    hasUcase = checkUcase(pass);
    hasLcase = checkLcase(pass);
    hasdigit = checkDigit(pass);
    hasSpecialChar = checkSpecialChar(pass);

    if (hasUcase == false)
    {
        std::cout << "At least one Upper Case letter required"
                  << "\n"
                  << std::endl;
    }
    if (hasdigit == false)
    {
        std::cout << "At least one number required"
                  << "\n"
                  << std::endl;
    }
    if (hasSpecialChar == false)
    {
        std::cout << "At least one Special character required eg: ., @, # etc." << std::endl;
    }

    if (hasdigit && hasUcase && hasLcase && hasSpecialChar)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display(bool result)
{
    if (result)
    {
        std::cout << "Your password is strong" << std::endl;
    }
    else
    {
        std::cout << "Your password is not strong enough" << std::endl;
    }
}

int main()
{
    std::string password;
    std::cout << "Enter your password" << std::endl;
    std::cin >> password;

    bool result = validate(password);
    display(result);
}