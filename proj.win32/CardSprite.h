
#include "cocos2d.h"
#define CARD_BORDER 4

USING_NS_CC;
class CardSprite : public cocos2d::Sprite
{
public:
	int number;
	int getNumber();
	void setNumber(int num);
	cocos2d::Label* labelNumber;
	cocos2d::LayerColor* layerColorBG;
	static CardSprite* createCardSprite(int number, int size, float x, float y);
	void enemyInit(int number, int size, float x, float y);
	virtual bool init();
	CREATE_FUNC(CardSprite);
};

