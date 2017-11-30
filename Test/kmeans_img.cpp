#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <imgproc/imgproc.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/ml/ml.hpp>
#include<time.h>

using namespace cv;
using namespace std;

#define CV_32FC5 CV_MAKETYPE(CV_32F,5)
typedef Vec<float, 5> Vec5f;

const string imgPath = "0.jpg";
const float kk = 0.1;

void main()
{
	Mat img = imread(imgPath);
	//resize(img, img, Size(480, 270));
	namedWindow("Source Image");
	imshow("Source Image", img);
	Mat samples(img.cols*img.rows, 1, CV_32FC5);//CV_32FC3); //生成一维采样点,包括所有图像像素点,注意采样点格式为32bit浮点数。
	Mat labels(img.cols*img.rows, 1, CV_32SC1); //标记矩阵，32位整形
	
	//Mat_<Vec3f>::iterator iSample = samples.begin<Vec3f>();
	//Mat_<Vec3b>::iterator iColor = img.begin<Vec3b>();
	//while (iColor != img.end<Vec3b>())
	//{
	//	(*iSample)[0] = static_cast<float>((*iColor)[0]);
	//	(*iSample)[1] = static_cast<float>((*iColor)[1]);
	//	(*iSample)[2] = static_cast<float>((*iColor)[2]);
	//	iColor++;
	//	iSample++;
	//}



	int k = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			samples.at<Vec5f>(k, 0)[0] = static_cast<float>(img.at<Vec3b>(i, j)[0]);
			samples.at<Vec5f>(k, 0)[1] = static_cast<float>(img.at<Vec3b>(i, j)[1]);
			samples.at<Vec5f>(k, 0)[2] = static_cast<float>(img.at<Vec3b>(i, j)[2]);
			samples.at<Vec5f>(k, 0)[3] = static_cast<float>(i*kk);
			samples.at<Vec5f>(k, 0)[4] = static_cast<float>(j*kk);
			k++;
		}
	}

	int clusterCount = 6;
	Mat centers(clusterCount, 1, samples.type());
	kmeans(samples, clusterCount, labels, TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0), 3, KMEANS_PP_CENTERS, centers);

	//我们已知有3个聚类，用各自中心点表示。
	Mat kmeansImg(img.rows, img.cols, CV_8UC3);
	k = 0;
	for (int i = 0; i < kmeansImg.rows; i++)
	{
		for (int j = 0; j < kmeansImg.cols; j++)
		{
			kmeansImg.at<Vec3b>(i, j)[0] = centers.at<Vec5f>(labels.at<int>(k, 0), 0)[0];
			kmeansImg.at<Vec3b>(i, j)[1] = centers.at<Vec5f>(labels.at<int>(k, 0), 0)[1];
			kmeansImg.at<Vec3b>(i, j)[2] = centers.at<Vec5f>(labels.at<int>(k, 0), 0)[2];
			k++;
		}
	}

	namedWindow("K-Means");
	imshow("K-Means", kmeansImg);
	imwrite(imgPath + "_K-Means_" + to_string(time(NULL)) + ".jpg", kmeansImg);
	waitKey(0);

}