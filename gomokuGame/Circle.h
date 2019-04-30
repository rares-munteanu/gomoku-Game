// Nume: Munteanu
// Prenume: Rares-Alexandru
// Grupa: 134

#ifndef CIRCLE
#define CIRCLE


#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include<QObject>


class Circle :public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

protected:
	int i, j;
	bool isPressed = 0;
	int color = -1;
public:

	int get_i() { return i; }
	int get_j() { return j; }
	int is_Pressed() { return isPressed; }
	void set_indexes(int a, int b) { i = a; j = b; }
	void set_Pressed(bool a) { isPressed = a; }
	int get_color() { return color; }
	void set_color(int a) { color = a; }
	void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
	void check(int, int);
	void draw_circle(Circle*);
	void increaseCounter();
};

#endif //CIRCLE