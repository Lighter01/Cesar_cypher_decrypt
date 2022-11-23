#include "ceaser_chipher_decryption.h"

#include <iostream>

#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

void readDomainList()
{
    std::wifstream file("data/domains_list.txt");
    std::wstring tmp_string;

    while (std::getline(file, tmp_string)) {
        domains::DomainsList.insert(tmp_string);
    }

    file.close();
    return;
}

void countEncryptedDomainNames(const std::vector<std::wstring>& domainNames)
{

    for (const auto& it : domainNames) {
        domains::EncryptedDomain[it.substr(it.rfind('.'))]++;
    }

    for (const auto& it : domains::EncryptedDomain) {
        std::wcout << it.first << L" " << it.second << L"\n";
    }

    return;
}


std::wstring CeaserShift(const std::wstring& line, const int& key)
{
    std::wstring result;
    for (auto& it : line) {
        if (it >= L'a') {
            if ((it + key) / 123 == 0) {
                result += static_cast<wchar_t>(it + key);
            } else {
                result += static_cast<wchar_t>(L'a' + ((it + key) % 123));
            }
        } else {
            result += it;
        }
    }

    return result;
}

void CeaserChipherDecrypt(std::vector<std::wstring>& email)
{
    std::wstring tmp_string;
    int key;

    for (auto& it : email) {

        key = 1;

        do {
            tmp_string = CeaserShift(it, key++);
        } while (key != 26 && domains::DomainsList.find(tmp_string.substr(tmp_string.rfind('.') + 1)) == domains::DomainsList.end());

        if (key != 26) {
            std::wcout << it << "    turns into ---->   "<< tmp_string << '\n';
        } else {
            std::wcout << it << "    failed to encrypt\n";
        }
    }
}





