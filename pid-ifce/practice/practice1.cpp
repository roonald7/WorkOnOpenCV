#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int, char**) 
{
    auto imagePath = "./resources/lena512.bmp";
    auto windowLabel1 = "Display Original Image - Practice 1";
    auto windowLabel2 = "Display Gray Image - Practice 1";

    double min;
    double max;

    auto image = imread(imagePath);
    Mat imgGray;

    cvtColor(image, imgGray, COLOR_BGR2GRAY);

    namedWindow(windowLabel1, WINDOW_AUTOSIZE);
    imshow(windowLabel1, image);

    namedWindow(windowLabel2, WINDOW_AUTOSIZE);
    imshow(windowLabel2, imgGray);
    
    minMaxIdx(imgGray, &min, &max);

    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;

    waitKey(0);
}
