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

	win_render = SDL_CreateRenderer(win, -1, 0);
	win_texture = SDL_CreateTexture(win_render, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	
}



void SysDisplay::ClearScreen()
{
	
	SDL_RenderClear(win_render);
	uint32_t pixel[win_max_size];
	std::fill_n(pixel,win_max_size,~0);
	SDL_UpdateTexture(win_texture,nullptr,pixel,width*4);
	
}






void SysDisplay::UpdateWindow() const
{

	SDL_RenderCopy(win_render,win_texture,nullptr,nullptr);
	SDL_RenderPresent(win_render);
}


SysDisplay::~SysDisplay()
{

	std::cout << "Destroying SysDisplay\n";	
	SDL_DestroyRenderer(win_render);
	SDL_DestroyTexture(win_texture);
	SDL_DestroyWindow(win);

}



int main()
{
	SysDisplay disp(800,600,60);
	disp.ClearScreen();
	disp.UpdateWindow();
	SDL_Delay(1000*4);



}
