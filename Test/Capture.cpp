#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

#define DEBUG

const string CTRL_PANEL("control panel");

int brightness = 8;
int contrast = 50;
int exposure = 10;
int sharpness = 10;


void main()
{
	Mat frame;
	VideoCapture cap(0);
	namedWindow(CTRL_PANEL);
	createTrackbar("brightness", CTRL_PANEL, &brightness,16);
	createTrackbar("contrast", CTRL_PANEL, &contrast, 100);
	//createTrackbar("exposure", CTRL_PANEL, &exposure, 10);
	createTrackbar("sharpness", CTRL_PANEL, &sharpness, 20);

	while(cap.isOpened())
	{
		cap.set(CV_CAP_PROP_BRIGHTNESS, brightness);
		cap.set(CV_CAP_PROP_CONTRAST, contrast);
		//cap.set(CV_CAP_PROP_EXPOSURE, exposure);
		cap.set(CV_CAP_PROP_SHARPNESS, sharpness);

#ifdef DEBUG
		cout << cap.get(CV_CAP_PROP_SHARPNESS) << endl;
#endif // DEBUG

		cap >> frame;
		if (frame.data != NULL)
		{
			imshow("capture", frame);
		}
		waitKey(1);
	}

	system("pause");
}