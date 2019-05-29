#include "OpenCV.h"

int main()
{
	Show_image();
	VideoStream();
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}