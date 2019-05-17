#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//数组的引用int (&data)[400]

Mat black = Mat::zeros(Size(1200,400),CV_8UC3);

//每次都刷新全部数组
void draw_black(vector<int> &data)
{
	black.setTo(0);
	int location;
	for(int i = 1;i<400;i++){
		cout << data[i] << endl;
		//location 按照顺序画
		location = 3*i-1;
		Point point1(location,400-data[i]);
		Point point2(location,399);
		line(black,point1,point2,Scalar(255,255,255),2);
	}
	imshow("result",black);
	waitKey(10);
}

//最后一次刷新数组,只是在排好序的数组图上刷新颜色不用归零
void draw_last(vector<int> &data)
{
	//black.setTo(0);
	int location;
	for(int i = 1;i<400;i++){
		cout << data[i] << endl;
		//location 按照顺序画
		location = 3*i-1;
		Point point1(location,400-data[i]);
		Point point2(location,399);
		line(black,point1,point2,Scalar(255,0,0),2);
		imshow("result",black);
		waitKey(1);
	}
}