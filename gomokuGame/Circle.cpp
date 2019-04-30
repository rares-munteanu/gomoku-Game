// Nume: Munteanu
// Prenume: Rares-Alexandru
// Grupa: 134

#include "Circle.h"

void Circle::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && isPressed == 0)
	{
		emit draw_circle(this);
		emit increaseCounter();
		emit check(i, j);
	}
}
