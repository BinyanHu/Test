//#include<opencv2\opencv.hpp>
//
//using namespace cv;
//using std::to_string;
//
//void showRECTs(const Rect& rect, const Mat&numImg, Mat& dstImg, const string& windowName, const Scalar& color, const int waitTime)
//{
//	if (numImg.channels() == 1)	cvtColor(numImg, dstImg, cv::COLOR_GRAY2BGR);
//	else if (numImg.data != dstImg.data) numImg.copyTo(dstImg);
//	rectangle(dstImg, rect, color);
//	imshow(windowName, dstImg);
//	waitKey(waitTime);
//}
//void showRECTs(const vector<Rect>& rects, const Mat&numImg, Mat& dstImg, const string& windowName, const Scalar& color, const int waitTime)
//{
//	if (numImg.channels() == 1)	 cvtColor(numImg, dstImg, cv::COLOR_GRAY2BGR);
//	else if (numImg.data != dstImg.data) numImg.copyTo(dstImg);
//	for (const Rect& rect : rects)
//	{
//		rectangle(dstImg, rect, color);
//	}
//	imshow(windowName, dstImg);
//	waitKey(waitTime);
//}
//
//
//int main()
//{
//	for (size_t i = 0; i < 9; i++)
//	{
//		Mat numImg = imread("numbers\\"+to_string(i)+".jpg");
//		cvtColor(numImg, numImg, COLOR_BGR2GRAY);
//		imshow("img", numImg);
//		waitKey();
//
//		cv::normalize(numImg, numImg, 0, 255, cv::NORM_MINMAX);
//		numImg = 255 - numImg;
//		imshow("inverse", numImg);
//		waitKey();
//
//		threshold(numImg, numImg, 120, 255, cv::THRESH_BINARY);
//		imshow("norm", numImg);
//		waitKey();
//
//		vector<Mat>contours;
//		findContours(numImg.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//		imshow("after contours", numImg);
//		waitKey();
//
//		for (size_t index = 0; index < contours.size(); index++)
//		{
//			Mat dstImg = Mat::zeros(numImg.size(), CV_8UC3);
//			drawContours(dstImg, contours, index, Scalar(255, 255, 255), CV_FILLED);
//			imshow("contours", dstImg);
//			waitKey();
//
//			const Rect boundRect = boundingRect(contours[index]);
//			showRECTs(boundRect, dstImg, Mat(), "contours", Scalar(255, 0, 0), 0);
//			if (boundRect.area() > 0.3*numImg.cols*numImg.rows && boundRect.area() < 0.95*numImg.cols*numImg.rows)
//			{
//				showRECTs(boundRect, numImg, Mat(), "contours", Scalar(0, 255, 0), 0);
//				Mat rectImg = numImg(boundRect);
//				resize(rectImg, rectImg, Size(32, 32));
//				imwrite(to_string(i) + ".jpg", rectImg);
//			}
//		}
//
//	}
//}