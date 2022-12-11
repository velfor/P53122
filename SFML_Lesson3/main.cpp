#include "settings.h"
using namespace sf;
int main()
{
    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FPS);

    //�������� ������� ��������
    //�������
    RectangleShape leftBat, rightBat;
    leftBat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGHT));
    leftBat.setPosition(BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGHT) / 2 );
    leftBat.setFillColor(LEFT_BAT_COLOR);

    rightBat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGHT));
    rightBat.setPosition(WINDOW_WIDTH - BAT_WIDTH - BAT_OFFSET, 
        (WINDOW_HEIGHT - BAT_HEIGHT) / 2);
    rightBat.setFillColor(RIGHT_BAT_COLOR);

    //���
    CircleShape ball{BALL_RADIUS};
    ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
        (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2);
    ball.setFillColor(BALL_COLOR);
    float ball_speedx = 2.f;
    float ball_speedy = 3.f;

    //����
    int leftPlayerScore = 0;
    int rightPlayerScore = 0;

    Font font;
    font.loadFromFile("DS-DIGIB.ttf");

    Text leftScoreText(std::to_string(leftPlayerScore), font, 64);
    Text rightScoreText(std::to_string(leftPlayerScore), font, 64);
    leftScoreText.setPosition(200,10);
    rightScoreText.setPosition(600, 10);

   while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
        }
        
        //���������� �������� ����
        ball.move(ball_speedx, ball_speedy);
        if (ball.getPosition().x <= 0)
        {
            ball_speedx = -ball_speedx;
            rightPlayerScore += 1;
            rightScoreText.setString(std::to_string(rightPlayerScore));
        }
        if (ball.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
        {
            ball_speedx = -ball_speedx;
            leftPlayerScore += 1;
            leftScoreText.setString(std::to_string(leftPlayerScore));
        }
        if (ball.getPosition().y <= 0 || 
            ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
        {
            ball_speedy = -ball_speedy;
        }
        // ��������� �������� � ����
        window.clear();
        window.draw(leftBat);
        window.draw(rightBat);
        window.draw(ball);
        window.draw(rightScoreText);
        window.draw(leftScoreText);
        window.display();
    }
    return 0;
}