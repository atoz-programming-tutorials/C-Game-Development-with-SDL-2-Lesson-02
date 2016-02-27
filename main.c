// Lesson 2
// Draw points, lines and rectangles

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include "utils.h"

static const int width = 800;
static const int height = 600;

// Draw points with random colors and positions
void draw_random_points(int nr_points, bool randomizeColor, SDL_Renderer *renderer)
{
    for(int i = 0; i < nr_points; ++i)
    {
        if(randomizeColor)
        {
            SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
        }
        SDL_RenderDrawPoint(renderer, randomNumber(0, width), randomNumber(0, height));
    }
}

// Draw random lines with random color
void draw_random_lines(int nr_lines, bool randomizeColor, SDL_Renderer *renderer)
{
    for(int i = 0; i < nr_lines; ++i)
    {
        if(randomizeColor)
        {
            SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
        }
        SDL_RenderDrawLine(renderer, randomNumber(0, width), randomNumber(0, height), randomNumber(0, width), randomNumber(0, height));
    }
}


int main(int argc, char **argv)
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
    SDL_Event event;
    while(running)
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // Clear screen with black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow color
        //draw_random_points(500, true, renderer);
        //draw_random_lines(500, true, renderer);

        // Draw a rectangle
        SDL_Rect rect = {50, 50, 200, 200};
        SDL_RenderFillRect(renderer, &rect);

        // Draw a wired rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_Rect rect2 = {250, 300, 200, 250};
        SDL_RenderDrawRect(renderer, &rect2);


        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
