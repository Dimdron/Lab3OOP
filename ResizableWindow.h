#pragma once
class ResizableWindow
{
private:
    int width;
	int height;
    //virtual void onChangedSize(int wigth, int height) {}
public:
    ResizableWindow(int w, int h);
	~ResizableWindow();

	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();

    void changeSize(int dw, int dh);
};

