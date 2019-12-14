#include "save_file.h"
#include "payload.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

SaveFile::SaveFile()
{

}

Payload* SaveFile::stage_op(Payload *ele)
{
    blur(ele->image, ele->image,Size(10,10));
    imwrite(ele->outpath, ele->image);
    // namedWindow( "bat", WINDOW_AUTOSIZE ); 

    // Displays an image in the specified window.
    // first argument: name of the window
    // second argument: image to be shown(Mat object)
    // imshow( "bat", ele->image ); 

    // waitKey(0); // Wait infinite time for a keypress
    std::cout << "Saving "<< ele->outpath << "\n";
    return ele;
}
