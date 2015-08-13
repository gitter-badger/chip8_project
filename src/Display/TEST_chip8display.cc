





/* 
*
* 		TEST unit, this file should have a only a main function, 
* 		or a test chip8display class implementation and the main function.
*/





#include <SDL2/SDL.h>
#include <iostream>
#include "chip8display.hh"

namespace Display {








constexpr int chip8_W {64};

constexpr int chip8_H {32};

constexpr int chip8_max_pixels {64*32};


constexpr int static_multiplie(int x, int y)
{
	return x*y;
}




Chip8Display::Chip8Display(uint32_t _width, uint32_t _height, float _frames_per_sec) : 
	SysDisplay(_width,_height,_frames_per_sec),chip8_renderer{ nullptr }, chip8_texture{ nullptr }, 
	pixels(std::make_unique<uint32_t[]>(chip8_max_pixels))

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




void Chip8Display::ClearScreen() const
{

	/* std::fill_n
	*
	*	fill the pixels with ~0 value
	*
	*
	**/
	std::fill_n(pixels.get(),chip8_max_pixels,~0);

}


void Chip8Display::UpdateWindow() const
{
	
	/* 				SDL_UpdateTexture
	*
	* Use this function to update the given texture rectangle with new pixel data.
	*
	*
	*
	*	int SDL_UpdateTexture(SDL_Texture*    texture,
    *                  		const SDL_Rect* rect,
    *                  		const void*     pixels,
    *                  		int             pitch)
    *
	* 		Parameters info:
	*
	*		texture 	the texture to update
	*		rect 		an SDL_Rect structure representing the area to update, or NULL to update the entire texture
	*		pixels 		the raw pixel data
	*		pitch 		the number of bytes in a row of pixel data, including padding between lines
	*
	*
    *
	**/
	SDL_UpdateTexture(chip8_texture,nullptr,pixels.get(),static_multiplie(chip8_W,4));






	



	/* 				SDL_RenderCopy
	*
	* Use this function to copy a portion of the texture to the current rendering target.
	* 
	* 	int SDL_RenderCopy(SDL_Renderer*   renderer,
    *              SDL_Texture*    texture,
    *              const SDL_Rect* srcrect,
    *              const SDL_Rect* dstrect)
	*
	*		Parameters info:
	*
    *		renderer 	the rendering context
	*		texture 	the source texture; see Remarks for details
	*		srcrect		the source SDL_Rect structure or NULL for the entire texture
	*		dstrect		the destination SDL_Rect structure or NULL for the entire rendering target; the texture will be stretched to fill the given rectangle
	*
	*
	**/
	SDL_RenderCopy(chip8_renderer,chip8_texture,nullptr,nullptr);















	/* 			SDL_RenderPresent
	*
	*	Use this function to update the screen with any rendering performed since the previous call.
	*	
	*	void SDL_RenderPresent(SDL_Renderer* renderer)
	*
	*	Parameters info:
	*
	*	renderer 	the rendering context
	*
	**/
	SDL_RenderPresent(chip8_renderer);










	SDL_Delay(1000/frames_per_sec);


}
















Chip8Display::~Chip8Display()
{
		
		
	std::cout << "Destructing Chip8Display\n";
	SDL_DestroyTexture(chip8_texture);
	SDL_DestroyRenderer(chip8_renderer);



}
















}



int main()
{
	
	Display::Chip8Display chip8_display(800,600,60);


	chip8_display.ClearScreen();

	/* .... */


	chip8_display.UpdateWindow();

	SDL_Delay(1000*3);
}