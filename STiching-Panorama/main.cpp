
#include <iostream>
#include <fstream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include < stdio.h >    
#include < opencv2\opencv.hpp > 

using namespace std;
using namespace cv;


int main()
{
	vector< Mat > vImg;
	Mat rImg;

	vImg.push_back(imread("C:/panL.jpg"));
	vImg.push_back(imread("C:/panR.jpg"));

	Stitcher stitcher = Stitcher::createDefault();

	unsigned long AAtime = 0, BBtime = 0; //check processing time  
	AAtime = getTickCount(); //check processing time  

	Stitcher::Status status = stitcher.stitch(vImg, rImg);

	BBtime = getTickCount(); //check processing time

	cout << "Processing time" << (BBtime - AAtime) / getTickFrequency();

	if (Stitcher::OK == status)
		imshow("Stitching Result", rImg);
	else
		cout << "Failed!";

	waitKey(0);

	return 0;
}
