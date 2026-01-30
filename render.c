#include <SDL3/SDL.h>
#include "render.h"
#include "transform.h"
#include "color.h"

void SetRenderColor(SDL_Renderer *renderer, Color *color)
{
    SDL_SetRenderDrawColor(renderer, color->red, color->green, color->blue, color->alpha);
}

void RenderTransform(SDL_Renderer *renderer, Transform *transform)
{
    SDL_FRect rect = {transform->x, transform->y, transform->scaleX, transform->scaleY};
    SDL_RenderRect(renderer, &rect);
}