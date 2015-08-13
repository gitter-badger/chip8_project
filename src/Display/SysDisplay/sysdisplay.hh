#ifndef SYSDISPLAY_HH
#define SYSDISPLAY_HH




namespace Display {

class SysDisplay
{
public:
	SysDisplay(uint32_t _width, uint32_t _height, float _frames_per_second);
	virtual void ClearScreen() const = 0;
	virtual void UpdateWindow() const = 0;
	virtual ~SysDisplay();

protected:
	uint32_t width;
	uint32_t height;
	double frames_per_sec;
	size_t win_max_size;
	SDL_Window 		*win;

	




};

}



#endif