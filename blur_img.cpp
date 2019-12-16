#include "blur_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdlib>

using namespace cv;
using namespace std;

BlurImg::BlurImg()
{

}

Payload* BlurImg::stage_op(Payload *ele)
{
    int randomNumber = std::rand()%50 + 1;
    cout<< "Blur:"<<ele->inpath<<"\n";
    blur(ele->image, ele->image,Size(randomNumber, randomNumber));
    return ele;
}
  