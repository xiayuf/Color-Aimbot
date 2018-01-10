//#include "ScanContents.h"
//
//
//*INSTRUCTIONS ON HOW TO USE:
//1- Set up chams, load up game
//2- turn this hack on
//3- detect based on colour CURRENTLY BLUE
//4-play game and trigger with specific key CURRENTLY RIGHT MOUSE
//*/
//
//
//#define UP 1
//#define DOWN 2
//#define LEFT 3
//#define RIGHT 4
//bool TakeScreenshot(BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot, HBITMAP &hBitmapOld, HDC &hdcScreen);
//
//
//bool CompareColour(RGBQUAD *pPixels, int height, int width, int x, int y)
//{
//	int p = (height-y-1)*width+x; // upside down
//	//int r = (int)pPixels[p].rgbRed;
//	//int g = (int)pPixels[p].rgbGreen;
//	//int b = (int)pPixels[p].rgbBlue;
//	//std::cout < < r << ", " << g << ", " << b  << std::endl;
//	//SetCursorPos(x, y);
//	//PINK
//	if((int)pPixels[p].rgbRed < 30 && (int)pPixels[p].rgbGreen < 30 && (int)pPixels[p].rgbBlue > 230)
//	{
//		//std::cout << r << ", " << g << ", " << b  << std::endl;
//		//std::cout << "Found color" << std::endl;
//		SetCursorPos(x, y);
//		int rep = 0;
//		return true;
//	}
//	//if(GetAsyncKeyState(VK_ESCAPE))
//	//{
//		//exit(0);
//	//}
//	return false;
//}
//
//*
// ----
//  ---
//   --
//    -
//*/
////check the bounds in all our scanning threads, reset any variables if we reach bounds
//void CheckBoundsVert(int startingX, int startingY, int &currentLoopX, int &currentLoopY, int &incBy, RECT rcWindow, bool &breakOut)
//{
//	//only increment if its within the window bounds
//	if(startingX+(currentLoopX*2) < rcWindow.right)currentLoopX++;
//	//cut the main bit of the window from the top
//	if(startingY-currentLoopY > rcWindow.top)currentLoopY++;
//
//	//if the conditions are met restart our LOOP!!
//	//Reached the end of the loop for X axis, now keep going until we reach the bottom of the window
//	if(startingX+(currentLoopX*2) >= rcWindow.right)
//	{
//		//std::cout << "out of bounds X" << " startingY-currentLoopY " << startingY-currentLoopY << " rcWindow.top " << rcWindow.top << std::endl;
//		//system("pause");
//		//startingY-currentLoopY is now below the bottom rectangle
//		//WE ADD 20 BECAUSE WE DONT WANT TO SCAN THE TOP BIT OF THE WINDOW WHERE CALL OF DUTY LOGO AND TEXT IS AT 
//		//IF YOUR GAME DOENS THAVE A OUTSIDE WINDOW YOU CAN TAKE OFF THE +20 :)
//		if(startingY-currentLoopY <= rcWindow.top+20)
//		{
//			//std::cout << "out of bounds Y" << std::endl;
//			//system("pause");
//			currentLoopX = 1;
//			currentLoopY = 1;
//			breakOut = true;
//		}
//	}
//	incBy+=2;
//}
//
//
//
//
//void ScanBMPVertical(ScanContents * scan)
//{
//	int currentLoopX = 1;
//	int currentLoopY = 1;
//	bool breakOut = false;
//	while(true)
//	{
//		if(scan->TypeOfSearch == UP)
//			scan->Y = scan->StartingY-currentLoopY;
//		else if(scan->TypeOfSearch == DOWN)
//			scan->Y = scan->StartingY+currentLoopY;
//		//start somewhere between the screen e.g. start at center -10 and go to center +10 and keep incrementing that value
//		//BECAUSE 9/10 times the width of a screen is greater than the height then we make the height 
//		//scan through twice as much at once
//		scan->X = scan->StartingX-(currentLoopX*2);
//		//make sure the line doesnt go and start reading outside of the window
//		//y > rcWindow.top &&
//		
//		for(scan->X; scan->X < scan->StartingX+(currentLoopX*2); scan->X++)
//		{
//			//SetCursorPos(scan->X, scan->Y);
//			//if color has been found we stop checking for colour comparison and leave the loop
//			//SetCursorPos(scan->X, scan->Y);
//			if(*scan->ColorFoundK)
//			{
//				scan->OutOfThread = true;
//				_endthread();
//			}
//			if(CompareColour(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, scan->X, scan->Y))
//			{
//				//std::cout << "Thread killed color found " << scan->ThreadNum << std::endl;
//				//WE FOUND OUR VALUE COLOUR KILL ALL THREADS
//				if(!*scan->ColorFoundK)*scan->ColorFoundK = true;
//				//std::cout << "thread killed" << std::endl;
//				scan->OutOfThread = true;
//				_endthread();
//				//std::cout << "still on?" << std::endl;
//			}
//		}
//
//		//check the bounds of our searches
//		CheckBoundsVert(scan->StartingX, scan->StartingY, currentLoopX, currentLoopY, scan->IncBy, scan->RcWindow, breakOut);
//		if(breakOut || *scan->ColorFoundK)
//		{
//			scan->OutOfThread = true;
//			//std::cout << "Thread killed after full scan " << scan->ThreadNum << std::endl;
//			_endthread();
//		}
//	}
//}
//
////check the bounds in all our scanning threads, reset any variables if we reach bounds
////CENTER TO LEFT
//void CheckBoundsHoriz(int startingX, int startingY, int &currentLoopX, int &currentLoopY, int &incBy, RECT rcWindow, int typeOfSearch,
//	bool &breakOut)
//{
//	//only increment if its within the window bounds
//	if(startingY+(currentLoopY*2) < rcWindow.bottom-30)currentLoopY++;
//
//	if(startingX-currentLoopX < rcWindow.right)currentLoopX++;
//
//	//if the conditions are met restart our LOOP!!
//	//Reached the end of the loop for X axis, now keep going until we reach the bottom of the window
//	//WE TAKEAWAY 30 BECAUSE WE DONT WANT TO SCAN THE TOP BIT OF THE WINDOW WHERE CALL OF DUTY LOGO AND TEXT IS AT 
//	//IF YOUR GAME DOENS THAVE A OUTSIDE WINDOW YOU CAN TAKE OFF THE -30 :)
//	if(startingY+(currentLoopY*2) >= rcWindow.bottom-30)
//	{
//		//std::cout << "out of bounds X" << " startingY-currentLoopY " << startingY-currentLoopY << " rcWindow.top " << rcWindow.top << std::endl;
//		//system("pause");
//		//startingY-currentLoopY is now below the bottom rectangle
//		if(startingX-currentLoopX <= rcWindow.left)
//		{
//			currentLoopX = 1;
//			currentLoopY = 1;
//			breakOut = true;
//		}
//	}
//	incBy+=2;
//}
//
//
//void ThrScanBMPHorizontal(ScanContents * scan)
//{
//	bool breakOut = false;
//	int currentLoopX = 1;
//	int currentLoopY = 1;
//	//scan until it reaches the limits/bounds of the game window
//	while(true)
//	{
//		if(scan->TypeOfSearch == LEFT)
//			scan->X = scan->StartingX-currentLoopX;
//		else if(scan->TypeOfSearch == RIGHT)
//			scan->X = scan->StartingX+currentLoopX;
//		scan->Y = scan->StartingY-(currentLoopY*2);
//		//make sure the line doesnt go and start reading outside of the window
//		//y > rcWindow.top &&
//		for(scan->Y; scan->Y < scan->StartingY+(currentLoopY*2); scan->Y++)
//		{
//			//SetCursorPos(scan->X, scan->Y);
//			if(*scan->ColorFoundK)
//			{
//				scan->OutOfThread = true;
//				_endthread();
//			}
//			if(CompareColour(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, scan->X, scan->Y))
//			{
//				//std::cout << "Thread killed color found " << scan->ThreadNum << std::endl;
//				//WE FOUND OUR VALUE COLOUR KILL ALL THREADS
//				if(!*scan->ColorFoundK)*scan->ColorFoundK = true;
//				scan->OutOfThread = true;
//				//std::cout << "thread killed" << std::endl;
//				_endthread();
//				//std::cout << "still on?" << std::endl;
//			}
//		}
//		//check the bounds of our searches 
//		CheckBoundsHoriz(scan->StartingX, scan->StartingY, currentLoopX, currentLoopY, scan->IncBy, scan->RcWindow, scan->TypeOfSearch, breakOut);
//		if(breakOut || *scan->ColorFoundK)
//		{
//			scan->OutOfThread = true;
//			//std::cout << "Thread killed after full scan " << scan->ThreadNum << std::endl;
//			_endthread();
//		}
//	}
//}
//
////OUR MAIN SCANNER LOOP
//void ScanBMPHorizontal(ScanContents * scan)
//{
//	bool breakOut = false;
//	int currentLoopX = 1;
//	int currentLoopY = 1;
//	//scan until it reaches the limits/bounds of the game window
//	while(true)
//	{
//		if(scan->TypeOfSearch == LEFT)
//			scan->X = scan->StartingX-currentLoopX;
//		else if(scan->TypeOfSearch == RIGHT)
//			scan->X = scan->StartingX+currentLoopX;
//
//		scan->Y = scan->StartingY-(currentLoopY*2);
//		//make sure the line doesnt go and start reading outside of the window
//		//y > rcWindow.top &&
//		for(scan->Y; scan->Y < scan->StartingY+(currentLoopY*2); scan->Y++)
//		{
//			//SetCursorPos(scan->X, scan->Y);
//			if(*scan->ColorFoundK)
//			{
//				scan->OutOfThread = true;
//				return;
//			}
//			if(CompareColour(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, scan->X, scan->Y))
//			{
//				//std::cout << "Thread killed color found " << scan->ThreadNum << std::endl;
//				//WE FOUND OUR VALUE back to main loop
//				if(!*scan->ColorFoundK)*scan->ColorFoundK = true;
//				scan->OutOfThread = true;
//				//std::cout << "thread killed" << std::endl;
//				return;
//				//std::cout << "still on?" << std::endl;
//			}
//		}
//		//check the bounds of our searches 
//		CheckBoundsHoriz(scan->StartingX, scan->StartingY, currentLoopX, currentLoopY, scan->IncBy, scan->RcWindow, scan->TypeOfSearch, breakOut);
//		if(breakOut || *scan->ColorFoundK)
//		{
//			scan->OutOfThread = true;
//			return;
//			//std::cout << "Thread killed after full scan " << scan->ThreadNum << std::endl;
//		}
//	}
//}
//
//
//int main()
//{
//	HWND appWnd = FindWindow(0, "rgb - Windows Photo Viewer"); //rgb - Windows Photo Viewer // Call of duty 4
//	
//	RECT rcWindow;
//	GetWindowRect(appWnd, &rcWindow);
//
//	BITMAP bm;
//	HBITMAP hbmap;
//	HBITMAP hBitmapOld;
//	BITMAPINFO bmi;
//	HDC hdcShot;
//	HDC hdcScreen;
//
//	int p;
//	bool loopBreak;
//	int pressLimiter = clock();
//	int i;
//	bool CurrentlyScanning = false;
//	RGBQUAD *pPixels;
//	bool scanStarted = false;
//    //Do things with bits here
//	int TimeTakenScreenAndScan;
//
//	int startingX;;
//	int startingY;
//
//	int currentLoopX;
//	int currentLoopY;
//	//incrementer is used to expand our spiral in both direction
//	int incBy;
//	int y;
//	int x;
//	while(true)
//	{
//		loopBreak = false;
//		//only allow pressing with a x ms difference
//		if(GetAsyncKeyState('X') && !CurrentlyScanning) //VK_RBUTTON
//		{
//			TimeTakenScreenAndScan = clock();
//			scanStarted = true;
//			CurrentlyScanning = true;
//			//get all contents of our screen and store them in bm
//			TakeScreenshot(bm, hbmap, bmi, hdcShot, hBitmapOld, hdcScreen);
//			//--TOOK ABOUT 40 SECONDS TO TAKE SCREENSHOT AND GET HERE--
//			std::cout << "Took screenshot in " << clock() - TimeTakenScreenAndScan << " milliseconds" << std::endl;
//
//			pPixels = new RGBQUAD[bm.bmWidth * bm.bmHeight]; 
//			if (!pPixels) return false;
// 
//			HDC hdc = GetDC(HWND_DESKTOP);
//			if (!GetDIBits(hdc, hbmap, 0, bm.bmHeight, pPixels, &bmi, DIB_RGB_COLORS))
//			{
//				ReleaseDC(GetDesktopWindow(), hdc);
//				delete [] pPixels;
//				return false;
//			}
//			ReleaseDC(HWND_DESKTOP, hdc);
//			//DEFINE our window centers
//			startingX = rcWindow.right-((rcWindow.right-rcWindow.left)/2);
//			startingY = rcWindow.bottom-((rcWindow.bottom-rcWindow.top)/2);
//			currentLoopX = 1;
//			currentLoopY = 1;
//			//incrementer is used to expand our spiral in both direction
//			incBy = 2;
//			y = startingY-currentLoopY;
//			x = startingX-currentLoopX;
//
//			//std::cout << bm.bmWidth << std::endl;
//			//once a colour has been found we reset all threads
//			bool foundColour = false;
//			//Create our 3 objects to send to threads
//			ScanContents scanContents1(x, y, incBy, startingX, startingY, bm, rcWindow, pPixels, DOWN, &foundColour, false, 0); 
//			ScanContents scanContents2(x, y, incBy, startingX, startingY, bm, rcWindow, pPixels, UP, &foundColour, false, 1);
//			ScanContents scanContents3(x, y, incBy, startingX, startingY, bm, rcWindow, pPixels, LEFT, &foundColour, false,  2);
//			ScanContents scanContentsMain(x, y, incBy, startingX, startingY, bm, rcWindow, pPixels, RIGHT, &foundColour, false);
//
//			//create our threads to scan 4 parts of the screenshot
//			_beginthread((void(*)(void*))ScanBMPVertical, 0, (void*)&scanContents1);
//			_beginthread((void(*)(void*))ScanBMPVertical, 0, (void*)&scanContents2);
//			_beginthread((void(*)(void*))ThrScanBMPHorizontal, 0, (void*)&scanContents3);
//			//check if the threads are running and if so allow our player to call the aimbot again
//			ScanBMPHorizontal(&scanContentsMain);
//			//system("pause");
//
//			//wait until ALL THREADS HAVE SCANNED or quit to move on
//			while(CurrentlyScanning)
//			{
//				CurrentlyScanning = !(scanContents1.OutOfThread && scanContents2.OutOfThread && scanContents3.OutOfThread && scanContentsMain.OutOfThread);
//				//if a color was found we kill all scans
//				//if(foundColour)CurrentlyScanning = false; 
//				//std::cout << /* foundColour << " " << scanContents1.OutOfThread << " " << scanContents2.OutOfThread <<*/ " " << scanContents3.OutOfThread << " " << scanContentsMain.OutOfThread << std::endl;
//			}
//			//CURRENTLY AT 66 MILLISECONDS PER SCAN(A PROBLEM)
//			std::cout << "out of scan, took " << clock() - TimeTakenScreenAndScan << " milliseconds" << std::endl;
//		}
//		//CHECK IF OUR THREADS are still running and i+f NOT then we allow player to scan aimbot again
//		
//		//system("pause");
//		//if we ended our scan we free up the memory for our next screenshot
//		if(!CurrentlyScanning && scanStarted)
//		{
//			//std::cout << "Scan " << " took " << clock() - scanTime << " ms to complete" << std::endl;
//			//free our memory again or head on to crash town
//			if(pPixels)free(pPixels);
//			SelectObject(hdcShot, hBitmapOld);
//			DeleteObject(hbmap);
//			DeleteDC(hdcShot);
//			DeleteDC(hdcScreen);
//			scanStarted = false;
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//
//void SetupBitmapInfo(BITMAPINFO &bmi, int bWidth, int bHeight, int bitsPerPixel)
//{
//    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
//    bmi.bmiHeader.biWidth = bWidth;
//    bmi.bmiHeader.biHeight = bHeight;
//    bmi.bmiHeader.biPlanes = 1;
//    bmi.bmiHeader.biBitCount = bitsPerPixel;
//    bmi.bmiHeader.biCompression = BI_RGB;
//    bmi.bmiHeader.biSizeImage = 0;
//}
//
//
//bool TakeScreenshot(BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot, HBITMAP &hBitmapOld, HDC &hdcScreen)
//{
//    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
//    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
//
//	hdcScreen = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
//    hdcShot = CreateCompatibleDC(hdcScreen);
//    hbmap = CreateCompatibleBitmap(hdcScreen, screenWidth, screenHeight);
//    hBitmapOld = (HBITMAP) SelectObject(hdcShot, hbmap);
//    BitBlt(hdcShot, 0, 0, screenWidth, screenHeight, hdcScreen, 0, 0, SRCCOPY);
// 
//    if (!GetObject(hbmap, sizeof(BITMAP), (LPSTR)&bm)) 
//		return false;
//    int bitsPerPixel = bm.bmBitsPixel;
//
//    if (bitsPerPixel != 32 || bm.bmPlanes != 1) 
//		return false;
// 
//	SetupBitmapInfo(bmi, bm.bmWidth, bm.bmHeight, bitsPerPixel);
//	return true;
//}