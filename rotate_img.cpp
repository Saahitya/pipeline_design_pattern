#include "rotate_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

RotateImg::RotateImg()
{

}

Payload* RotateImg::stage_op(Payload *ele)
{
    cout<< "Rotate:"<<ele->inpath<<"\n";
    rotate(ele->image, ele->image, ROTATE_90_CLOCKWISE);

    return ele;
}
  