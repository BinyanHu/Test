//#include<opencv2\opencv.hpp>
//
//using namespace cv;
//
//void main()
//{
//	VideoCapture vcap("C:\\Users\\Binyan Hu\\Documents\\Visual Studio 2017\\Projects\\RuneRecognition\\RuneRecognition\\bigBuff.avi");
//	Mat frame;
//	for (;;)
//	{
//		vcap >> frame;
//		Mat filtedImg;
//		cv::medianBlur(frame, filtedImg, 3);//must be even!
//		imshow("ori", frame);
//		imshow("filted", filtedImg);
//		waitKey(1);
//	}
//}