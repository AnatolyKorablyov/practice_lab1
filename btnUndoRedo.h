#pragma once
#include "UI.h"
#include "Story.h"

class btnUndo : public UI
{
public:
	btnUndo();
	~btnUndo();
	virtual void drawUI(RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> &shapes) override;
};

class btnRedo : public UI
{
public:
	btnRedo();
	~btnRedo();
	virtual void drawUI(RenderWindow & window) override;
	virtual void commandBtn(std::vector<Figure*> &shapes) override;
};