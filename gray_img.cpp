#include "gray_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdlib>

using namespace cv;
using namespace std;

GrayImg::GrayImg()
{

}

Payload* GrayImg::stage_op(Payload *ele)
{
    cout<< "Graying:"<<ele->inpath<<"\n";
    if(std::rand()%2) {
        cvtColor(ele->image, ele->image, COLOR_BGR2GRAY);
    }

    return ele;
}

void GrayImg::tee(Payload *ele)
{
    // std::cout << "this is stuff" << std::endl;
    imwrite(ele->prefix + ele->index + "_teegray" + ele->suffix, ele->image);
}
  