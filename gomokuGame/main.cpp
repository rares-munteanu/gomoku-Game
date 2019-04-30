// Nume: Munteanu
// Prenume: Rares-Alexandru
// Grupa: 134

#include <QApplication>
#include<QObject>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include<QObject>
#include<QKeyEvent>
#include<QDebug>
#include<QMouseEvent>
#include<QList>
#include"Game.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	Game myGame;
	myGame.drawTable();
	myGame.populateTable();

	return app.exec();
}