#ifndef RUN_DECRYPTOR_H
#define RUN_DECRYPTOR_H

#include <string>
#include <vector>

/*!
 * Пространство имен, хранящее контейнеры, в которые будут записаны зашифрованные данные.
 */
namespace containers
{
    inline std::vector<std::string> phone;
    inline std::vector<std::string> email;
    inline std::vector<std::string> address;
}

/*!
 * Пространство имен, содержащее функции-обертки, сокращающие вызов всех основных методов программы
 */
namespace methods
{
    /*!
     * \brief readEncryptedData - функция, вызывающая чтение зашифрованных данных из файла в соответствующие контейнеры
     */
    void readEncryptedData();

    /*!
     * \brief testProg - функция, вызывающая все основные процессы программы, т.е. непосредственно дешифровку исходного файла.
     */
    void testProg();
}


#endif // RUN_DECRYPTOR_H
