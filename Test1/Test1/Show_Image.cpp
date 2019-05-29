#include "OpenCV.h"

void Show_image()
{
	Mat frame;
	frame = imread("./person_051.jpg", IMREAD_COLOR); // CV_LOAD_IMAGE_COLOR -> IMREAD_COLOR로 변경
	if (!frame.data) // 이미지를 읽어오지 못했을 경우
	{
		cerr << "Image have not data\n";
	}
	else
	{
		imshow("Original", frame); // 이미지 보여주기
		waitKey(0); 
	}
	
	destroyWindow("Original"); // 윈도우 제거
}