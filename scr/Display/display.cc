#include <SDL2/SDL.h>
#include <iostream>
#include "display.hh"


SysDisplay::SysDisplay(uint32_t _width, uint32_t _height, double _frames_per_second) 	:	
	width { _width }, height { _height }, frames_per_sec { _frames_per_second }, win_max_size{ width*height } 
{
	std::cout << "Constructing SysDisplay\n";


	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout 	<< "Error Initializing SDL_INIT_VIDEO\n"
					<< "Error Code: "
					<< SDL_GetError();
		return;			
	}
	win = SDL_CreateWindow("SysDisplay",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
				width,height,SDL_WINDOW_RESIZABLE);
	
	win_surface = SDL_GetWindowSurface(win);
	
}



void SysDisplay::ClearScreen() const
{
	std::fill_n(static_cast<uint32_t*>(win_surface->pixels),win_max_size,~0);
}






void SysDisplay::UpdateWindow() const
{

	SDL_UpdateWindowSurface(win);
}


SysDisplay::~SysDisplay()
{

	std::cout << "Destroying SysDisplay\n";	
	SDL_FreeSurface(win_surface);
	SDL_DestroyWindow(win);

}



int main()
{
	SysDisplay disp(800,600,60);
	
	disp.UpdateWindow();
	SDL_Delay(1000*4);



}
