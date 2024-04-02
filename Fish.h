#pragma once


class Fish {
private:
	float _x, _y;
	bool isLeft;
public:
	void Setpos(int x,int y){
		_x = x;
		_y = y;
	}

	float GetxPos() { return _x; }
	float GetyPos() { return _y; }

};