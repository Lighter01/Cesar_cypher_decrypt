#include "ceaser_chipher_decryption.h"

#include <iostream>

#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

#include <cmath>

void readDomainList()
{
    std::ifstream file("data/domains_list.txt");
    std::string tmp_string;

    while (std::getline(file, tmp_string)) {
        domains::DomainsList.insert(tmp_string);
    }

    file.close();
    return;
}

void countEncryptedDomainNames(const std::vector<std::string>& domainNames)
{

    for (const auto& it : domainNames) {
        domains::EncryptedDomain[it.substr(it.rfind('.'))]++;
    }

    for (const auto& it : domains::EncryptedDomain) {
        std::cout << it.first << " " << it.second << "\n";
    }

    return;
}


std::string CeaserShift(const std::string& line, const int& key)
{
    std::string result;
    for (auto it : line) {
        if (it > 0) {
            if (it >= 'a') {
                if ((it + key) / 123 == 0) {
                    result += static_cast<char>(it + key);
                } else {
                    result += static_cast<char>('a' + ((it + key) % 123));
                }
            } else {
                result += it;
            }
        }
        else {

            if (it == -72) { // если ё
                it = -8;
            }
            else if (it == -88) { // если Ё
                it = -40;
            }

            if (it < -32) { // Заглавные
                if ((it + key) <= -1) { // не вышли за "Я"
                    result += static_cast<char>(it + key);
                }
                else { // вышли за "Я"
                    result += static_cast<char>((-64) + (it + key));
                }
            }
            else { // строчные
                if ((it + key) <= -1) { // не вышли за "я"
                    result += static_cast<char>(it + key);
                }
                else { // вышли за "я"
                    result += static_cast<char>((-32) + (it + key));
                }
            }
        }
    }

    return result;
}

void CeaserChipherDecrypt(std::vector<std::string>& email, std::vector<std::string>& address)
{
    std::ofstream result("result.csv");
    std::string tmp_string;
    int key;

    for (int i = 0; i < email.size(); ++i) {

        key = 0;

        do {
            tmp_string = CeaserShift(email.at(i), ++key);
        } while (key != 25 && domains::DomainsList.find(tmp_string.substr(tmp_string.rfind('.') + 1)) == domains::DomainsList.end());

        result << email.at(i) << ';' << tmp_string << ";key: " << key << ';';

        tmp_string = CeaserShift(address.at(i), key + 6);
        result << address.at(i) << ';'<< tmp_string << ";key: " << key + 6 << '\n';
    }

    result.close();
}





