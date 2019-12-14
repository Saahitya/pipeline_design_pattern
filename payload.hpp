#ifndef __PAYLOAD__H__
#define __PAYLOAD__H__
#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
using namespace cv;

class Payload {
    string path;

    Mat image;

    public:
    Payload();
};

#endif