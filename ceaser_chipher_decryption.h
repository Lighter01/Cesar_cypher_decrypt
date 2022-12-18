#ifndef CEASER_CHIPHER_DECRYPTION_H
#define CEASER_CHIPHER_DECRYPTION_H

#include <vector>
#include <string>
#include <set>
#include <map>

/*!
 * \brief domains - пространство имен, хранящее словарь доменных имен.
 * \param DomainLists - словарь доменных имен
 * \param EncryptedDomain - не нужен, тхнический контейнер
 */
namespace domains
{
    inline std::map<std::string, int> EncryptedDomain;
    inline std::set<std::string>      DomainsList({});
}

/*!
 * \brief readDomainList - функция для составления словаря доменных имен.
 *
 * Читает список доменных имен из файла.
 */
void readDomainList();

void countEncryptedDomainNames(const std::vector<std::string>& domainNames);

/*!
 * \brief CeaserShift -
 * \param line
 * \param key
 * \return
 */
std::string CeaserShift(const std::string& line, const int& key);

void CeaserChipherDecrypt(std::vector<std::string>& email, std::vector<std::string>& address);

#endif // CEASER_CHIPHER_DECRYPTION_H
