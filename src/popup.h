#pragma once

class Popup
{
private:
	const char* ID;
	const char* text;
	const char* btn1_text;
	const char* btn2_text;
	bool btn_1 = false;
	bool btn_2 = false;

public:
	int clicked = -1;

public:
	Popup(const char* str, const char* text);
	~Popup();
	void Update(bool &open);
	void SetButton1(const char* text);
	void SetButton2(const char* text);
};
