#ifndef __UI_TEXT__
#define __UI_TEXT__

#include "UI_element.h"
#include "SDL/include/SDL_pixels.h"

struct _TTF_Font;

class Text : public UI_element
{
public:

	Text()
	{}

	Text(char* text, int x, int y, _TTF_Font* font, SDL_Color color, j1Module* callback) : UI_element(x, y, element_type::TEXT, callback, nullptr),
		text(text),
		font(font),
		color(color)
	{
		createTexture();
	}

	~Text();

	void createTexture();
	void setOutlineColor(SDL_Color newColor);
	void BlitElement();
	void setOutlined(bool isOutlined);

public:

	p2SString text = nullptr;
	SDL_Color color;
	uint tex_width;
	uint tex_height;

private:

	_TTF_Font* font = nullptr;
	bool outlined = false;
	SDL_Texture* outline = nullptr;
	SDL_Color outline_color = { 0, 0, 0, 255 };
	iPoint outline_offset;
};

#endif // !__UI_TEXT__
