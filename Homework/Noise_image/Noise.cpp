#include <iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;


// "胡椒鹽雜訊"副程式
void Add_salt_pepper_Noise(Mat &srcArr, float pa, float pb )
{   
	RNG rng;	// rand number generate
    int amount1 = srcArr.rows*srcArr.cols*pa;
    int amount2 = srcArr.rows*srcArr.cols*pb;
    for(int counter=0; counter<amount1; ++counter)
    {
      
     srcArr.at<uchar>(rng.uniform( 0,srcArr.rows), rng.uniform(0, srcArr.cols)) = 0;

    }
     for (int counter=0; counter<amount2; ++counter)
     {
     	srcArr.at<uchar>(rng.uniform(0,srcArr.rows), rng.uniform(0,srcArr.cols)) = 255;
     }
}


// "增加高斯雜訊"副程式
void Add_gaussian_Noise(Mat &srcArr,double mean,double sigma)	
{
    Mat NoiseArr = srcArr.clone();
    RNG rng;	// rand number generate
    rng.fill(NoiseArr, RNG::NORMAL, mean,sigma);	// 產生高斯雜訊矩陣  

    add(srcArr, NoiseArr, srcArr); // 矩陣"srcArr + NoiseArr -> srcArr"：向 srcArr 增加高斯雜訊
}


//  主程式
int main(int argc, char *argv[])
{
    Mat srcArr;

	if (argc<=1)
	 {   srcArr = imread("shouzo.jpg"); }

	else if (argc>=2)
	 {   srcArr = imread(argv[1]);}

	cvtColor(srcArr,srcArr, CV_RGB2GRAY,1);	// 先將原圖進行灰階處理
	imshow("The original Image", srcArr);
	imwrite("The original Image.jpg", srcArr);

	Mat srcArr1 = srcArr.clone();
	Mat srcArr2 = srcArr.clone();
	

	float sigma, mean, pa, pb;
	cout<<"請分別輸入'胡椒鹽雜訊'的處理參數 pa 和 pb：";
	cin>>pa>>pb;		// 輸入"胡椒鹽雜訊"的處理參數
	
	cout<<"請分別輸入'高斯雜訊'的處理參數 sigma 和 mean：";
	cin>>sigma>>mean;	// 輸入"高斯雜訊"的處理參數

 
	// 使用"胡椒鹽雜訊"進行影像處理
	Add_salt_pepper_Noise(srcArr1, pa, pb);		
	imshow("Add salt and pepper noise to image ", srcArr1);
	imwrite("salt&pepper-noise-image.jpg", srcArr1);

	
 	// 輸入"高斯雜訊"進行影像處理
	Add_gaussian_Noise(srcArr2, mean, sigma);
	imshow("Add gaussian noise to image", srcArr2);
	imwrite("gaussian-noise-image.jpg", srcArr2);
	
	
	waitKey(0);
	return 0;
}
