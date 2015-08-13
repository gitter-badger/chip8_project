#include <SDL2/SDL.h>
#include <chip8display.hh>



int main()
{
	Display::Chip8Display chip8_display(800,600,60);


	chip8_display.ClearScreen();
	chip8_display.UpdateWindow();

	SDL_Delay(1000*3);

}