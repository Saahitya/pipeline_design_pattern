#include "blur_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

BlurImg::BlurImg()
{

}

Payload* BlurImg::stage_op(Payload *ele)
{
    cout<< "Blur:"<<ele->inpath<<"\n";
    blur(ele->image, ele->image,Size(50,50));

    return ele;
}
  