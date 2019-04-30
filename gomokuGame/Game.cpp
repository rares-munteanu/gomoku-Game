// Nume: Munteanu
// Prenume: Rares-Alexandru
// Grupa: 134

#include "Game.h"

Game::Game()
{
	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
	QPalette pal;

	QImage image("light.jpg");

	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
	scene->addItem(item);

	int y = 60;
	QPushButton* newGame = new QPushButton(view);
	newGame->setText("Standard Version");
	pal = newGame->palette();
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	newGame->setAutoFillBackground(true);
	newGame->setPalette(pal);
	newGame->update();
	newGame->setGeometry(10, y, 100, 50);
	newGame->updateGeometry();
	QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(startGame()));
	newGame->show();
	y += 50;

	y += 50;

	QPushButton* swapb = new QPushButton(view);
	swapb->setText("SWAP MODE");
	swapb->setGeometry(10, y, 100, 50);
	swapb->updateGeometry();
	pal = swapb->palette();
	swapb->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	swapb->setPalette(pal);
	swapb->update();
	QObject::connect(swapb, SIGNAL(clicked()), this, SLOT(swapf()));
	swapb->show();
	y += 50;

	swapmb = new QPushButton(view);
	swapmb->setText("SWAP");
	swapmb->setGeometry(20, y, 80, 50);
	swapmb->updateGeometry();
	pal = swapmb->palette();
	swapmb->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	swapmb->setPalette(pal);
	swapmb->update();
	QObject::connect(swapmb, SIGNAL(clicked()), this, SLOT(swapmbf()));
	swapmb->show();

	y += 50; y += 50;

	QPushButton* swap2b = new QPushButton(view);
	swap2b->setText("SWAP2 MODE");
	swap2b->setGeometry(10, y, 100, 50);
	swap2b->updateGeometry();
	pal = swap2b->palette();
	swap2b->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	swap2b->setPalette(pal);
	swap2b->update();
	QObject::connect(swap2b, SIGNAL(clicked()), this, SLOT(swap2f()));
	swap2b->show();
	y += 50;

	swapm2b = new QPushButton(view);
	swapm2b->setText("SWAP2");
	swapm2b->setGeometry(60, y, 50, 50);
	swapm2b->updateGeometry();
	pal = swapm2b->palette();
	swapm2b->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	swapm2b->setPalette(pal);
	swapm2b->update();
	QObject::connect(swapm2b, SIGNAL(clicked()), this, SLOT(swapm2bf()));
	swapm2b->show();

	swapchpl = new QPushButton(view);
	swapchpl->setText("SWAP\nColor");
	swapchpl->setGeometry(60, y, 50, 50);
	swapchpl->updateGeometry();
	pal = swapchpl->palette();
	swapchpl->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	swapchpl->setPalette(pal);
	swapchpl->update();
	QObject::connect(swapchpl, SIGNAL(clicked()), this, SLOT(swapchplbf()));
	swapchpl->hide();

	switchswap2 = new QPushButton(view);
	switchswap2->setText("Put +2\n stones");
	switchswap2->setGeometry(10, y, 50, 50);
	switchswap2->updateGeometry();
	pal = switchswap2->palette();
	switchswap2->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	switchswap2->setPalette(pal);
	switchswap2->update();
	QObject::connect(switchswap2, SIGNAL(clicked()), this, SLOT(switchbf()));
	switchswap2->show();

	y += 50; y += 50;

	QPushButton* pasb = new QPushButton(view);
	pasb->setText("PAS");
	pasb->setGeometry(10, y, 100, 50);
	pasb->updateGeometry();
	pal = pasb->palette();
	pasb->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	pasb->setPalette(pal);
	pasb->update();
	QObject::connect(pasb, SIGNAL(clicked()), this, SLOT(pas()));
	pasb->show();

	y += 50;
	QPushButton* drawb = new QPushButton(view);
	drawb->setText("DRAW");
	drawb->setGeometry(10, y, 100, 50);
	drawb->updateGeometry();
	pal = drawb->palette();
	drawb->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	drawb->setPalette(pal);
	drawb->update();
	QObject::connect(drawb, SIGNAL(clicked()), this, SLOT(draw()));
	drawb->show();

	y += 50;
	y += 50;

	QPushButton* reset = new QPushButton(view);
	reset->setText("Reset Game");
	reset->setGeometry(10, y, 100, 50);
	reset->updateGeometry();
	pal = reset->palette();
	reset->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	reset->setPalette(pal);
	reset->update();
	QObject::connect(reset, SIGNAL(clicked()), this, SLOT(resetGame()));
	reset->show();

	y += 50;

	QPushButton* exitButton = new QPushButton(view);
	exitButton->setText("Exit");
	exitButton->setGeometry(10, y, 100, 50);
	exitButton->updateGeometry();
	pal = exitButton->palette();
	exitButton->setAutoFillBackground(true);
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	exitButton->setPalette(pal);
	exitButton->update();
	QObject::connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	exitButton->show();


	view->setFixedSize(1110, 1019);
	view->setWindowTitle("Gomoku");
	view->setBackgroundBrush(QBrush(Qt::lightGray));
	view->show();

}


void Game::drawTable()
{


	player = new QGraphicsTextItem;
	player->setPlainText("Player 1->Black");
	player->hide();
	player->setPos(480, 20);
	player->setTextWidth(450);
	player->setDefaultTextColor(QColor(Qt::black));
	QFont serifFont("Times", 20, QFont::Bold);
	player->setFont(serifFont);
	scene->addItem(player);

	QGraphicsRectItem* item;

	int x = 200, y = 80, alternator = 0;
	for (int i = 1; i <= 460; i++)
	{

		item = new QGraphicsRectItem(x, y, 40, 40);
		if (alternator)
			item->setBrush(QBrush(Qt::lightGray));
		else
			item->setBrush(QBrush(Qt::white));
		scene->addItem(item);

		if (i % 20 == 0)
		{
			x = 200;
			y += 40;
			alternator = 1 - alternator;
		}
		else
		{
			x += 40;
		}
		alternator = 1 - alternator;
	}


}

void::Game::populateTable()
{
	QVector<Circle*> myVector;

	Circle* circle;
	int x = 160, y = 40;
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			circle = new Circle();
			circle->setRect(x + 25, y + 25, 30, 30);
			scene->addItem(circle);
			myVector.push_back(circle);
			myVector[j]->setOpacity(0.01);
			myVector[j]->set_indexes(i, j);
			myVector[j]->set_color(-1);
			myVector[j]->set_Pressed(0);
			myVector[j]->hide();


			QObject::connect(circle, SIGNAL(check(int, int)), this, SLOT(checkMatrix(int, int)));
			QObject::connect(circle, SIGNAL(increaseCounter()), this, SLOT(increaseCounter()));
			x += 40;
		}
		y += 40;
		x = 160;
		myMatrix.push_back(myVector);
		myVector.clear();
	}
	view->setAlignment(Qt::AlignCenter);
}

void Game::resetGame()
{
	game_proceed = 0;
	winned = 0;
	color_counter = 1;
	player_font_counter = 1;
	player->setPlainText("Player 1->black");
	player->hide();
	circleCounter = 0;
	alt = 0;
	for (int i = 0; i < myMatrix.size(); i++)
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			myMatrix[i][j]->setOpacity(0.01);
			myMatrix[i][j]->setBrush(QBrush(Qt::NoBrush));
			myMatrix[i][j]->set_Pressed(false);
			myMatrix[i][j]->set_color(-1);
			myMatrix[i][j]->hide();
			QObject::disconnect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayer(Circle*)));
			QObject::disconnect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayerSwap(Circle*)));
			QObject::disconnect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayerSwap2(Circle*)));
		}

	QObject::connect(swapmb, SIGNAL(clicked()), this, SLOT(swapmbf()));
	QObject::connect(swapm2b, SIGNAL(clicked()), this, SLOT(swapm2bf()));
	QObject::connect(swapchpl, SIGNAL(clicked()), this, SLOT(swapchplbf()));
	QObject::connect(switchswap2, SIGNAL(clicked()), this, SLOT(switchbf()));
}

void Game::checkMatrix(int a, int b)
{

	int color = myMatrix[a][b]->get_color();
	int lines = myMatrix.size();
	int col = myMatrix[a].size();
	int nr = 0;
	if (color == -1)
	{
		//qDebug() << "Color -1!!";
		return;
	}

	/// Checking column down

	for (int i = a; i <= a + 5 && i < lines; i++)
		if (myMatrix[i][b]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner column down";
		return;
	}
	nr--;

	/// Checking column up
	for (int i = a; i >= a - 5 && i >= 0; i--)
		if (myMatrix[i][b]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner column up";
		return;
	}


	/// Checking line to right

	nr = 0;
	for (int j = b; j <= b + 5 && j < col; j++)
		if (myMatrix[a][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner line to right";
		return;
	}

	///Checking line to left
	nr--;
	for (int j = b; j >= b - 5 && j >= 0; j--)
		if (myMatrix[a][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner line to left";
		return;
	}

	/// Checking diagonal to right down
	nr = 0;
	for (int i = a, j = b; i <= a + 5 && j <= b + 5 && i < lines && j < col; i++, j++)
		if (myMatrix[i][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner diagonal to right down";
		return;
	}
	///Checking diagonal to up left 
	nr--;
	for (int i = a, j = b; i >= a - 5 && j >= b - 5 && i >= 0 && j >= 0; i--, j--)
		if (myMatrix[i][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner diagonal to up left ";
		return;
	}

	///Checking diagonal to right up
	nr = 0;
	for (int i = a, j = b; i >= a - 5 && i >= 0 && j <= b + 5 && j < col; i--, j++)
		if (myMatrix[i][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner diagonal to right up ";
		return;
	}

	///Checking diagonal to left down
	nr--;
	for (int i = a, j = b; i <= a + 5 && i < lines && j >= b - 5 && j >= 0; i++, j--)
		if (myMatrix[i][j]->get_color() == color)
			nr++;
		else
			break;
	if (nr == 5)
	{
		showWinner();
		//qDebug() << "Winner diagonal to left down ";
		return;
	}
	if (circleCounter == 504)
		draw();
}

void Game::startGame()
{
	game_proceed = 1;
	player->show();
	color_counter = player_font_counter = 1;
	for (int i = 0; i < myMatrix.size(); i++)
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			myMatrix[i][j]->show();
			QObject::connect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayer(Circle*)));
		}
}

void Game::switchPlayersFont()
{
	QString string;
	if (color_counter == 1)
		string = "black";
	else
		string = "white";
	if (player_font_counter == 1)
	{
		player->setPlainText("Player 2 ->" + string);
		player_font_counter = 3 - player_font_counter;
	}
	else if (player_font_counter == 2)
	{
		player->setPlainText("Player 1->" + string);
		player_font_counter = 3 - player_font_counter;
	}

}

void Game::switchColors()
{
	color_counter = 3 - color_counter;
	QString string;
	if (color_counter == 1)
		string = "black";
	else
		string = "white";
	if (player_font_counter == 1)
	{
		player->setPlainText("Player 1 ->" + string);
	}
	else if (player_font_counter == 2)
	{
		player->setPlainText("Player 2->" + string);
	}
}

void Game::showWinner()
{
	switchPlayers();
	winned = 1;
	if (player_font_counter == 1)
		player->setPlainText("Player 1 winned");
	else
		if (player_font_counter == 2)
			player->setPlainText("Player 2 winned");
	for (int i = 0; i < myMatrix.size(); i++)
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			myMatrix[i][j]->set_Pressed(true);
		}
}

void Game::pas()
{
	if (!winned)
	{
		switchPlayers();
	}

}

void Game::swapf()
{
	player->show();
	game_proceed = 1;
	alt = 0;
	color_counter = player_font_counter = 1;
	mode = 2;
	for (int i = 0; i < myMatrix.size(); i++)
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			myMatrix[i][j]->show();
			QObject::connect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayerSwap(Circle*)));
		}
}

void  Game::swapmbf()
{
	if (mode == -1)
	{
		switchPlayersFont();
		//swapmb->hide();
		QObject::disconnect(swapmb, SIGNAL(clicked()), this, SLOT(swapmbf()));
	}
}

void Game::swap2f()
{
	player->show();
	game_proceed = 1;
	alt = 0;
	color_counter = player_font_counter = 1;
	mode = 2;
	alt = -1;
	for (int i = 0; i < myMatrix.size(); i++)
		for (int j = 0; j < myMatrix[i].size(); j++)
		{
			myMatrix[i][j]->show();
			QObject::connect(myMatrix[i][j], SIGNAL(draw_circle(Circle*)), this, SLOT(checkPlayerSwap2(Circle*)));
		}
}

void Game::swapm2bf()
{
	if (mode == -1)
	{
		switchPlayersFont();
		QObject::disconnect(swapm2b, SIGNAL(clicked()), this, SLOT(swapm2bf()));
	}
}

void Game::switchbf()
{
	if (mode == -1)
	{
		swapm2b->hide();
		swapchpl->show();
		switchColors();
		alt = 1;
		mode = -3;
		color_counter = 1;
		QObject::disconnect(switchswap2, SIGNAL(clicked()), this, SLOT(switchbf()));
	}
}

void Game::swapchplbf()
{
	switchColors();
	QObject::disconnect(swapchpl, SIGNAL(clicked()), this, SLOT(swapchplbf()));
}

void Game::draw()
{
	if (game_proceed == 1 && winned == 0)
	{

		player->setPlainText("DRAW");
		for (int i = 0; i < myMatrix.size(); i++)
			for (int j = 0; j < myMatrix[i].size(); j++)
			{
				myMatrix[i][j]->set_Pressed(true);
			}
	}
}

Game::~Game()
{
	delete[]view;
	delete[]scene;
}
