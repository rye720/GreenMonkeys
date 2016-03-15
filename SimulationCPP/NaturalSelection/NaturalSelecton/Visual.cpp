#include "Visual.h"

/*COMMENTS:
*  Need this inorder to create a pointer to this class in the static version of windowprodecure.3
*  Not going to use pop in this at all, so setting pop equal to its self is safe in this instance.
*/
Visual::Visual():popMap(popMap){
	hWnd = NULL;
	hInstance = NULL;
	hDc = NULL;

}

/*COMMENTS:
*  The constructor that will be called from outside this class. Using an initializer list more for style and avoiding possible complicated code.
*  In earlier development this did not use an initializer list and the program quickly ran into problems setting popMap equal to incPopMap in the body of the function.
*  Not sure what caused this, but it was fixed with an initalizer list.
*/
Visual::Visual(std::map<std::string, std::tuple<std::vector<std::shared_ptr<Animal>>, int>> incPopMap) : popMap(std::move(incPopMap)){
	hWnd = NULL;
	hInstance = NULL;
	hDc = NULL;
	
	gridBoard.resize(gridHeight);		
	for (int i = 0; i < gridHeight; i++){	
		gridBoard[i].resize(gridWidth);
	}
}

/*COMMENTS:
* OLD, no need for this. Was used when the grid was a 2d array and needed to malloc the grid.
*/
Visual::~Visual(){
	//for (int i = 0; i < 500; i++)
	//	free(gridBoard[i]);
	//free(gridBoard);
}

/*COMMENTS:
*  Just basic window creation and registration with a basic msg handler loop. Nothing too fancy. 
*/
void Visual::visualSetup(){
	LPCSTR myClass = "Green Monkeys";
	LPCSTR myTitle = "Natural Selection Simulator";
	std::cout << std::get<0>(popMap.begin()->second).size();

	WNDCLASS wndclass = { CS_HREDRAW | CS_VREDRAW, (WNDPROC)StaticWndProc, 0, 0, 
		hInstance, LoadIcon(NULL,IDI_WINLOGO), LoadCursor(NULL, IDC_ARROW),
		(HBRUSH) GetStockObject(WHITE_BRUSH), myTitle, myClass};

	if (RegisterClass(&wndclass))
	{
		hWnd = CreateWindowEx(0, myClass, myTitle,
			WS_BORDER | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
			800, 600, NULL, NULL, hInstance, this);
		
		if (hWnd)
		{
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			UpdateWindow(hWnd);
			MSG msg; 
			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
		}
	}
}

/*COMMENTS:
*  This was a big pain to get working. Finally got it to work after a long time resraching.
*  So windows api only allows the main window procedure to be static. But since we are using an external data structure
*  this proved to be a problem. The way this problem was solved was by creating a pointer to the class and a pointer to the window.
*  The window pointer is then used to initalize the class pointer (class pointer still has access to the static window). With this we are able to call functions via the class pointer.
*  And since we are able to call our second window procedure, which is not static, and use our external data members. 
*  This whole process allows us to bypass the static window procedure. 
*  Again this was a big pain to get working.
*/
LRESULT CALLBACK Visual::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Visual* pParent;

	// Get pointer to window
	if (uMsg == WM_CREATE)
	{
		pParent = (Visual*)((LPCREATESTRUCT)lParam)->lpCreateParams;
		SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)pParent);
		//SetTimer(hWnd, 1, 3, NULL);
		SetTimer(hWnd, 2, 5000, NULL);
		SetTimer(hWnd, 3, 150, NULL);
		/*SetTimer(hWnd, 4, 10000, NULL);*/
	}
	else
	{
		pParent = (Visual*)GetWindowLongPtr(hWnd, GWL_USERDATA);
		if (!pParent) return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	pParent->hWnd = hWnd;
	return pParent->WndProc(uMsg, wParam, lParam);
}

/*COMMENTS:
*  Non-static version of the window procedure. 
*  May need to edit the timers a bit more. 
*  Also need to remove the first timer as it is not being used anymore.
*  Messing with OpenMP. Causing errors though, still looking into it.
*/
LRESULT Visual::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;


	switch (uMsg)
	{
	case WM_CREATE:
		//SetTimer(hWnd, 1, 20, NULL);
		//SetTimer(hWnd, 2, 2000, NULL);
		break;
	case WM_TIMER:
		switch (wParam){
		case 1:
			/*This will be used to update the window to give the illusion of realtime movement*/

			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			break;
		case 2:
			/*Possible timer to update animals position and such. Mostly for testing right now*/		
//#pragma omp parallel
			for (auto& map : popMap){
				animalPosUpdate(std::get<0>(map.second));
//#pragma omp barrier
			}
			break;
		case 3:
//#pragma omp parallel
			for (auto& map : popMap){
				animalIncUpdate(std::get<0>(map.second));
//#pragma omp barrier
			}	
			InvalidateRect(hWnd, NULL, TRUE);
			UpdateWindow(hWnd);
			break;
		/*case 4:
			GA g = GA();
			g.combination(pop, pop.size(), 0);
			g.ranking(pop);
			g.selection(pop);
			break;*/
		}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		/*Window here*/


		//code to plot points of animal locations called here
//#pragma omp parallel
		if (firstTime){
//			for (auto& map : popMap){
//				initialPopPlot(hdc, hWnd, std::get<0>(map.second));
////#pragma omp barrier
//			}

				initialPopPlot(hdc, hWnd, std::get<0>(popMap.find("wolf")->second));
		
				initialPopPlot(hdc, hWnd, std::get<0>(popMap.begin()->second));

		}
		else {

//#pragma omp parallel
//			for (auto& map : popMap){
//				paintAnimals(hdc, hWnd, std::get<0>(map.second), "RED");
////#pragma omp barrier
//			}

				paintAnimals(hdc, hWnd, std::get<0>(popMap.find("wolf")->second), "RED");

				paintAnimals(hdc, hWnd, std::get<0>(popMap.begin()->second), "BLACK");


			/***************************************************************************
			 * For ryan: How to Textout out the vector size + name of the animals.     *
			 * Old code before we had the map though. Still works just need to get the *
			 * vector from the map.                                                    *
			 ***************************************************************************/

			//Got it working now	-Ryan

			SetTextColor(hdc, RGB(0, 0, 0));
			TextOut(hdc, 10, 10, std::get<0>(popMap.find("wolf")->second)[0]->getName().c_str(), std::get<0>(popMap.find("wolf")->second)[0]->getName().length());
			TCHAR buffer[32];
			_itoa_s(std::get<0>(popMap.find("wolf")->second).size(), buffer, 10);
			if (std::get<0>(popMap.find("wolf")->second).size() < 10)
				TextOut(hdc, 40, 10, buffer, 1);
			else if (std::get<0>(popMap.find("wolf")->second).size() < 100)
				TextOut(hdc, 40, 10, buffer, 2);
			else if (std::get<0>(popMap.find("wolf")->second).size() < 1000)
				TextOut(hdc, 40, 10, buffer, 3);
			else
				TextOut(hdc, 40, 10, buffer, 4);

			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 70, 10, std::get<0>(popMap.begin()->second)[0]->getName().c_str(), std::get<0>(popMap.begin()->second)[0]->getName().length());
			_itoa_s(std::get<0>(popMap.begin()->second).size(), buffer, 10);
			if (std::get<0>(popMap.begin()->second).size() < 10)
				TextOut(hdc, 100, 10, buffer, 1);
			else if (std::get<0>(popMap.begin()->second).size() < 100)
				TextOut(hdc, 100, 10, buffer, 2);
			else if (std::get<0>(popMap.begin()->second).size() < 1000)
				TextOut(hdc, 100, 10, buffer, 3);
			else
				TextOut(hdc, 100, 10, buffer, 4);
		}



		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return (UINT)0;
}

/*COMMENTS:
*  This will need to change or be re-written once we add in prey/a grid 2d array. 
*  Currently it is giving the animal a random direction to "roam" in.
*/
void Visual::animalPosUpdate(std::vector<std::shared_ptr<Animal>> pop){
	GAUtils gau = GAUtils();

//#pragma omp parallel
	for (const auto& animal : pop){
		int randx = gau.randIntGen(600);
		int randy = gau.randIntGen(500);
			
		if (gau.randIntGen(10) >= 5)
			animal->setPosXOffset(randx);
		else
			animal->setPosXOffset(randx*-1);

		if (gau.randIntGen(10) >= 5)
			animal->setPosYOffset(randy);
		else
			animal->setPosYOffset(randy*-1);
	}
	
}

/*COMMENTS:
*  Generates the first position and starting place for each animal.
*  It spawns each animal in a box formation. Each with their own unique position. This is done so there is no outliers when spawning (i.e. they're all grouped up).
*  Note, when we add in prey/predator we may need to space them out a bit more to avoid a feeding frenzy and possible genocide.
*  Probably should create their position in the GA instead of here, but this works for now.
*  Re-did how they are given their position to match a 2d array style for loop. Made sure to add in the remainder this time.
*  Also testing OpenMP. Still need to profile it with and without OpenMP to see if it is making any difference.
*/
void Visual::initialPopPlot(HDC hdc, HWND hWnd, std::vector<std::shared_ptr<Animal>>& pop) {
	GAUtils gau = GAUtils();
	startX = gau.randIntGen(100, 300);
	startY = gau.randIntGen(100, 300);
	int x = 1;
	int y = pop.size();
	int z = 0;

#pragma omp parallel
	for (int i = 500; i < 500; i++){
		for (int j = 700; j < 700; j++){
			gridBoard[j][i] = NULL;
		}
	}

	int popFillSize = floor(sqrt(y));
	int remainder = (y-(popFillSize*popFillSize));

#pragma omp parallel shared(popFillSize, remainder)
	for (int i = 0, animalCount = 0; i < popFillSize; i++){
		for (int j = 0; j < popFillSize; j++){
			pop[animalCount]->setXPosition(startX + i);
			pop[animalCount]->setYPosition(startY + j);
			gridBoard[startY + j][startX + i] = pop[animalCount];			
			animalCount++;
		}
	}

#pragma omp parallel
	for (int i = 0, j = pop.size(); i < remainder; i++){
		pop[j - i-1]->setXPosition(startX + i);
		pop[j - i-1]->setYPosition(startY + popFillSize);
		gridBoard[startY + popFillSize][startX + i] = pop[j-i-1];
	}
	firstTime = false;
	animalPosUpdate(pop);
}

/*COMMENTS:
*  Basic painting and collision detection done in one function.
*  Did this in one function becuase the collision is fairly small and fits right in with the painting.
*  Need to find a better way to do the COLORREF. Looking/thinking of a way to do this.
*/
void Visual::paintAnimals(HDC hdc, HWND hWnd, std::vector<std::shared_ptr<Animal>> pop, std::string color){

	if (color == "BLACK")
		SetTextColor(hdc, RGB(0,0,0));
	else
		SetTextColor(hdc, RGB(255,0,0));

//#pragma omp parallel
	for (const auto& animal : pop){
		int xpos, ypos;
		xpos = animal->getXPos();
		ypos = animal->getYPos();
		

		if ((xpos > 51) && (ypos > 51) && (ypos < 501) && (xpos < 701))
			TextOut(hdc,xpos, ypos, ".", 1);
		else if ((xpos < 51) && (ypos > 51))
			TextOut(hdc, 50, ypos, ".", 1);
		else if ((ypos < 51) && (xpos > 51))
			TextOut(hdc, xpos, 50, ".", 1);
		else if ((ypos < 51) && (xpos < 51))
			TextOut(hdc, 51, 51, ".", 1);
		else if ((ypos > 501) && (xpos < 701))
			TextOut(hdc, xpos, 500, ".", 1);
		else if ((ypos < 501) && (xpos > 701))
			TextOut(hdc, 700, ypos, ".", 1);
		else
			TextOut(hdc, 699, 499, ".", 1);
	}
}

/*COMMENTS:
*  Possible future work: Instead of each animal moving 1 pixel at a time have them move at their own speed.
*  Would need to test this though. Could lead to a "skipping" effect on the screen.
*/
void Visual::animalIncUpdate(std::vector<std::shared_ptr<Animal>> pop){

	//#pragma omp parallel
	for (const auto& animal : pop){
		int xpos = animal->getXPos();
		int ypos = animal->getYPos();
		if (animal->getPosXOffset() > 0 && xpos < gridHeight-1 && xpos > 0){
			animal->setPosXOffset(animal->getPosXOffset() - 1);
			gridBoard[xpos][ypos] = NULL;
			animal->setXPosition(animal->getXPos() + 1);
			gridBoard[xpos+1][ypos] = animal;
		}
		else if (animal->getPosXOffset() < 0 && xpos < gridHeight-1 && xpos > 0){
			animal->setPosXOffset(animal->getPosXOffset() + 1);
			gridBoard[xpos][ypos] = NULL;
			animal->setXPosition(animal->getXPos() - 1);
			gridBoard[xpos-1][ypos] = animal;
		}

		if (animal->getPosYOffset() > 0 && ypos < gridWidth-1 && ypos > 0){
			animal->setPosYOffset(animal->getPosYOffset() - 1);
			gridBoard[xpos][ypos] = NULL;
			animal->setYPosition(animal->getYPos ()+ 1);
			gridBoard[xpos][ypos+1] = animal;
		}
		else if (animal->getPosYOffset() < 0 && ypos < gridWidth-1 && ypos > 0){
			animal->setPosYOffset(animal->getPosYOffset() + 1);
			gridBoard[xpos][ypos] = NULL;
			animal->setYPosition(animal->getYPos() - 1);
			gridBoard[xpos][ypos-1] = animal;
		}
		//#pragma omp barrier
	}
	localizePopulation(pop);
}


/*
Comments: Set up to get good search grid bounds, defending against indexing out of the gridMap
*/


void Visual::localizePopulation(std::vector<std::shared_ptr<Animal>> pop) {

	int xStart;
	int yStart;
	int xStop;
	int yStop;

	for (const auto& animal : pop) {
		
		int searchSize = (int)std::floorf(6 * animal->getFitness());

		if ( (animal->getXPos() - searchSize) > -1 ) {
			xStart = animal->getXPos() - searchSize;
		}
		else {
			xStart = 0;
		}
		
		if ((animal->getYPos() - searchSize) > -1) {
			yStart = animal->getYPos() - searchSize;
		}
		else {
			yStart = 0;
		}

		if ( (animal->getXPos() + searchSize) < (gridWidth - 1) ) {
			xStop = animal->getXPos() + searchSize;
		}
		else {
			xStop = gridWidth - 1;
		}

		if ((animal->getYPos() + searchSize) < (gridHeight - 1)) {
			yStop = animal->getYPos() + searchSize;
		}
		else {
			yStop = gridHeight - 1;
		}

		for (int j = xStart; j < xStop; j++ ) {
			for (int i = yStart; i < yStop; i++) {

				if (!gridBoard[i][j] == NULL) {
					
					//do search and eat animals

				}
			}
		}

	}

}