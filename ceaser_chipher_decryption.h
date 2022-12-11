#ifndef CEASER_CHIPHER_DECRYPTION_H
#define CEASER_CHIPHER_DECRYPTION_H

#include <vector>
#include <string>
#include <set>
#include <map>

namespace domains
{
    inline std::map<std::string, int> EncryptedDomain;
    inline std::set<std::string>      DomainsList({});
}

void readDomainList();

void countEncryptedDomainNames(const std::vector<std::string>& domainNames);


std::string CeaserShift(const std::string& line, const int& key);

void CeaserChipherDecrypt(std::vector<std::string>& email, std::vector<std::string>& address);

#endif // CEASER_CHIPHER_DECRYPTION_H
