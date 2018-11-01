#pragma once
#include "SceneNode.h"
#include <SFML/Graphics/Sprite.hpp>

namespace GEX {
	class SpriteNode : public SceneNode
	{
	public:
		explicit		SpriteNode(const sf::Texture& texture);
						SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
		
	private:
		virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		sf::Sprite	sprite_;
	};

}