typedef struct Component Component;

typedef void (*ComponentUpdateFunction)(Component *self, float dt);

typedef enum
{
    COMPONENT_TRANSFORM,
    COMPONENT_RIGIDBODY,
    COMPONENT_RENDER,
} ComponentType;

struct Component
{
    ComponentType type;
    ComponentUpdateFunction update;
};