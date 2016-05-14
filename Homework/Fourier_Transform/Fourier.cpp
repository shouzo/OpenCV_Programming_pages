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
Mat src, dst;
Mat I;

const char* file_name;						// 設定圖片名稱
const char* window_name = "Fourier Demo";	// 設定視窗名稱


/* Function headers	 副程式宣告區 */
int Origin( void );							// 顯示原來的圖片
int Fourier( void );						// 處理雜訊圖片							
int display_caption( const char* caption );	// 投影片隔頁(顯示文字)
int display_dst( int delay );				// 顯示圖片視窗


/* function main  主程式入口 */
int main( void )
{
	// 處理"高斯雜訊"之圖片
	namedWindow( window_name, WINDOW_AUTOSIZE );	// 新增視窗
	file_name = "gaussian-noise-image.jpg";			// 設定要處理之圖片名稱
	Origin();										// 顯示原圖
	
	display_caption( "Fourier Transform..." ); 		// 顯示隔頁文字
	Fourier();										// 進行傅立葉轉換
	waitKey(0);										// 等待鍵盤按下任一按鍵
	destroyWindow( window_name );					// 銷毀視窗

	
	// 處理"椒鹽雜訊"之圖片
	namedWindow( window_name, WINDOW_AUTOSIZE );	// 新增視窗
	file_name = "salt&pepper-noise-image.jpg";		// 設定要處理之圖片名稱
	Origin();										// 顯示原圖
	
	display_caption( "Fourier Transform..." ); 		// 顯示隔頁文字
	Fourier();										// 將圖片去除雜訊
	waitKey(0);										// 等待鍵盤按下任一按鍵
	destroyWindow( window_name );					// 銷毀視窗
	
	
	waitKey(0);
	return 0;
}


int Origin( void )
{
	src = imread( file_name, 1 );			// 載入來源圖片
	if( display_caption( "Original Image (Before)" ) != 0 ) { return 0; }
	dst = src.clone();
	if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }
}


int Fourier( void )
{
    I = imread( file_name, CV_LOAD_IMAGE_GRAYSCALE );			// 載入來源圖片
	
	Mat padded;                            //expand input image to optimal size
    int m = getOptimalDFTSize( I.rows );
    int n = getOptimalDFTSize( I.cols ); // on the border add zero values
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

    dft(complexI, complexI);            // this way the result may fit in the source matrix

    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    Mat magI = planes[0];

    magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);

    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;

    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magI, magI, 0, 1, NORM_MINMAX); // Transform the matrix with float values into a
                                            // viewable image form (float between values 0 and 1).    
    dst = magI.clone();
		
	if( display_dst( DELAY_CAPTION ) != 0 )
	{ return 0;	}
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