#include "Dot.h"
#include "Screen.h"

namespace Snake {

void Dot::move() {
	switch(m_direction) {
	case UP:
		m_y -= m_speed;
		break;
	case DOWN:
		m_y += m_speed;
		break;
	case LEFT:
		m_x -= m_speed;
		break;
	case RIGHT:
		m_x += m_speed;
		break;
	case STOP:
		break;
	}
//	if( m_direction == UP ) {
//		m_y -= m_speed;
//	}
//	if (m_direction == DOWN ) {
//		m_y += m_speed;
//	}
//	if (m_direction == LEFT ) {
//		m_x -= m_speed;
//	}
//	if (m_direction == RIGHT ) {
//		m_x += m_speed;
//	}
}

bool Dot::processQuitCollisons() {

	if( m_x <= 0 || m_x >= Screen::SCREEN_WIDTH || m_y <= 0 || m_y >= Screen::SCREEN_HEIGHT) {
		return false;
	}

	return true;

}

bool Dot::processFruitCollisions(Dot &fruit) {

	bool headXCollision = (m_x >= (fruit.m_x - DOT_RADIUS)) && (m_x <= (fruit.m_x + DOT_RADIUS));
	bool headYCollision = (m_y >= (fruit.m_y - DOT_RADIUS)) && (m_y <= (fruit.m_y + DOT_RADIUS));

	bool fruitCollision = headXCollision && headYCollision;

	if(fruitCollision) {
		return false;
	}
	return true;

}

void Dot::extend() {

}

} /* namespace Snake */




