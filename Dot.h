#ifndef DOT_H_
#define DOT_H_

namespace Snake {

class Dot {
private:
	double m_x;
	double m_y;
	int m_speed;
	enum eDirection {STOP, UP, DOWN, LEFT, RIGHT};
	eDirection m_direction;

public:
	const static int DOT_RADIUS = 10; // N.B. Gives architecture error if not initialised here
	const static int DOT_SPEED = 5;
public:
	Dot(double x, double y): m_x(x), m_y(y), m_speed(0), m_direction(STOP) {};
	Dot(double x, double y, int speed): m_x(x), m_y(y), m_speed(speed), m_direction(STOP) {};
	Dot(double x, double y, int speed, eDirection direction): m_x(x), m_y(y), m_speed(speed), m_direction(direction) {};
	double getX() { return m_x; };
	double getY() { return m_y; };
	eDirection getDirection() { return m_direction; };
	void changeDirectionUp() { m_direction = UP; };
	void changeDirectionDown() { m_direction = DOWN; };
	void changeDirectionLeft() { m_direction = LEFT; };
	void changeDirectionRight() { m_direction = RIGHT; };
	void pause() { m_direction = STOP; };
	void move();
	bool processQuitCollisons();
	bool processFruitCollisions(Dot &fruit);
	void extend();

};

} /* namespace Snake */

#endif /* DOT_H_ */
