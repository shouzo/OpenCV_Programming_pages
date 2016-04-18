// Introduce_1.cpp
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main()
{
	char FileName[10]="danny.jpg";				// 要顯示的影像名稱
	IplImage *Image1 = cvLoadImage(FileName,1);		// 存入影像

	cvNamedWindow("Show Image",0);			// 命名顯示在螢幕上的視窗名稱
	cvResizeWindow("Show Image",600,800);		// 設定視窗的大小
	cvShowImage("Show Image",Image1);			// 顯示視窗
	cvWaitKey(0);						// 鍵盤事件(阻斷)

	cvDestroyWindow("Show Image");			// 銷毀視窗	
	cvReleaseImage(&Image1);				// 釋放記憶體

	return 0;
}