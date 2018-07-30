/* License:
   Oct. 3, 2008
   Right to use this code in any way you want without warrenty, support or any guarentee of it working.

   BOOK: It would be nice if you cited it:
   Learning OpenCV: Computer Vision with the OpenCV Library
     by Gary Bradski and Adrian Kaehler
     Published by O'Reilly Media, October 3, 2008
 
   AVAILABLE AT: 
     http://www.amazon.com/Learning-OpenCV-Computer-Vision-Library/dp/0596516134
     Or: http://oreilly.com/catalog/9780596516130/
     ISBN-10: 0596516134 or: ISBN-13: 978-0596516130    

   OTHER OPENCV SITES:
   * The source code is on sourceforge at:
     http://sourceforge.net/projects/opencvlibrary/
   * The OpenCV wiki page (As of Oct 1, 2008 this is down for changing over servers, but should come back):
     http://opencvlibrary.sourceforge.net/
   * An active user group is at:
     http://tech.groups.yahoo.com/group/OpenCV/
   * The minutes of weekly OpenCV development meetings are at:
     http://pr.willowgarage.com/wiki/OpenCV
*/
#include <opencv2/opencv.hpp>

using namespace cv;

void example2_4( Mat &image )
{
    // Create some windows to show the input
    // and output images in.
    //
    namedWindow( "Example2_4-in", CV_WINDOW_AUTOSIZE );
    namedWindow( "Example2_4-out", CV_WINDOW_AUTOSIZE );
    
    // Create a window to show our input image
    //
    imshow( "Example2_4-in", image );
    
    // Create an image to hold the smoothed output
    //
    Mat out( image.size(), CV_8UC3 );

    // Do the smoothing
    //
    GaussianBlur( image, out, Size(5,5), 0 );

    // Show the smoothed image in the output window
    //
    imshow( "Example2_4-out", out );
    
    // Wait for the user to hit a key, then clean up the windows
    //
    waitKey( 0 ); 
    destroyWindow("Example2_4-in" );
    destroyWindow("Example2_4-out" );
    
}

int main( int argc, char** argv )
{
  Mat img = imread( argv[1] );
  example2_4( img );
}

