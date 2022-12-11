#include "run_decryptor.h"

#include <fstream>
#include <sstream>

#include <iostream>

#include "ceaser_chipher_decryption.h"

void methods::readEncryptedData()
{
    std::ifstream file("data/student_v.1.18.csv");
    std::string tmp_string;
    std::stringstream tmp_stream;
    int counter;

    while (std::getline(file, tmp_string)) {
        tmp_stream << tmp_string;

        counter = 0;
        while (std::getline(tmp_stream, tmp_string, ';')) {
            switch (counter++) {
                case 0: {
                    containers::phone.push_back(tmp_string);
                    break;
                }
                case 1: {
                    containers::email.push_back(tmp_string);
                    break;
                }
                case 2: {
                    containers::address.push_back(tmp_string);
                    break;
                }
            }
        }

        tmp_stream.clear();
    }

    file.close();
}

void methods::testProg()
{
    methods::readEncryptedData();
//    countEncryptedDomainNames(containers::email);
    readDomainList();
    CeaserChipherDecrypt(containers::email, containers::address);
}
