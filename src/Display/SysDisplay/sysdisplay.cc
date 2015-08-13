#include <SDL2/SDL.h>
#include <iostream>
#include "sysdisplay.hh"

namespace Display{




SysDisplay::SysDisplay(uint32_t _width, uint32_t _height, float _frames_per_second) 	:	
	width { _width }, height { _height }, frames_per_sec { _frames_per_second }, win_max_size{ width*height },
	win{nullptr}


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


	if(win == nullptr)
	{
		std::cout 	<< "Error with SDL_CreateWindow\n"
					<< "Error Code: "
					<< SDL_GetError();			
	}
}






SysDisplay::~SysDisplay()
{

	std::cout << "Destroying SysDisplay\n";	
	SDL_DestroyWindow(win);

}

}