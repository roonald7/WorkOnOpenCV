#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void displayImage();
void displayVideo();
void displayWebcam();
void imageEffect();

int main(int, char**) 
{
    imageEffect();

    return 0;
}

void displayImage()
{
    string imagePath = "./resources/arara.jpg";
    
    Mat image;
    image = imread(imagePath);

    if(!image.data)
    {
        cout << "No image data!" << endl;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
}

void displayVideo()
{
    string videoPath = "";
    
    VideoCapture cap(videoPath);
    Mat img;

    while(1)
    {
        cap.read(img);

        imshow("Image", img);

        waitKey(0);
    }
}

void displayWebcam()
{
    VideoCapture cap(0);
    Mat img;

    while(1)
    {
        cap.read(img);

        imshow("Image", img);

        waitKey(1);
    }
}

void imageEffect()
{
    string imagePath = "./resources/arara.jpg";
    Mat imgOriginal = imread(imagePath);
    Mat imgGray, imgBlur, imgCanny;

    cvtColor(imgOriginal, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgOriginal, imgBlur, Size(3,3), 3, 0);
    Canny(imgBlur, imgCanny, 50, 150);

    imshow("Original", imgOriginal);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    
    waitKey(0);
}