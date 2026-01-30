#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "component.h"

typedef struct
{
    Component base;

    float velocityX;
    float velocityY;

    float mass;

} Rigidbody;

void Rigidbody_Update(Component *self, float dt);
Rigidbody *Rigidbody_Create(float x, float y);
void Rigidbody_AddForce(Rigidbody *rb, float fx, float fy);

#endif