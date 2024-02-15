#include <iostream>

bool validate(std::string input)
{
    if (input.length() < 6)
    {
        return false;
    }

    bool hasUcase = false;
    bool hasLcase = false;
    bool hasSpecialchar = false;
    bool hasdigit = false;

    for (char c : input)
    {
        if (isupper(c))
        {
            hasUcase = true;
        }
        else if (islower(c))
        {
            hasLcase = true;
        }
        else if (isdigit(c))
        {
            hasdigit = true;
        }
        else if (!(isalnum(c)))
        {
            hasSpecialchar = true;
        }

        if (hasUcase && hasLcase && hasdigit && hasSpecialchar)
        {
            break;
        }
    }
    return true;
}

int main()
{
    std::string password;
    std::cout << "Enter your password" << std::endl;
    std::cin >> password;

    if (validate(password))
    {
        std::cout << "Your password is strong" << std::endl;
    }
    else
    {
        std::cout << "Your password is not strong enough" << std::endl;
    }
}