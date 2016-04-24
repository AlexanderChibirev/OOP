#pragma once
#include "IShape.h"
#include <vector>
#include <memory>
using namespace sf;
using namespace std;

class CShapesContainer
{
public:
	void AddShape(Vector2f const &pos);
	void  AddShape(const sf::Vector2f &dot1, const sf::Vector2f &dot2, const string &lineColor);
	void  AddShape(const sf::Vector2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);
	void  AddShape(const sf::Vector2f &dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	void  AddShape(const sf::Vector2f &point1, const sf::Vector2f &point2, const sf::Vector2f &point3, string const &lineColor, string const &fillColor);
	vector<shared_ptr<IShape>> GetShapes()const;
private:
	vector<shared_ptr<IShape>> m_shapes;
};

