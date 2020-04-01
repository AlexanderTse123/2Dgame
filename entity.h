#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "gf2d_sprite.h""

typedef struct Entity_S
{
	Uint8			_inuse;						/**<This is for checking if the entity in the memory is active.>*/
	Sprite			*sprite;					/**<Pointer to a sprite that is being used by the entity.>*/
	float			frame;						/**<Current frame for the sprite.>*/

	int				digable;					/**<A flag to check if the object can be dug out by workers.>*/
	int				role;						/**<A sort of multi flag which checks what kinds of things this entity can do. Reserve this for creatures.>*/
	int				faction;					/**<A flag to tell whose side the entity is on. Will also determine what color the entity is associated with.>*/
	int				style;						/**<A flag to tell what kind of combat style this unit has. Will determine speed and how the entity reacts to enemies.>*/ 

	Vector2D		position;					/**<Check where the entity is in a 2D environment.>*/
	Vector2D		velocity;

	Vector2D		drawOffset;
	float			radius;						/**<how wide this entity is>*/
	Vector2D		size;

	void(*think)(struct Entity_S *self);		/**<This gets called when the entity is drawn.>*/
	void(*touch)(struct Entity_S *self, struct Entity_S *other);	/**<called when an entity touches another entity>*/
}Entity;

/**
* @brief get a pointer to a new entity
* @return null on out of memory error, a pointer to a blank entity otherwise
*/
Entity *entity_new();

/**
* @brief initialize entity resource manager
* @param maxEnts upper bound of maximum concurrent entities to be supported
* @note must be called before creating a new entity
*/
void entity_manager_init(Uint32 maxEnts);

/**
* @brief free a previously allocated entity
* @param self a pointer to the entity to free
*/
void entity_free(Entity *self);

/**
* @brief update every active entity
*/
void entity_update_all();

/**
* @brief draw every active entity
*/
void entity_draw_all();

/**
* @brief when an entity changes whose faction it is fighting for use this
* @param self a pointer to the entity to change faction
*/
void change_faction(Entity *self);

#endif