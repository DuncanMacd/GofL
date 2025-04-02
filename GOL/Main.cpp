#include <Windows.h>
#include "GameOfLife.h"

int main()
{
	World W, Empty, Previous;
	Set(10, 17, W);
	Set(10, 16, W);
	Set(10, 15, W);
	Set(10, 13, W);

	Set(11, 17, W);

	Set(12, 14, W);
	Set(12, 13, W);

	Set(13, 16, W);
	Set(13, 15, W);
	Set(13, 13, W);

	Set(14, 17, W);
	Set(14, 15, W);
	Set(14, 13, W);

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
