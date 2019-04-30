// Nume: Munteanu
// Prenume: Rares-Alexandru
// Grupa: 134

#ifndef GAME
#define GAME

#include<QGraphicsScene>
#include<QGraphicsView>
#include<QApplication>
#include<QPushButton>
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QGraphicsEllipseItem>
#include<QObject>
#include<QDebug>
#include<QVector>
#include<QGraphicsTextItem>
#include<Circle.h>
#include <QSignalMapper>


class Game :public QObject
{
	Q_OBJECT

private:


	QPushButton* swapmb;
	QPushButton* swapm2b;
	QPushButton* switchswap2;
	QPushButton* swapchpl;

	int player_font_counter = -1;
	QGraphicsScene* scene;
	QGraphicsView* view;
	QVector<QVector<Circle*>>myMatrix;
	QGraphicsTextItem* player;
	int game_proceed = 0;
	int circleCounter = 0;
	int color_counter = -1;
	bool winned = 0;
	int mode = 0;
	int alt = 0;

public:


	Game();
	~Game();
	void drawTable();
	void populateTable();
	void switchPlayersFont();
	void switchColors();
	void switchPlayers()
	{
		switchColors();
		switchPlayersFont();
	}
	void showWinner();

public slots:


	void draw();
	void increaseCounter() { circleCounter++; }
	void resetGame();
	void checkMatrix(int, int);
	void startGame();
	void pas();
	void swapf();
	void swap2f();
	void swapmbf();
	void swapm2bf();
	void switchbf();
	void swapchplbf();
	void checkPlayer(Circle* a)
	{
		if (color_counter == 2)
		{
			a->setBrush(QBrush(Qt::white));
			a->set_color(0);
			a->setOpacity(1.0);
			a->set_Pressed(1);
		}
		else
			if (color_counter == 1)
			{
				a->setBrush(QBrush(Qt::black));
				a->set_color(1);
				a->setOpacity(1.0);
				a->set_Pressed(1);
			}
		switchPlayers();
	}
	void checkPlayerSwap(Circle* a)
	{

		if (color_counter == 2)
		{
			a->setBrush(QBrush(Qt::white));
			a->set_color(0);
			a->setOpacity(1.0);
			a->set_Pressed(1);
		}
		else
			if (color_counter == 1)
			{
				a->setBrush(QBrush(Qt::black));
				a->set_color(1);
				a->setOpacity(1.0);
				a->set_Pressed(1);
			}

		switch (mode)
		{
		case 2:mode--; break;
		case 1:switchColors(); mode--; break;
		case 0:switchPlayersFont(); mode--; break;
		case -1:switchPlayers(); mode--; break;
		case -2:switchPlayers(); break;
		default:
			break;
		}
	}
	void checkPlayerSwap2(Circle* a)
	{

		if (color_counter == 2)
		{
			a->setBrush(QBrush(Qt::white));
			a->set_color(0);
			a->setOpacity(1.0);
			a->set_Pressed(1);
		}
		else
			if (color_counter == 1)
			{
				a->setBrush(QBrush(Qt::black));
				a->set_color(1);
				a->setOpacity(1.0);
				a->set_Pressed(1);
			}

		switch (mode)
		{
		case 2:mode--; break;
		case 1:switchColors(); mode--; break;
		case 0:switchPlayersFont(); mode--; break;
		case -1:switchPlayers(); mode--; break;
		case -2:switchPlayers(); break;
		default:
			break;
		}

		switch (alt)
		{
		case 1:switchColors(); alt--; break;
		case 0:switchPlayers(); alt--; mode = -1; break;
		default:
			break;
		}
	}
};


#endif // GAME