#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Skase");
    sf::CircleShape shape(5.f);
    shape.setFillColor(sf::Color::White);
    sf::RectangleShape p1;
    sf::RectangleShape p2;
    sf::Vector2f size(20.0f,70.0f);
    p1.setSize(size);
    p2.setSize(size);
    p1.setFillColor(sf::Color::Green);
    p2.setFillColor(sf::Color::Blue);
    sf::Vector2f pos1(30,300);
    p1.setPosition(pos1);
    sf::Vector2f pos2(1150,300);
    p2.setPosition(pos2);
    float vely = 10;
    float velx = 10;
    float velpx = 0.3;
    float velpy= 0.3;
    sf::Vector2f poss(600,300);
    shape.setPosition(poss);
    
    while (window.isOpen())
    {
	       
	    
	    sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
	poss.x += velpx;
	shape.setPosition(poss);
	
		if (shape.getGlobalBounds().intersects(p1.getGlobalBounds() ) ) 
		{
			poss.x += velpx;
			shape.setPosition(poss);
		}
    		
		if (shape.getGlobalBounds().intersects(p2.getGlobalBounds() ) ) 
		{
			poss.x -= velpx;
			shape.setPosition(poss);
		}

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	    {
		    p1.move(0,-15);
	    }	    
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    {
		p1.move(0,15);	
	    }

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	    {
		    p2.move(0.f,-15.f);
	    }
	    
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	    {	   
		    p2.move(0.f,15.f);
	    }
	
	//collision physics
	
	
	    if (p1.getPosition().y < 0)
	    {
		    p1.setPosition(30,0);
	    }

	    if (p1.getPosition().y > 637)
	    {
		    p1.setPosition(30,637);
	    }

	    if (p2.getPosition().y < 0)
	    {
		    p2.setPosition(1150,0);
	    }

	    if (p2.getPosition().y > 637)
	    {
		    p2.setPosition(1150,637);
	    }
	}

	

        window.clear();
        window.draw(shape);
	window.draw(p1);
	window.draw(p2);
        window.display();
    }

    return 0;
}

