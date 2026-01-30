#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>
#include "color.h"
#include "transform.h"

void SetRenderColor(SDL_Renderer *renderer, const Color *color);
void RenderTransform(SDL_Renderer *renderer, Transform *transform);

#endif