//#include <Windows.h>
//#include <iostream>
//#include <ctime>
//#include <string>
//
//
//int CaptureAnImage(HWND hWnd, HWND wndPositioning);
//
//
///*
// * Returns a buffer containing the pixels of a bitmap in 32bpp format.
// *
// * Parameters:
// *   hBmp    The source bitmap.
// *   hdc     A matching device context. Typically a device
// *           context from a window or the screen.
// *
// * Returns:
// *   A pointer to a buffer containing the pixel data or NULL on failure.
// *   A pixel can be indexed with the following syntax: pixels[(y * width) + x]
// *   The buffer should be released with free when no longer needed.
// */
//
////hud_enable 0
//
///*
// * Helper function that fills out a pbmi struct for a 32bpp bitmap.
// */
//static BOOL CompleteBitmapInfo(HBITMAP hBmp, BITMAPINFO* pbmi)
//{
//	BITMAP bmo;
//
//	if (GetObject(hBmp, sizeof(BITMAP), &bmo))
//	{
//		ZeroMemory(pbmi, sizeof(BITMAPINFO));
//
//		pbmi->bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
//		pbmi->bmiHeader.biWidth       = bmo.bmWidth;
//		pbmi->bmiHeader.biHeight      = -bmo.bmHeight;
//		pbmi->bmiHeader.biPlanes      = 1;
//		pbmi->bmiHeader.biBitCount    = 32; /* Request a 32bpp bitmap. */
//		pbmi->bmiHeader.biCompression = BI_RGB;
//
//		return TRUE;
//	}
//
//	return FALSE;
//}
//
//PDWORD GetBitmapPixels(HBITMAP hBmp, HDC hdc)
//{
//	BITMAPINFO   bmi;
//	PDWORD       pixels = NULL;
//
//	if (CompleteBitmapInfo(hBmp, &bmi))
//	{
//		pixels = (PDWORD) malloc(-bmi.bmiHeader.biHeight * bmi.bmiHeader.biWidth * sizeof(DWORD));
//
//		if (pixels)
//		{
//		 	if (GetDIBits(hdc, hBmp, 0, -bmi.bmiHeader.biHeight, pixels, &bmi, DIB_RGB_COLORS))
//			{
//				return pixels;
//			}
//		}
//	}
//
//	free(pixels);
//	return NULL;
//}
//
////Some of code taken from stack overflow
//void TakeScreenshot(BITMAPINFO* bi, BYTE* buf, HWND &hActive) //gets the bitmap data
//{
//  HBITMAP hBitmap;
//  BITMAP Bitmap;
//  RECT r;
//
//  HDC ActiveDC = GetDC(hActive);
//  HDC CopyDC = CreateCompatibleDC(ActiveDC);
//
//  GetWindowRect(hActive, &r);
//
//  int scrWidth = r.right-r.left;
//  int scrHeight = r.bottom-r.top;
//
//  hBitmap = CreateCompatibleBitmap(ActiveDC, scrWidth, scrHeight);
//  SelectObject(CopyDC, hBitmap);
//
//  BitBlt(CopyDC, 0, 0, scrWidth, scrHeight, ActiveDC, 0, 0, SRCCOPY);
//
//  GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
//
//  int cClrBits = Bitmap.bmPlanes*Bitmap.bmBitsPixel;
//
//  memset(bi, 0, sizeof(BITMAPINFO));
//
//  bi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
//  bi->bmiHeader.biWidth = Bitmap.bmWidth;
//  bi->bmiHeader.biHeight = Bitmap.bmHeight;
//  bi->bmiHeader.biPlanes = Bitmap.bmPlanes;
//  bi->bmiHeader.biBitCount = Bitmap.bmBitsPixel;
//
//  if(cClrBits<24)
//  {
//    bi->bmiHeader.biClrUsed = (1<<cClrBits);
//  }
//
//  bi->bmiHeader.biCompression = BI_RGB;
//  bi->bmiHeader.biSizeImage = ((bi->bmiHeader.biWidth * cClrBits +31) & ~31)/8*bi->bmiHeader.biHeight;
//
//  int i = GetDIBits(CopyDC, hBitmap, 0, scrHeight, buf, bi, DIB_RGB_COLORS);
//
//  printf("GetDIBits returned %i\n", i);
//
//  ReleaseDC(hActive, ActiveDC);
//  DeleteDC(CopyDC);
//}
//
//
//
//void InitializeScreenshot(HWND &appWnd, HDC &hdcScreen, HDC &hdcWindow, HDC &hdcMemDC, HBITMAP &hbmScreen, RECT &rcClient)
//{
//	// get the device context of the screen
//	hdcScreen = GetDC(NULL);     
//	// and a device context to put it in
//	hdcMemDC = CreateCompatibleDC(hdcWindow);
//
//	// maybe worth checking these are positive values
//	hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);
//	    SelectObject(hdcMemDC,hbmScreen);
//	// get a new bitmap
//	HGDIOBJ hOldBitmap = SelectObject(hdcMemDC, hbmScreen);
//
//	BitBlt(hdcMemDC, 0, 0,  rcClient.right-rcClient.left, rcClient.bottom-rcClient.top, hdcWindow, 0, 0, SRCCOPY);
//	HGDIOBJ hBitmap= SelectObject(hdcMemDC, hOldBitmap);	
//
//
//
//
//	if(!appWnd)
//    {
//        MessageBox(GetDesktopWindow(), "Unable to find window","Failed", MB_OK);
//        return;
//    }
//
//    // Retrieve the handle to a display device context for the client 
//    // area of the window. 
//    hdcScreen = GetDC(NULL);
//    hdcWindow = GetDC(HWND_DESKTOP);
//
//    // Create a compatible DC which is used in a BitBlt from the window DC
//    hdcMemDC = CreateCompatibleDC(hdcWindow); 
//
//    if(!hdcMemDC)
//    {
//        MessageBox(GetDesktopWindow(), "CreateCompatibleDC has failed","Failed", MB_OK);
//        //goto done;
//    }
//
//
//    //This is the best stretch mode
//    SetStretchBltMode(hdcWindow,HALFTONE);
//
//    //The source DC is the entire screen and the destination DC is the current window (HWND)
//    if(!StretchBlt(hdcWindow, 
//               0,0, 
//               rcClient.right, rcClient.bottom, 
//               hdcScreen, 
//               0,0,
//               GetSystemMetrics (SM_CXSCREEN),
//               GetSystemMetrics (SM_CYSCREEN),
//               SRCCOPY))
//    {
//        MessageBox(GetDesktopWindow(), "StretchBlt has failed","Failed", MB_OK);
//       // goto done;
//    }
//    
//    // Create a compatible bitmap from the Window DC
//    hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);
//    
//    if(!hbmScreen)
//    {
//        MessageBox(GetDesktopWindow(), "CreateCompatibleBitmap Failed","Failed", MB_OK);
//        //goto done;
//    }
//
//    // Select the compatible bitmap into the compatible memory DC.
//    SelectObject(hdcMemDC,hbmScreen);
//    
//    // Bit block transfer into our compatible memory DC.
//    if(!BitBlt(hdcMemDC, 
//               0,0, 
//               rcClient.right-rcClient.left, rcClient.bottom-rcClient.top, 
//               hdcWindow, 
//               0,0,
//               SRCCOPY))
//    {
//        MessageBox(GetDesktopWindow(), "BitBlt has failed", "Failed", MB_OK);
//        //goto done;
//    }
//}
//
//
//
//
//int main()
//{
//	int debugRuntime = clock();
//	std::string gameWindow = "Call of duty 4";
//	HWND appWnd = FindWindow(0, gameWindow.c_str());//Call of duty 4 // Untitled (58%) - Paint.NET v3.5.10//rgb - Windows Photo Viewer
//	while(!appWnd)
//    {
//		system("CLS");
//		appWnd = FindWindow(0, gameWindow.c_str());
//		std::cout << "Looking for " << gameWindow << std::endl;
//		Sleep(1000);
//        //MessageBox(HWND_DESKTOP, "Unable to find window","Failed", MB_OK);
//        //return 0;
//    }
//	std::cout << "Found " << gameWindow << std::endl;
//	
//	HWND hWnd = GetDesktopWindow();
//    HDC hdcWindow;
//
//	int tickTock = clock();
//
//	COLORREF col;
//	//define our rgb colours
//	int r;
//	int g;
//	int b;
//	int shootingTimer = clock();
//	bool foundTarget = false;
//
//	//2 because we only want to scan every other pixel, this makes it faster
//	//and still ensures we dont miss any content(any more than this and you are 
//	//risking skipping a relevant pixel)
//	POINT initialCursor;
//	//find our window's position so we only scan around the window and not the whole desktop
//	RECT rcClientPositioning;
//	// Get the client area for size calculation
//    RECT rcClient;
//	PDWORD pixels;
//
//	while(!GetAsyncKeyState(VK_ESCAPE))
//	{
//		TakeScreenshot(
//		GetClientRect(GetDesktopWindow(), &rcClient);
//		//InitializeScreenshot(appWnd, hdcScreen, hdcWindow, hdcMemDC, hbmScreen, rcClient);
//		GetWindowRect(appWnd, &rcClientPositioning);
//		// Get the BITMAP from the HBITMAP
//		GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen);
//
//		// Select the compatible bitmap into the compatible memory DC.
//		//SelectObject(hdcMemDC,hbmScreen);
//		//shootingTimer = clock();
//		//grab our contents
//		pixels = GetBitmapPixels(hbmScreen, hdcWindow);
//		//reset our found target
//		foundTarget = false;
//		//find where we were looking at first
//		GetCursorPos(&initialCursor);
//		//std::cout << "initial cursor x= " << initialCursor.x << " y= " << initialCursor.y << std::endl;
//
//
//
//
//		/*
//		for(int y = rcClientPositioning.top+45; y < rcClientPositioning.bottom; y+=1)
//		{
//			//3 because we are checking RGB every time
//			for(int x = rcClientPositioning.left+15; x < rcClientPositioning.right; x+=3)
//			{
//
//				//SetCursorPos(x, y);
//				//define our colours, FOR SOME Reason red needs GetBlueValue and blue the GetRedValue()
//				//not sure why but it doesnt affect anything
//				//IT SEEMS AS THOUGH GETDIBITS GRABS THINGS REVERSE
//				b = (int)GetRValue(pixels[(y * bmpScreen.bmWidth) + x]);
//				g = (int)GetGValue(pixels[(y * bmpScreen.bmWidth) + (x+1)]);
//				r = (int)GetBValue(pixels[(y * bmpScreen.bmWidth) + (x+2)]);
//
//				//PRINT RGB
//				//std::cout << r << ", " << g << ", " << b << std::endl;
//
//				//Sleep(1000);
//				 
//				//RED DETECTED
//				if(r >120 && g < 40 && b < 40)
//				//if(r == 255 && g == 216 && b == 0)
//				{
//
//					//std::cout << "yes?"  << std::endl;
//					//only shoot every x ms, i.e. give the player some actual control
//					if(clock() - shootingTimer > 1050)
//					{
//						//shootingTimer = clock();
//						//std::cout << r << ", " << g << ", " << b << std::endl;
//						//std::cout << "Bam juice x:"<< x << "y:" << y << std::endl;
//					//	SetCursorPos(x, y);
//						////mousemove(x, y);
//						//mouse_event(MOUSEEVENTF_LEFTDOWN,x, y,0,0);
//						//mouse_event(MOUSEEVENTF_LEFTUP,x, y,0,0);
//						////system("pause");
//						////Sleep(10);
//					}
//				}
//				if(GetAsyncKeyState(VK_ESCAPE))
//				{
//					exit(0);
//				}
//	
//			}
//			if(foundTarget)break;
//		}
//		*/
//		//free our allocated memory, otherwise crashesRus
//		free(pixels);
//		DeleteObject(hbmScreen);
//		DeleteObject(hdcMemDC);
//		ReleaseDC(NULL,hdcScreen);
//		ReleaseDC(hWnd,hdcWindow);
//	}
//
//	std::cout << "Took  " << clock() - debugRuntime  << " milliseconds to scan whole page"<< std::endl;
//	system("pause");
//}
//
//
//
//
//
//
//
////
//////-----------------------IGNORE---------------------
////int CaptureAn
////    //Close the handle for the file that was created
////    CloseHandle(hFile);
////       
////    //Clean up
////done:
////    DeleteObject(hbmScreen);
////    DeleteObject(hdcMemDC);
////    ReleaseDC(NULL,hdcScreen);
////    ReleaseDC(hWnd,hdcWindow);
////	*/
////
////
////
////
////    return 0;
////