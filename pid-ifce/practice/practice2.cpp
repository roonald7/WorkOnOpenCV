#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int, char**) 
{
    auto imagePath = "./resources/lena154g.bmp";
    auto windowLabel1 = "Display Original Image - Practice 2";
    auto windowLabel2 = "Display Resized Image (Nearest Interpolation) - Practice 2";
    auto windowLabel3 = "Display Resized Image (Bilinear Interpolation) - Practice 2";
    auto windowLabel4 = "Display Resized Image (Bicubic Interpolation) - Practice 2";
    auto windowLabel5 = "Display Resized Image (Bicubic Interpolation 2x) - Practice 2";

    auto image = imread(imagePath);
    Mat imgResizeNearest;
    Mat imgResizeBilinear;
    Mat imgResizeBicubic;
    Mat imgResizeBicubic2x;

    resize(image, imgResizeNearest, Size(), 3.33, 3.33, INTER_NEAREST);
    resize(image, imgResizeBilinear, Size(), 3.33, 3.33, INTER_LINEAR);
    resize(image, imgResizeBicubic, Size(), 3.33, 3.33, INTER_CUBIC);
    resize(image, imgResizeBicubic2x, Size(), 2, 2, INTER_CUBIC);

    namedWindow(windowLabel1, WINDOW_AUTOSIZE);
    imshow(windowLabel1, image);

    namedWindow(windowLabel2, WINDOW_AUTOSIZE);
    imshow(windowLabel2, imgResizeNearest);

    namedWindow(windowLabel3, WINDOW_AUTOSIZE);
    imshow(windowLabel3, imgResizeBilinear);

    namedWindow(windowLabel4, WINDOW_AUTOSIZE);
    imshow(windowLabel4, imgResizeBicubic);
    
    namedWindow(windowLabel5, WINDOW_AUTOSIZE);
    imshow(windowLabel5, imgResizeBicubic2x);

    waitKey(0);
}
