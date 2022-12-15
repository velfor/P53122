#include "settings.h"
#include "functions.h"
using namespace sf;


int main()
{
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//шарик
	CircleShape ball;
	initBall(ball, ballColor, ballStartPosition);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//СЧЕТ
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	//тексты для счетов
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов
		//шарик
		//движение шарика
		ball.move(ball_speedx, ball_speedy);
		//попал-вышел за левую 
		if (ball.getPosition().x <= 0)
		{
			//скорость по оси х сменилась на противоположную
			ball_speedx = -ball_speedx;
			//правый игрок забил гол
			rightPlayerScore++;
			rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
		}
		//или правую границу
		if (ball.getPosition().x >=(WINDOW_WIDTH - 2 * ballRadius))
		{
			//скорость по оси х сменилась на противоположную
			ball_speedx = -ball_speedx;
			//левый игрок забил гол
			leftPlayerScore++;
			leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
		{
			//скорость по оси y сменилась на противоположную
			ball_speedy = -ball_speedy;
		}

		//Проверка нажатий клавиш
		//если клавиша W нажата - лева ракетка вниз
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		//двигаем ракетку		
		leftBat.move(0, leftBatSpeedY);
		//и сразу обнуляем скорость
		leftBatSpeedY = 0;



		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 вывод на экран
		window.display();
	}
	return 0;
}