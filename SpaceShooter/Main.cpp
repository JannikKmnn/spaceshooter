//Purpose: Just a SpaceShooter Game for fun
//Author: Jannik Kalkmann
//Date: 04/2020

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>

#include "SpaceShip.h"
#include "Shot.h"
#include "Stone.h"
#include "Hit.h"
#include "Player.h"

using namespace sf;

const float Window_Height = 700.0f;
String name;
bool startgame = false;
bool pause = false;

//Speed in pixels per "while(window.isOpen())"-Run in main()
float spaceship_speed = 0.05f;
const float ship_vel_change = 500.0f;
const float shot_speed = 0.2f;
float stone_speed = 0.015f;
const float stone_vel_change = 500.0f;

float stone_density_change = 10.0f;

bool shotfired = false;
unsigned int shotsCount = 0;

bool stonepresent = false;
unsigned int stonesCount = 0;

unsigned int Score = 0;
unsigned int Lifes = 5;

float Max_Shots_per_Sek = 0.4f;
float Max_Stones_per_sek = 1.8f;

bool freeshot = false;
bool freestone = false;
bool freename = true;

void StartWindow(Font font, RenderWindow& window, Sprite sprite) {

	Text TitleBar;
	TitleBar.setFont(font);
	TitleBar.setString("Space Shooter");
	TitleBar.setFillColor(Color::Cyan);
	TitleBar.setCharacterSize(Window_Height / 11.5f);
	FloatRect titleRect = TitleBar.getLocalBounds();
	TitleBar.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
	TitleBar.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 4.0f));

	Text EnterName;
	EnterName.setFont(font);
	EnterName.setString("Enter Your Name: ");
	EnterName.setFillColor(Color::White);
	EnterName.setCharacterSize(Window_Height / 25.0f);
	EnterName.setStyle(Text::Bold);
	FloatRect enterRect = EnterName.getLocalBounds();
	EnterName.setOrigin(enterRect.left + enterRect.width / 2.0f, enterRect.top + enterRect.height / 2.0f);
	EnterName.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 2.0f));

	Text Name;
	Name.setFont(font);
	Name.setFillColor(Color::White);
	Name.setCharacterSize(Window_Height / 25.0f);
	Name.setStyle(Text::Bold);

	RectangleShape Button;
	Button.setFillColor(Color::Transparent);
	Button.setOutlineThickness(1.0f);
	Button.setOutlineColor(Color::Cyan);
	Button.setSize(Vector2f(Window_Height / 3.0f, Window_Height / 25.0f));
	Button.setOrigin(Button.getSize().x / 2.0f, Button.getSize().y / 2.0f);
	Button.setPosition(Window_Height / 2.0f, Window_Height / 1.35f);

	Text Play;
	Play.setFont(font);
	Play.setString("Play!");
	Play.setFillColor(Color::Cyan);
	Play.setCharacterSize(Button.getSize().y - 2*Button.getOutlineThickness());
	FloatRect playRect = Play.getLocalBounds();
	Play.setOrigin(playRect.left + playRect.width / 2.0f, playRect.top + playRect.height / 2.0f);
	Play.setPosition(Button.getPosition());

	float deltaTime = 0.0f;
	float text_time = 0.0f;
	Clock clock;

	while (window.isOpen() && startgame == false) {

		deltaTime = clock.restart().asSeconds();

		FloatRect nameRect = Name.getLocalBounds();
		Name.setOrigin(nameRect.left + nameRect.width / 2.0f, nameRect.top + nameRect.height / 2.0f);
		Name.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 2.0f) + EnterName.getCharacterSize());

		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window.close();
				break;
			}
		}

		float mouseX = float(Mouse::getPosition(window).x);
		float mouseY = float(Mouse::getPosition(window).y);

		if (Mouse::isButtonPressed(Mouse::Left) && abs(mouseX - Button.getPosition().x) < Button.getSize().x / 2.0f && abs(mouseY - Button.getPosition().y) < Button.getSize().y / 2.0f ) {
			startgame = true;
			break;
		}
		
		text_time += deltaTime;
		if (text_time >= 0.47f) {
			text_time -= 0.47f;
			freename = true;
		}

		if (freename) {
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				name += "A";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::B)) {
				name += "B";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::C)) {
				name += "C";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				name += "D";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				name += "E";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::F)) {
				name += "F";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::G)) {
				name += "G";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::H)) {
				name += "H";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::I)) {
				name += "I";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::J)) {
				name += "J";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::K)) {
				name += "K";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::L)) {
				name += "L";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::M)) {
				name += "M";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::N)) {
				name += "N";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::O)) {
				name += "O";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::P)) {
				name += "P";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				name += "Q";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				name += "R";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				name += "S";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::T)) {
				name += "T";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::U)) {
				name += "U";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::V)) {
				name += "V";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				name += "W";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::X)) {
				name += "X";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Y)) {
				name += "Y";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)) {
				name += "1";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)) {
				name += "2";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)) {
				name += "3";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)) {
				name += "4";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)) {
				name += "5";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num6) || Keyboard::isKeyPressed(Keyboard::Numpad6)) {
				name += "6";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num7) || Keyboard::isKeyPressed(Keyboard::Numpad7)) {
				name += "7";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num8) || Keyboard::isKeyPressed(Keyboard::Numpad8)) {
				name += "8";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num9) || Keyboard::isKeyPressed(Keyboard::Numpad9)) {
				name += "9";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Num0) || Keyboard::isKeyPressed(Keyboard::Numpad0)) {
				name += "0";
				freename = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
				name.erase(name.getSize() - 1);
				freename = false;
			}
		}

		Name.setString(name);

		window.draw(sprite);
		window.draw(TitleBar);
		window.draw(EnterName);
		window.draw(Name);
		window.draw(Button);
		window.draw(Play);
		window.display();
		
	}
}

void PauseWindow(Sprite sprite, RenderWindow& window) {

	Font PauseFont;
	PauseFont.loadFromFile("Square.ttf");

	Font font;
	font.loadFromFile("Coalition.ttf");

	Text PauseSign;
	PauseSign.setFont(PauseFont);
	PauseSign.setString("ii");
	PauseSign.setFillColor(Color::White);
	PauseSign.setCharacterSize(Window_Height / 10.0f);
	PauseSign.setStyle(Text::Bold);
	FloatRect pauseRect = PauseSign.getLocalBounds();
	PauseSign.setOrigin(pauseRect.left + pauseRect.width / 2.0f, pauseRect.top + pauseRect.height / 2.0f);
	PauseSign.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 2.0f));

	Text Continue;
	Continue.setFont(font);
	Continue.setString("Press Shift to Continue");
	Continue.setFillColor(Color::White);
	Continue.setCharacterSize(Window_Height / 20.0f);
	Continue.setStyle(Text::Bold);
	FloatRect conRect = Continue.getLocalBounds();
	Continue.setOrigin(conRect.left + conRect.width / 2.0f, conRect.top + conRect.height / 2.0f);
	Continue.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 2.0f) + 140.0f);

	while (window.isOpen()) {
		
		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window.close();
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::RShift) || Keyboard::isKeyPressed(Keyboard::LShift)) {
			pause = false;
			break;
		}
		else {
			window.draw(sprite);
			window.draw(PauseSign);
			window.draw(Continue);
			window.display();
		}
	}
}

void GameOverWindow(Sprite sprite, RenderWindow& window, Font font, unsigned int score) {

	Text GameOver;
	GameOver.setString("Game Over!");
	GameOver.setFont(font);
	GameOver.setCharacterSize(Window_Height / 13.0f);
	GameOver.setFillColor(Color::Cyan);
	GameOver.setStyle(Text::Bold);
	FloatRect textRect = GameOver.getLocalBounds();
	GameOver.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	GameOver.setPosition(float(Window_Height) / 2.0f, (float(Window_Height) / 2.0f) - 70.0f);

	Text ScoreShow;
	ScoreShow.setString("Hope it was fun! \n Your Score Was " + std::to_string(score));
	ScoreShow.setFont(font);
	ScoreShow.setCharacterSize(Window_Height / 30.0f);
	ScoreShow.setFillColor(Color::Cyan);
	ScoreShow.setStyle(Text::Bold);
	FloatRect SCRect = ScoreShow.getLocalBounds();
	ScoreShow.setOrigin(SCRect.left + SCRect.width / 2.0f, SCRect.top + SCRect.height / 2.0f);
	ScoreShow.setPosition(GameOver.getPosition().x, GameOver.getPosition().y + GameOver.getCharacterSize());

	RectangleShape Button1;
	Button1.setFillColor(Color::Transparent);
	Button1.setOutlineThickness(1.0f);
	Button1.setOutlineColor(Color::Cyan);
	Button1.setSize(Vector2f(Window_Height / 2.5f, Window_Height / 25.0f));
	Button1.setOrigin(Button1.getSize().x / 2.0f, Button1.getSize().y / 2.0f);
	Button1.setPosition(Window_Height / 2.0f, Window_Height / 1.3f);

	Text PlayAgain;
	PlayAgain.setFont(font);
	PlayAgain.setString("Play Again!");
	PlayAgain.setFillColor(Color::Cyan);
	PlayAgain.setCharacterSize(Button1.getSize().y - 2 * Button1.getOutlineThickness());
	FloatRect againRect = PlayAgain.getLocalBounds();
	PlayAgain.setOrigin(againRect.left + againRect.width / 2.0f, againRect.top + againRect.height / 2.0f);
	PlayAgain.setPosition(Button1.getPosition());

	RectangleShape Button2;
	Button2.setFillColor(Color::Transparent);
	Button2.setOutlineThickness(1.0f);
	Button2.setOutlineColor(Color::Cyan);
	Button2.setSize(Vector2f(Window_Height / 2.5f, Window_Height / 25.0f));
	Button2.setOrigin(Button2.getSize().x / 2.0f, Button2.getSize().y / 2.0f);
	Button2.setPosition(Window_Height / 2.0f, Window_Height / 1.2f);

	Text Exit;
	Exit.setFont(font);
	Exit.setString("Exit");
	Exit.setFillColor(Color::Cyan);
	Exit.setCharacterSize(Button2.getSize().y - 2 * Button2.getOutlineThickness());
	FloatRect exitRect = Exit.getLocalBounds();
	Exit.setOrigin(exitRect.left + exitRect.width / 2.0f, exitRect.top + exitRect.height / 2.0f);
	Exit.setPosition(Button2.getPosition());

	while (window.isOpen()) {

		window.draw(sprite);

		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window.close();
				break;
			}
		}

		float mouseX = float(Mouse::getPosition(window).x);
		float mouseY = float(Mouse::getPosition(window).y);

		if (Mouse::isButtonPressed(Mouse::Left) && abs(mouseX - Button1.getPosition().x) < Button1.getSize().x / 2.0f && abs(mouseY - Button1.getPosition().y) < Button1.getSize().y / 2.0f) {
			Lifes = 5;
			Score = 0;
			spaceship_speed = 0.05f;
			stone_speed = 0.015f;
			Max_Shots_per_Sek = 0.4f;
			Max_Stones_per_sek = 1.8f;
			break;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && abs(mouseX - Button2.getPosition().x) < Button2.getSize().x / 2.0f && abs(mouseY - Button2.getPosition().y) < Button2.getSize().y / 2.0f) {
			window.close();
			break;
		}

		window.draw(GameOver);
		window.draw(ScoreShow);
		window.draw(Button1);
		window.draw(PlayAgain);
		window.draw(Button2);
		window.draw(Exit);
		window.display();
	}
	
}

int main() {

	RenderWindow window(VideoMode(Window_Height, Window_Height), "Space Shooter Game", Style::Close);

	Font font;
	font.loadFromFile("Coalition.ttf");

	SoundBuffer buffershot;
	buffershot.loadFromFile("LaserShot.wav");
	Sound ShotSound;
	ShotSound.setBuffer(buffershot);
	ShotSound.setPlayingOffset(seconds(0.8f));

	Text ScoreText;
	ScoreText.setFont(font);
	ScoreText.setCharacterSize(Window_Height / 40.0f);
	ScoreText.setFillColor(Color::Green);
	ScoreText.setPosition(2.0f, float(Window_Height) - float(ScoreText.getCharacterSize()) - 2.0f);

	Text LifeText;
	LifeText.setFont(font);
	LifeText.setCharacterSize(Window_Height / 40.0f);
	LifeText.setFillColor(Color::Red);
	LifeText.setPosition(float(Window_Height) - 95.0f, float(Window_Height) - float(LifeText.getCharacterSize()) - 2.0f);

	Texture Background;
	Background.loadFromFile("SpaceBackground.png");
	Background.setSmooth(true);

	Sprite sprite;
	sprite.setTexture(Background);
	sprite.setOrigin(Background.getSize().x / 2.0f, Background.getSize().y / 2.0f);
	sprite.setPosition(Window_Height / 2.0f, Window_Height / 2.0f);
	
	float deltaTime = 0.0f;
	float vel_time = 0.0f;
	float stone_time = 0.0f;
	Clock clock;

	Texture SpaceShipTexture;
	SpaceShipTexture.loadFromFile("SpaceShip.png");
	SpaceShipTexture.setSmooth(true);

	SpaceShip spaceship(&SpaceShipTexture, Window_Height);
	Hit hit;

	Texture ShotTexture;
	ShotTexture.loadFromFile("Shot.png");
	ShotTexture.setSmooth(true);

	Texture StoneTexture;
	StoneTexture.loadFromFile("GreyStone.png");
	StoneTexture.setSmooth(true);

	std::vector <Shot> Shots;
	std::vector <Stone> Stones;

	startgame == false;

	while (startgame == false) {
		StartWindow(font, window, sprite);
	}
	
	while (window.isOpen() && (pause == false) && startgame) {

		srand(time(NULL));
		unsigned int RandomNumber = rand();

		window.draw(sprite);
		deltaTime = clock.restart().asSeconds();

		vel_time += deltaTime;
		if (vel_time >= Max_Shots_per_Sek) {
			vel_time -= Max_Shots_per_Sek;
			freeshot = true;
		}

		stone_time += deltaTime;
		if (stone_time >= Max_Stones_per_sek) {
			stone_time -= Max_Stones_per_sek - stone_time/stone_density_change - (rand() % int(Max_Stones_per_sek));
			freestone = true;
		}

		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window.close();
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			pause = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Space) && freeshot) {
			std::cout << "Shots Array: " << Shots.size() << " Stones Array: " << Stones.size() << std::endl;
			shotfired = true;
			shotsCount++;
			ShotSound.play();
			stone_speed += stone_speed / stone_vel_change;
			spaceship_speed += spaceship_speed / ship_vel_change;
			freeshot = false;
		}

		if (freestone) {
			stonepresent = true;
			stonesCount++;
			freestone = false;
		}

		if (shotfired && pause == false) {
			Shot shot(&ShotTexture, Window_Height, spaceship.GetPosition(), spaceship.GetHeight());
			Shots.push_back(shot);
			shotfired = false;
		}

		if (stonepresent && pause == false) {
			Stone stone(&StoneTexture);
			stone.SetFirstPosition(Window_Height);
			Stones.push_back(stone);
			stonepresent = false;
		}

		spaceship.Update(spaceship_speed, spaceship.GetPosition().x, spaceship.GetPosition().y, Window_Height);

		if (shotsCount >= 1) {
			for (int i = 0; i < Shots.size(); ++i) {
				Shots[i].Update(shot_speed, Shots[i].GetPosition().x, Shots[i].GetPosition().y);
			}
		} 

		for (int i = 0; i < Stones.size(); ++i) {
			Stones[i].Update(stone_speed, Stones[i].GetPosition().x, Stones[i].GetPosition().y, Window_Height, spaceship.GetHeight());
			if (Stones[i].GroundHit()) {
				Lifes--;
			}
		}

		for (int i = 0; i < Stones.size(); ++i) {
			for (int j = 0; j < Shots.size(); ++j) {
				if (hit.ShotHitCheck(Stones[i].GetPosition(), Stones[i].GetSize(), Shots[j].GetPosition(), Shots[j].GetSize())) {
					Score++;
					Stones[i].CheckShotHit();
					Shots[j].CheckStoneHit();
				}
			}
		}

		
		Stones.erase(std::remove_if(Stones.begin(), Stones.end(), [](Stone stone) { return stone.GroundHit(); }), Stones.end());
		Stones.erase(std::remove_if(Stones.begin(), Stones.end(), [](Stone stone) { return stone.ShotHit(); }), Stones.end());
		Shots.erase(std::remove_if(Shots.begin(), Shots.end(), [](Shot shot) { return shot.GetsDestroyed(); }), Shots.end());

		if (pause) {
			PauseWindow(sprite, window);
		}

		if (Lifes == 0) {
			Player player(name, Score);
			Stones.erase(Stones.begin(),Stones.end());
			Shots.erase(Shots.begin(), Shots.end());
			GameOverWindow(sprite, window, font, Score);
		}

		spaceship.Draw(window);

		if (shotsCount >= 1) {
			for (int i = 0; i < Shots.size(); ++i) {
				Shots[i].Draw(window);
			}
		}

		for (int i = 0; i < Stones.size(); ++i) {
			Stones[i].Draw(window);
		}

		ScoreText.setString("Score: " + std::to_string(Score));
		LifeText.setString("Lifes: " + std::to_string(Lifes));
		window.draw(ScoreText);
		window.draw(LifeText);
	
		window.display();
	}

	return 0;
}