#include "Driver.h"


int main() {
	GA main = GA();
	GAUtils g = GAUtils();
	std::vector<Animal> population;
	population = main.generatePop("bear", 5, 5, 1);

	/*Loop i < x; x is the number of times you itterate through it*/
	for (int i = 0; i < 35; i++){
		main.combination(population, population.size(), i + 2);
		main.ranking(population);
		main.selection(population); 
	}
	
	/*g.popOut(population);*/
	g.popOut(population, 5);
	std::cout << "Population size: " + std::to_string(population.size());
	
	/*system("pause");*/
	return 0;

	/*
	 WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProcedure,
                            0, 0, GetModuleHandle(0), LoadIcon(0,IDI_APPLICATION),
                            LoadCursor(0,IDC_ARROW), HBRUSH(COLOR_WINDOW+1),
                            0, "Green Monkeys", LoadIcon(0,IDI_APPLICATION) } ;
    if( RegisterClassEx(&wndclass) )
    {
        HWND window = CreateWindowEx( 0, myclass, "title",
                   WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                   CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0 ) ;
        if(window)
        {
            ShowWindow( window, SW_SHOWDEFAULT ) ;
            MSG msg ;
            while( GetMessage( &msg, 0, 0, 0 ) ) DispatchMessage(&msg) ;
        }
    }
	*/
}