#include "OpenCV.h"

void VideoStream()
{
	Mat frame;
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
	// open selected camera using selected API
	cap.open(deviceID + apiID);
	Size size = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT)); // 동영상 파일을 저장하기 위한 준비
	double fps = 30.0;
	VideoWriter writer;

	writer.open("D:/output.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, size, true);
	// check if we succeeded
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
		return;
	}

	//--- GRAB AND WRITE LOOP
	cout << "Start grabbing" << endl
		<< "Press any key to terminate" << endl;
	for (;;)
	{
		// wait for a new frame from camera and store it into 'frame'
		cap.read(frame);
		if (frame.empty())
		{
			cerr << "빈 영상이 저장되었습니다.\n";
			break;
		}
		// show live and wait for a key with timeout long enough to show images
		writer.write(frame); // frame save
		imshow("Live", frame);
		if (waitKey(5) >= 0)
			break;
	}

	writer.release();

}