#include "open_file.h"
#include "payload.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

OpenFile::OpenFile()
{

}

Payload OpenFile::stage_op(Payload& ele)
{
    ele.image = imread("big.jpeg", IMREAD_UNCHANGED);

    return ele;
}
