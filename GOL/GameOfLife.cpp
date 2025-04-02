#include "GameOfLife.h"

void Display(const World& w)
{
	for (auto r : w)
	{
		std::cout << r.to_string('.', '+') << "\n";
	}
}

World Next(const World& current)
{
	World next;

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			Set(r, c, next, DetermineNewState(r, c, current));
		}
	}

	return next;
}

bool ValidRow(const int r) { return (r >= 0 && r < ROWS); }
bool ValidColumn(const int c) { return (c >= 0 && c < COLUMNS); }

bool IsAlive(const int r, const int c, const World& W)
{
	bool rc = false;

	if (ValidRow(r) && ValidColumn(c))
	{
		rc = W[r].test(c);
	}

	return rc;
}

void Set(const int r, const int c, World& W, const bool Alive)
{
	if (ValidRow(r) && ValidColumn(c))
	{
		W[r].set(c, Alive);
	}
}

int Neighbours(const int r, const int c, const World& W)
{
	return (IsAlive(r - 1, c - 1, W) + IsAlive(r - 1, c, W) + IsAlive(r - 1, c + 1, W) +
		IsAlive(r, c - 1, W) + IsAlive(r, c + 1, W) +
		IsAlive(r + 1, c - 1, W) + IsAlive(r + 1, c, W) + IsAlive(r + 1, c + 1, W));
}

bool DetermineNewState(const int r, const int c, const World& W)
{
	bool rc = false;

	const auto neighbour_count = Neighbours(r, c, W);

	if (IsAlive(r, c, W))
	{
		switch (neighbour_count)
		{
		case 2:
		case 3:
			rc = true;
			break;
		default:
			rc = false;
			break;
		}
	}
	else
	{
		if (neighbour_count == 3)
		{
			rc = true;
		}
	}

	return rc;
}
