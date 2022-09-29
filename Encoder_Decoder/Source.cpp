/*
* str, (string)
* chr, (char)
* uit, (unsigned int)
*/

#include <iostream>
#include <string>

#include <cmath>
#include <cstdint>

#include "short.h"

namespace encode
{
    str v1(str input, uit key)
    {
        str result{ "" };
        for (int i{ 0 }; i < input.length(); ++i)
        {
            chr c{ input[i] };
            result += (static_cast<uit>(c)) + key;
        }
        return result;
    }
}

namespace decode
{
    str v1(str input, uit key)
    {
        str result{ "" };
        for (int i{ 0 }; i < input.length(); ++i)
        {
            chr c{ input[i] };
            result += (static_cast<uit>(c)) - key;
        }
        return result;
    }
}

void cls() 
{
    std::system("cls");
}

void ask();

void ask()
{
    cls();
    std::cout << "Do you wish to encode, or decode: ";
    str eod{};
    std::cin >> eod;
    cls();
    std::cout << "Select the variation (current: 1 - 1): ";
    uit var{};
    std::cin >> var;
    cls();
    std::cout << "Enter the input: ";
    str inp{};
    std::getline(std::cin >> std::ws, inp);
    cls();
    std::cout << "Enter the key: ";
    str key{};
    std::cin >> key;
    cls();
    str out{};
    switch (eod[0])
    {
    case 'e':
        switch (var)
        {
        case 1:
            out = encode::v1(inp, std::stoi(key));
            break;
        }
        break;
    case 'd':
        switch (var)
        {
        case 1:
            out = decode::v1(inp, std::stoi(key));
            break;
        }
        break;
    }
    std::cout << "Output: " << out << '\n';
    std::cout << "Restart? y/n: ";
    chr ans{};
    std::cin >> ans;
    switch (ans) 
    {
    case 'y':
        ask();
        break;
    case 'n':
        std::system("exit");
        break;
    }
}

int main()
{
    std::system("title Encoder / Decoder by ROMAHKAO");
    ask();
}