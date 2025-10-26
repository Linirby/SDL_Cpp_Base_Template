#include <SDL2/SDL.h>
#include <iostream>
#include "game.hpp"
#include "game_timer.hpp"

void Game::handle_events(SDL_Event event)
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			running = false;
	}
}

void Game::update(float fixed_dt)
{
	(void)fixed_dt;
	// Update Here & remove `(void)fixed_dt`
}

void Game::render(float alpha)
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	(void)alpha;
	// Draw Here & remove `(void)alpha`

	SDL_RenderPresent(renderer);
}

void Game::run()
{
	SDL_Event	event;
	GameTimer	game_timer(60);
	float		fixed_dt;
	float		alpha;

	fixed_dt = game_timer.get_fixed_delta();
	while (running)
	{
		game_timer.update();

		handle_events(event);

		while (game_timer.can_fixed_update())
		{
			update(fixed_dt);
			game_timer.consume_fixed_update();
		}

		alpha = game_timer.get_alpha();
		render(alpha);

		game_timer.frame_limiter(120);
	}
}

Game::Game()
{
	running = false;

	window = SDL_CreateWindow(
		"Template SDL Project - by Lili",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
		0
	);
	if (!window)
	{
		std::cerr << "Can't Create Window: " << SDL_GetError() << "\n";
		return ;
	}
	
	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED
	);
	if (!renderer)
	{
		std::cerr << "Can't Create Renderer: " << SDL_GetError() << "\n";
		SDL_DestroyWindow(window);
		return ;
	}

	// Load additionnal Game Content Here

	running = true;
}

Game::~Game()
{
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
}
