#include "open_file.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

OpenFile::OpenFile()
{

}

Payload* OpenFile::stage_op(Payload *ele)
{
    ele->image = imread(ele->inpath, IMREAD_UNCHANGED);
    std::cout << "Opening "<< ele->inpath << "\n";
    return ele;
}
