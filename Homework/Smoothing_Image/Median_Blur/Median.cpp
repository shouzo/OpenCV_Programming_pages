#include <iostream>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

using namespace std;
using namespace cv;

/// Global Variables	// 在這裡可以調整投影片顯示的間隔時間
int DELAY_CAPTION = 3000;
int DELAY_BLUR = 500;
int MAX_KERNEL_LENGTH = 40;

Mat src; Mat dst;
char window_name[] = "Median Demo";

/// Function headers
int display_caption( const char* caption );
int display_dst( int delay );


/**
 * function main
 */
int main( void )
{
  namedWindow( window_name, WINDOW_AUTOSIZE );

  /// Load the source image
  src = imread( "../shouzo.jpg", 1 );

  if( display_caption( "Original Image (Before)" ) != 0 ) { return 0; }

  dst = src.clone();
  if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }




  /// Applying Median blur
  if( display_caption( "Median Blur (After)" ) != 0 ) { return 0; }

  for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
      { medianBlur ( src, dst, i );
        if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } }




  /// Wait until user press a key
  display_caption( "End: Press a key..." );

  waitKey(0);

  return 0;
}

/**
 * @function display_caption
 */
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

/**
 * @function display_dst
 */
int display_dst( int delay )
{
  imshow( window_name, dst );
  int c = waitKey ( delay );
  if( c >= 0 ) { return -1; }
  return 0;
}
