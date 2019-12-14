#include "open_file.h"
#include "payload.h"
#include <iostream>

using namespace std;

OpenFile::OpenFile()
{

}

Payload* OpenFile::stage_op(Payload *ele)
{
    std::cout << "Opening file\n";
    ele->num *= 2;
    return ele;
}
