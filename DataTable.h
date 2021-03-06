#pragma once
#include "TextureManager.h"
#include "AirCraft.h"
#include "Projectile.h"
#include "Pickup.h"
#include "Particle.h"
#include "Animation2.h"
#include "Actor.h"
#include <map>

namespace GEX {
	struct Direction 
	{
		Direction(float a, float d):
			angle(a),
			distance(d)
		{}

		float angle;
		float distance;
	};

	struct AircraftData
	{
		int			hitpoints;
		float		speed;
		TextureID	texture;
		sf::IntRect textureRect;
		sf::Time	fireInterval;
		bool		hasRollAnimation;
	
		std::vector<Direction> directions;
	};

	struct ProjectileData
	{
		int			damage;
		float		speed;
		TextureID	texture;

		sf::IntRect textureRect;
	};

	struct PickupData
	{
		std::function<void(AirCraft&)>	action;
		TextureID						texture;
		sf::IntRect textureRect;
	};

	struct ParticleData {
		sf::Color	color;
		sf::Time	lifetime;
	};

	struct ActorData
	{
		int										hitpoints;
		int										damageDone;
		float									speed;
		TextureID								texture;
		std::map<Actor::State, Animation2>		animations;

		std::vector<Direction>					directions;
	};

	std::map<ActorType, ActorData>				initializeActorData();

	std::map<Pickup::Type, PickupData>			initializePickupData();
	std::map<Projectile::Type, ProjectileData>	initializeProjectileData();
	std::map<AircraftType, AircraftData>		initializeAircraftData();

	std::map<Particle::Type, ParticleData>		initializeParticleData();
}

