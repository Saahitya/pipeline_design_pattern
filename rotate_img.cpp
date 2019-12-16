#include "rotate_img.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdlib>

using namespace cv;
using namespace std;

RotateImg::RotateImg()
{

}

Payload* RotateImg::stage_op(Payload *ele)
{
    cout<< "Rotate:"<<ele->inpath<<"\n";

    int randomNumber = std::rand()%2;


    rotate(ele->image, ele->image, randomNumber);

    return ele;
}

void RotateImg::tee(Payload *ele)
{
    // std::cout << "this is stuff" << std::endl;
    imwrite(ele->prefix + ele->index + "_teerotate" + ele->suffix, ele->image);
}