
class SysDisplay
{
public:
	SysDisplay(uint32_t _width, uint32_t _height, double _frames_per_second);
	void ClearScreen();
	virtual void UpdateWindow() const;
	virtual ~SysDisplay();

protected:
	uint32_t width;
	uint32_t height;
	double frames_per_sec;
	size_t win_max_size;
private:
	SDL_Window *win;
	SDL_Renderer *win_render;
	SDL_Texture *win_texture;

	




};


