#ifndef CHIP8DISPLAY_HH
#define CHIP8DISPLAY_HH


#include <memory>
#include <sysdisplay.hh>

namespace Display
{


class Chip8Display final : public SysDisplay
{
public:
	Chip8Display(uint32_t _width, uint32_t _height, float _frames_per_sec);

	void ClearScreen() const;
	
	void UpdateWindow() const;
	

	~Chip8Display();


private:
	SDL_Renderer 					*chip8_renderer;
	SDL_Texture 					*chip8_texture;
	std::unique_ptr<uint32_t[]> 	pixels;

	

};






}

#endif