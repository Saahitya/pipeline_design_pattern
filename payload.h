#ifndef __PAYLOAD__H__
#define __PAYLOAD__H__
#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
using namespace cv;

class Payload {
    public:
    string inpath;
    string outpath;
    Mat image;
};

#endif