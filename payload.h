#ifndef __PAYLOAD__H__
#define __PAYLOAD__H__
#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
using namespace cv;

class Payload {
    public:
    string path;

    Mat image;
};

#endif