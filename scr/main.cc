#include <SDL2/SDL.h>
#include <iostream>
#include "sysdisplay.hh"



class Chip8Display : public SysDisplay
{
public:
	Chip8Display(uint32_t _width, uint32_t _height, double _frames_per_sec);
	void ClearScreen()
	{

	}
	void UpdateWindow()
	{

	}
	

	~Chip8Display()
	{	
		std::cout << "Destructing Chip8Display\n";
	}


private:
	SDL_Renderer 	*chip8_renderer;
	SDL_Texture 	*chip8_texture;

	

};

constexpr uint32_t chip8_W {64};

constexpr uint32_t chip8_H {32};

constexpr int chip8_max_pixels {64*32};

Chip8Display::Chip8Display(uint32_t _width, uint32_t _height, double _frames_per_sec) : 
	
	SysDisplay(_width,_height,_frames_per_sec),chip8_renderer{ nullptr }, chip8_texture{ nullptr }
{
	std::cout << "Constructor Chip8Display\n";

	chip8_renderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	
	if(chip8_renderer == nullptr)
	{
		std::cout 	<< "Error SDL_CreateRenderer \n"
					<< "Error Code: " 
					<< SDL_GetError();

		return;
	}


	chip8_texture = SDL_CreateTexture(chip8_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
										chip8_W, chip8_H );


	if(chip8_renderer == nullptr)
	{
		std::cout 	<< "Error SDL_CreateTexture \n"
					<< "Error Code: " 
					<< SDL_GetError();

		return;
	}


	



}


int main()
{
	Chip8Display cp(800,600,60);
}