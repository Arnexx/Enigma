#pragma once
#include <vector>
#include <string>
using namespace std;

class Rotor
{
private:

	vector<int> rotor;
	vector<int> rotorShifts;
	int position;
	int notchPosition;

public:
	Rotor();

	int		step();
	int		goForward(int value);
	int		goBackward(int value);
	void	setPosition(int pos);
	void	setSequense(string seq);
	int		getPosition();
	int		getNotchPosition();
	void	setNotchPosition(int value);


	~Rotor();
};

