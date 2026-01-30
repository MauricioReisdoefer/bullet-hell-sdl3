#include <stdio.h>
#include <stdlib.h>
#include "rigidbody.h"
#include "transform.h"
#include "gameobject.h"

Rigidbody *Rigidbody_Create(void)
{
    Rigidbody *rb = malloc(sizeof(Rigidbody));

    rb->base.type = COMPONENT_RIGIDBODY;
    rb->base.update = Rigidbody_Update;
    rb->base.owner = NULL;

    rb->velocityX = 0.0f;
    rb->velocityY = 0.0f;

    return rb;
}

void Rigidbody_AddForce(Rigidbody *rb, float fx, float fy)
{
    rb->velocityX += fx;
    rb->velocityY += fy;
}

void Rigidbody_Update(Component *self, float dt)
{
    Rigidbody *rb = (Rigidbody *)self;

    if (!self->owner)
        return;

    Transform *transform = (Transform *)GameObject_GetComponent(
        self->owner,
        COMPONENT_TRANSFORM);

    if (!transform)
        return;

    transform->x += rb->velocityX * dt;
    transform->y += rb->velocityY * dt;

    rb->velocityX -= rb->mass;
    rb->velocityY -= rb->mass;
}