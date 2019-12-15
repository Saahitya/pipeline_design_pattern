#include "gray_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

GrayImg::GrayImg()
{

}

Payload* GrayImg::stage_op(Payload *ele)
{
    cout<< "Graying:"<<ele->inpath<<"\n";
    cvtColor(ele->image, ele->image, COLOR_BGR2GRAY);

    return ele;
}
  