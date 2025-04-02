#include <Windows.h>
#include "GameOfLife.h"

int main()
{
	World W, Empty, Previous;

	// Gosper's glider gun
	Set(2, 26, W);

	Set(3, 24, W);
	Set(3, 26, W);

	Set(4, 14, W);
	Set(4, 15, W);
	Set(4, 22, W);
	Set(4, 23, W);
	Set(4, 36, W);
	Set(4, 37, W);

	Set(5, 13, W);
	Set(5, 17, W);
	Set(5, 22, W);
	Set(5, 23, W);
	Set(5, 36, W);
	Set(5, 37, W);

	Set(6, 2, W);
	Set(6, 3, W);
	Set(6, 12, W);
	Set(6, 18, W);
	Set(6, 22, W);
	Set(6, 23, W);

	Set(7, 2, W);
	Set(7, 3, W);
	Set(7, 12, W);
	Set(7, 16, W);
	Set(7, 18, W);
	Set(7, 19, W);
	Set(7, 24, W);
	Set(7, 26, W);
	
	Set(8, 12, W);
	Set(8, 18, W);
	Set(8, 26, W);

	Set(9, 13, W);
	Set(9, 17, W);
	
	Set(10, 14, W);
	Set(10, 15, W);



	// From https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
	
	//Set(10, 17, W);
	//Set(10, 16, W);
	//Set(10, 15, W);
	//Set(10, 13, W);

	//Set(11, 17, W);

	//Set(12, 14, W);
	//Set(12, 13, W);

	//Set(13, 16, W);
	//Set(13, 15, W);
	//Set(13, 13, W);

	//Set(14, 17, W);
	//Set(14, 15, W);
	//Set(14, 13, W);

	// This is equivalent of 'cls'
	std::cout << "\033[2J\033[1;1H";

	Display(W);

	for (auto n = 1; (n < 1000) && (W != Empty) && (W != Previous); n++)
	{
		Sleep(10);
		Previous = W;
		W = Next(W);
		std::cout << "\033[2J\033[1;1H";
		Display(W);
	}
	return 0;
}
