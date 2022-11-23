#ifndef CEASER_CHIPHER_DECRYPTION_H
#define CEASER_CHIPHER_DECRYPTION_H

#include <vector>
#include <string>
#include <set>
#include <map>

namespace domains
{
    inline std::map<std::wstring, int> EncryptedDomain;
    inline std::set<std::wstring>      DomainsList({});
}

void readDomainList();

void countEncryptedDomainNames(const std::vector<std::wstring>& domainNames);


std::wstring CeaserShift(const std::wstring& line, const int& key);

void CeaserChipherDecrypt(std::vector<std::wstring>& email);

#endif // CEASER_CHIPHER_DECRYPTION_H
