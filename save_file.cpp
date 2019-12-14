#include "save_file.h"
#include "payload.h"
#include <iostream>

using namespace std;

SaveFile::SaveFile()
{

}

Payload* SaveFile::stage_op(Payload *ele)
{
    std::cout << "Saving\n";
    ele->num +=2;
    return ele;
}
