#pragma once
#include "Entity.h"
#include <SFML/Graphics/Sprite.hpp>
#include "TextureManager.h"
#include "Command.h"
#include "Animation2.h"

namespace GEX {

	class TextureManager;
	class TextNode;

	enum class ActorType
			{
				Hero2,
				Zombie1,
				Zombie2,
				Zombie3,
				Zombie4,
				Zombie5
			};

	class Actor : public Entity
	{
	public:
				enum class State {
				Attack,
				Dead,
				Idle,
				Rise,
				Walk,
				Run,
				Jump,
				count
			};
			
	public:
		enum class Direction {
			Left,
			Right,
			Up,
			Down
		};

	public:
		Actor(ActorType type, const TextureManager& textures);
		~Actor() = default;

		unsigned int		getCategory() const override;
		sf::FloatRect		getBoundingBox() const override;
		float				getMaxSpeed() const;
		virtual void		accelerate(sf::Vector2f velocity) override;

		void				attack();
		void				setState(State state);
		int					attackPoints() const;

	private:
		void				updateStates();
		void				updateCurrent(sf::Time dt, CommandQueue& commands) override;
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
		void				updateMovementPattern(sf::Time dt);
		void				updateTexts();
		bool				isMarkedForRemoval() const override;

	private:
		ActorType								type_;
		State									state_;
		mutable sf::Sprite						sprite_;
		mutable std::map<State, Animation2>		animations_;
		Direction								direction_;
		TextNode*								healthDisplay_;

		float									travelDistance_;
		std::size_t								directionIndex_;

		bool									attack_;
	};

}