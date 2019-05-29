#include "OpenCV.h"

void Show_image()
{
	Mat frame;
	frame = imread("./person_051.jpg", IMREAD_COLOR); // CV_LOAD_IMAGE_COLOR -> IMREAD_COLOR�� ����
	if (!frame.data) // �̹����� �о���� ������ ���
	{
		cerr << "Image have not data\n";
	}
	else
	{
		imshow("Original", frame); // �̹��� �����ֱ�
		waitKey(0); 
	}
	
	destroyWindow("Original"); // ������ ����
}