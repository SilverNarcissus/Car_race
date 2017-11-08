#include <cstdlib>
#include <iostream>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#define PI 3.1415926

//Uncomment this line at run-time to skip GUI rendering
#define _DEBUG

using namespace cv;
using namespace std;

const string CAM_PATH = "/dev/video0";
const string MAIN_WINDOW_NAME = "Processed Image";
const string CANNY_WINDOW_NAME = "Canny";

Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize=2;



const int CANNY_LOWER_BOUND = 30;
const int CANNY_UPPER_BOUND = 90;
const int HOUGH_THRESHOLD = 100;

int main() {
    Mat image = imread("../race_road4.png");

    //Set the ROI for the image
    Rect roi(0, image.rows / 3, image.cols, image.rows / 3);
    Mat imgROI = image(roi);

    //Canny algorithm
    Mat contours;
    //blur(imgROI,imgROI,Size(30,30));
    Canny(imgROI, contours, CANNY_LOWER_BOUND, CANNY_UPPER_BOUND);

//    // 求 X方向梯度
//    Sobel( imgROI, g_sobelGradient_X, CV_16S, 1, 0, (2*g_sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
//    convertScaleAbs( g_sobelGradient_X, g_sobelAbsGradient_X );//计算绝对值，并将结果转换成8位
//
//    // 求Y方向梯度
//    Sobel( imgROI, g_sobelGradient_Y, CV_16S, 0, 1, (2*g_sobelKernelSize+1), 1, 1, BORDER_DEFAULT );
//    convertScaleAbs( g_sobelGradient_Y, g_sobelAbsGradient_Y );//计算绝对值，并将结果转换成8位
//
//    // 合并梯度
//    addWeighted( g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, contours);

    //转换为GRAY图片
//    IplImage temp = IplImage(contours);
//    IplImage*img_gray=cvCreateImage(cvGetSize(&temp),temp.depth,1);
//    cvCvtColor(&temp,img_gray,CV_RGB2GRAY);
//    contours = Mat(img_gray);


#ifdef _DEBUG
    imshow(CANNY_WINDOW_NAME, contours);
#endif

//    waitKey();
//    return 0;
    vector<Vec4i> lines;
    HoughLinesP(contours, lines, 1, PI / 180, HOUGH_THRESHOLD, 5, 1);
    Mat result(imgROI.size(), CV_8U, Scalar(255));
    imgROI.copyTo(result);
    clog << lines.size() << endl;
    clog << imgROI.cols << endl;

    //Draw the lines and judge the slope
    int color = 50;
    //投票决定应该turn哪边
    int should_turn_left = 0;
    for (vector<Vec4i>::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        line(result, Point((*it)[0], (*it)[1]), Point((*it)[2], (*it)[3]), Scalar(color, color, 255), 20, CV_AA);
        float slope = ((float) (*it)[3] - (*it)[1])/((*it)[2] - (*it)[0]);
        clog << "slope" << slope << endl;
        if(slope <= 2 && slope >= 0.3){
            should_turn_left++;
        }
        if(slope >= -2 && slope <= -0.3){
            should_turn_left--;
        }
        color += 50;
        color %= 256;
        //Filter to remove vertical and horizontal lines,
        //and atan(0.09) equals about 5 degrees.
    }

    if(should_turn_left > 0){
        //turnTo(-10);
    }
    if(should_turn_left < 0){
        //turnTo(10);
    }


#ifdef _DEBUG
    stringstream overlayedText;
    overlayedText << "Lines: " << lines.size() << "TurnTo:" << should_turn_left;
    putText(result, overlayedText.str(), Point(10, result.rows - 10), 2, 0.8, Scalar(0, 0, 255), 0);
    imshow(MAIN_WINDOW_NAME, result);
#endif
    waitKey();
}
