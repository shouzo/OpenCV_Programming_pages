#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

using namespace std;
using namespace cv;


/* Global Variables	 全域變數區 */
int DELAY_CAPTION = 3000;					// 在這裡可以調整投影片顯示的間隔時間
int DELAY_BLUR = 3000;
int MAX_KERNEL_LENGTH = 15;					// 設定處理影像的最大核心值
int laplace_slider = 0;						// 設定Laplace operate滑動條的初始值

int scale = 1;
int delta = 0;
int ddepth = CV_16S;

Mat src, src_gray, dst;
const char* file_name;						// 設定圖片名稱
const char* window_name = "Laplace Demo";	// 設定視窗名稱


/* Function headers	 副程式宣告區 */
int noise( void );							// 處理雜訊圖片
int display_caption( const char* caption );	// 投影片隔頁(顯示文字)
int display_dst( int delay );				// 顯示圖片視窗

int trackbar( void );						// 顯示調整條控制視窗
void on_trackbar( int, void* );				// 顯示附有調整條之副程式


/* function main  主程式入口 */
int main( void )
{
	// 處理"高斯雜訊"之圖片
	namedWindow( window_name, WINDOW_AUTOSIZE );	// 新增視窗
	file_name = "gaussian-noise-image.jpg";			// 設定要處理之圖片名稱
	noise();										// 將圖片去除雜訊(投影片)
	display_caption( "Laplace Operate..." ); 		// 顯示隔頁文字(使用調整條)
	trackbar();								   		// 顯示調整條控制視窗
	waitKey(0);										// 等待鍵盤按下任一按鍵
	destroyWindow( window_name );					// 銷毀視窗

	
	// 處理"椒鹽雜訊"之圖片
	namedWindow( window_name, WINDOW_AUTOSIZE );	// 新增視窗
	file_name = "salt&pepper-noise-image.jpg";		// 設定要處理之圖片名稱
	noise();										// 將圖片去除雜訊(投影片)
	display_caption( "Laplace Operate..." ); 		// 顯示隔頁文字(使用調整條)
	trackbar();								   		// 顯示調整條控制視窗
	waitKey(0);										// 等待鍵盤按下任一按鍵
	destroyWindow( window_name );					// 銷毀視窗
	
	
	waitKey(0);
	return 0;
}


/* function noise  處理雜訊圖片之附程式 */
int noise( void )
{
	src = imread( file_name, 1 );			// 載入來源圖片
	if( display_caption( "Original Image (Before)" ) != 0 ) { return 0; }
	dst = src.clone();
	if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }


	// Applying Gaussian blur  使用Gaussian濾波器
	if( display_caption( "Gaussian Blur (After)" ) != 0 ) { return 0; }
	
	// 先使用高斯濾波器濾除雜訊
	GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );	// 高斯濾波器
	cvtColor( src, src_gray, COLOR_RGB2GRAY );					// 將圖片轉換成灰階模式
	dst = src.clone();
	
	if( display_dst( DELAY_BLUR ) != 0 ) { return 0; }
}


/* function display_caption  投影片隔頁(顯示文字) */
int display_caption( const char* caption )
{
	dst = Mat::zeros( src.size(), src.type() );
	putText( dst, caption,
		   Point( src.cols/4, src.rows/2),
		   FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

	imshow( window_name, dst );
	int c = waitKey( DELAY_CAPTION );
	if( c >= 0 ) { return -1; }
	return 0;
}


/* function display_dst  顯示圖片視窗 */
int display_dst( int delay )
{
	imshow( window_name, dst );
	int c = waitKey ( delay );
	if( c >= 0 ) { return -1; }
	return 0;
}


/* 顯示調整條控制視窗 */
int trackbar( void )
{
	src = imread( file_name, 1 );	// 載入來源圖片
	dst = src.clone();
	createTrackbar( "Laplace Operate", window_name, &laplace_slider, MAX_KERNEL_LENGTH, on_trackbar );
	on_trackbar( laplace_slider, 0 );
	
	return 0;
}


/* 顯示附有調整條之副程式 */
void on_trackbar( int, void* )
{
	/// Apply Laplace function
	Mat abs_dst;
	Laplacian( src_gray, dst, ddepth, 2 * laplace_slider + 1, scale, delta, BORDER_DEFAULT );	// Laplacian 函式
	imshow( window_name, dst );
	
	convertScaleAbs( dst, abs_dst );
	imshow( window_name, abs_dst );		// Show what you got
	
		
	// 設定經濾波過後的新圖片名稱
	char new_name[200] = "(after)";
	strcat( new_name, file_name );
	imwrite( new_name, dst );	// 產生新圖片
}