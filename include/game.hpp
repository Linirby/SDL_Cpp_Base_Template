#pragma once

#include <SDL2/SDL.h>

class Game
{
private:
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	bool			running;

	void	handle_events(SDL_Event event);
	void	update(float fixed_dt);
	void	render(float alpha);

public:
	Game();
	~Game();

	void	run();
};
