#include "cocos2d.h"

USING_NS_CC;
class ScoreBroad :public cocos2d::Layer
{
public:
	int type;
	int score;
	void setScore(int number);
	int getScore();
	cocos2d::Label* scoreLabel;
	cocos2d::LayerColor* background;
	static ScoreBroad* createScoreBroad(int score, int width, int height, const char* title, int type, float x, float y);
	void enemyInit(int score, int width, int height, const char* title, int type, float x, float y);
	virtual bool init();
	CREATE_FUNC(ScoreBroad);
};

