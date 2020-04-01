#include "simple_logger.h"
#include "collisions.h"

#include "bug.h"

#define ES_DEAD 1

void bug_think(Entity *self)
{
	int mx, my;
	Uint32 buttons;
	if (!self)
	{
		return;
	}
}

Entity *bug_new(Vector2D position, Vector2D velocity)
{
	Entity *self;
	self = entity_new();
	if (!self)
	{
		return NULL;
	}
	self->sprite = gf2d_sprite_load_all(
		"images/space_bug_top.png",
		128,
		128,
		16);
	self->radius = 24;
	self->size.x = 32;
	self->size.y = 32;
	self->think = bug_think;
	return self;
}