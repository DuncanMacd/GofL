#pragma once

#include <bitset>
#include <array>
#include <iostream>

const auto COLUMNS = 40;
const auto ROWS = 24;

using Row = std::bitset<COLUMNS>;
using World = std::array<Row, ROWS>;

void Display(const World& w);

bool ValidRow(const int r);
bool ValidColumn(const int c);

bool IsAlive(const int r, const int c, const World& W);

void Set(const int r, const int c, World& W, bool Alive = true);

int Neighbours(const int r, const int c, const World& W);
bool DetermineNewState(const int r, const int c, const World& W);

World Next(const World& current);
