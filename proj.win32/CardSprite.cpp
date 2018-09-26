#include "CardSprite.h"
#include "cocos2d.h"

using namespace std;

CardSprite* CardSprite::createCardSprite(int number, int size, float x, float y)
{
	CardSprite* enemy = new CardSprite();
	if (enemy && enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(number, size, x, y);
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}
bool CardSprite::init()
{
	if (!Sprite::init())
		return false;
	return true;
}
void CardSprite::enemyInit(int number, int size, float x, float y)
{
	this->number = number;
	layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(216, 210, 214, 255), size - CARD_BORDER, size - CARD_BORDER);
	layerColorBG->setPosition(x, y);
	if (number > 0)
	{
		/*char* buff;
		sprintf(buff, "%d", number);*/
		labelNumber = Label::create(String::createWithFormat("%i", number)->getCString(), "Arial", 36);
		labelNumber->setPosition(Vec2((size - CARD_BORDER) / 2, (size - CARD_BORDER) / 2));
		layerColorBG->addChild(labelNumber);
	}
	else
	{
		labelNumber = Label::create("", "Arial", 28);
		labelNumber->setPosition(Vec2(size / 2, size / 2));
		layerColorBG->addChild(labelNumber);
	}
	this->addChild(layerColorBG);
}
int CardSprite::getNumber()
{
	return this->number;
}
void CardSprite::setNumber(int num)
{
	number = num;
	if (number > 0)
	{
		labelNumber->setString(String::createWithFormat("%i", number)->getCString());
		switch (number)
		{
		case 2:
			layerColorBG->setColor(Color3B(255, 246, 247));
			labelNumber->setColor(Color3B(33, 33, 7));
			break;
		case 4:
			layerColorBG->setColor(Color3B(255, 218, 163));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 8:
			layerColorBG->setColor(Color3B(255, 144, 91));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 16:
			layerColorBG->setColor(Color3B(255, 101, 46));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 32:
			layerColorBG->setColor(Color3B(255, 80, 46));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 64:
			layerColorBG->setColor(Color3B(254, 56, 60));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 128:
			layerColorBG->setColor(Color3B(6, 194, 240));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 256:
			layerColorBG->setColor(Color3B(5, 140, 240));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 512:
			layerColorBG->setColor(Color3B(4, 140, 200));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 1024:
			layerColorBG->setColor(Color3B(3, 112, 154));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 2048:
			layerColorBG->setColor(Color3B(2, 98, 131));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 4096:
			layerColorBG->setColor(Color3B(1, 93, 118));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 8192:
			layerColorBG->setColor(Color3B(58, 49, 132));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 16384:
			layerColorBG->setColor(Color3B(41, 41, 49));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		case 32768:
			layerColorBG->setColor(Color3B(33, 33, 7));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		default:
			layerColorBG->setColor(Color3B(0, 0, 0));
			labelNumber->setColor(Color3B(255, 255, 255));
			break;
		}
		if (num > 10000)
			labelNumber->setSystemFontSize(24);
		else if (num > 1000)
			labelNumber->setSystemFontSize(28);
		else if (num > 100)
			labelNumber->setSystemFontSize(34);
		else if(num > 100)
			labelNumber->setSystemFontSize(38);
		else
			labelNumber->setSystemFontSize(44);
	}
	else
	{
		labelNumber->setString("");
		layerColorBG->setColor(Color3B(216, 210, 214));
	}
}