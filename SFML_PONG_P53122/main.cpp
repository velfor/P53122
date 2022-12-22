#include "settings.h"
#include "functions.h"
using namespace sf;


int main()
{
	srand(time(nullptr));
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;
	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//�����
	CircleShape ball;
	initBall(ball, BALL_COLOR, BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	//����
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	//������ ��� ������
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//2 ���������� ��������
		//�����
		//�������� ������
		ball.move(ball_speedx, ball_speedy);
		//�����-����� �� ����� 
		if (ball.getPosition().x <= 0)
		{
			//�������� �� ��� � ��������� �� ���������������
			ball_speedx = -ball_speedx;
			//������ ����� ����� ���
			rightPlayerScore++;
			rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
		}
		//��� ������ �������
		if (ball.getPosition().x >=(WINDOW_WIDTH - 2 * BALL_RADIUS))
		{
			//�������� �� ��� � ��������� �� ���������������
			ball_speedx = -ball_speedx;
			//����� ����� ����� ���
			leftPlayerScore++;
			leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * BALL_RADIUS))
		{
			//�������� �� ��� y ��������� �� ���������������
			ball_speedy = -ball_speedy;
		}
		//�������� ������� ������
		//���� ������� W ������ - ���� ������� ����
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		//������� �������		
		leftBat.move(0, leftBatSpeedY);
		//� ����� �������� ��������
		leftBatSpeedY = 0;
		//������ �������
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
			rightBatSpeedY = -batSpeed;
		if (Keyboard::isKeyPressed(Keyboard::Down)) 
			rightBatSpeedY = batSpeed;
		//������� �������		
		rightBat.move(0, rightBatSpeedY);
		//� ����� �������� ��������
		rightBatSpeedY = 0;

		//��������� ���� �� �������
		//��������� �����-�������� ������ ���������� ������ ���� ��������
		float ballX = ball.getPosition().x;
		float ballY = ball.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS, ballY };
		Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
		//�������� �� ����� �������
		if (pointInRect(leftBat, midLeft)) ball_speedx = -ball_speedx;
		if (pointInRect(leftBat,midBottom) || pointInRect(leftBat, midTop))
			ball_speedy = -ball_speedy;
		//�������� �� ������ �������
		if (pointInRect(rightBat, midRight)) ball_speedx = -ball_speedx;
		if (pointInRect(rightBat, midBottom) || 
			pointInRect(rightBat, midTop))
			ball_speedy = -ball_speedy;

		//3 ��������� ����
		//3.1 ������� ����
		window.clear();
		//3.2 ��������� �������� (� ������!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 ����� �� �����
		window.display();
	}
	return 0;
}