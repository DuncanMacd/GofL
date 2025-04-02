#include "pch.h"
#include "..\GOL\GameOfLife.h"

TEST(IsAliveWorks, TestGOL) {
	World w;
	EXPECT_FALSE(IsAlive(1, 1, w));
}

TEST(SetTrueWorks, TestGOL) {
	World w;
	ASSERT_FALSE(IsAlive(1, 1, w));
	Set(1, 1, w);
	EXPECT_TRUE(IsAlive(1, 1, w));
}

TEST(SetFalseWorks, TestGOL) {
	World w;
	Set(1, 1, w);
	ASSERT_TRUE(IsAlive(1, 1, w));
	Set(1, 1, w, false);
	EXPECT_FALSE(IsAlive(1, 1, w));
}

TEST(NoNeighboursOfNonEdgeWork, TestGOL) {
	World w;
	Set(1, 1, w);
	auto neighbours = Neighbours(1, 1, w);
	EXPECT_EQ(0, neighbours);
}

TEST(NeighboursOfNonEdgeWork, TestGOL) {
	World w;
	Set(1, 1, w);

	Set(0, 0, w);
	EXPECT_EQ(1, Neighbours(1, 1, w));
	Set(0, 1, w);
	EXPECT_EQ(2, Neighbours(1, 1, w));
	Set(0, 2, w);
	EXPECT_EQ(3, Neighbours(1, 1, w));
	Set(1, 0, w);
	EXPECT_EQ(4, Neighbours(1, 1, w));
	Set(1, 2, w);
	EXPECT_EQ(5, Neighbours(1, 1, w));
	Set(2, 0, w);
	EXPECT_EQ(6, Neighbours(1, 1, w));
	Set(2, 1, w);
	EXPECT_EQ(7, Neighbours(1, 1, w));
	Set(2, 2, w);
	EXPECT_EQ(8, Neighbours(1, 1, w));
}

TEST(DetermineNextState_works_for_underpopulation, TestGOL)
{
	World w;
	Set(1, 1, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
	Set(0, 1, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
}

TEST(DetermineNextState_works_for_next_generation, TestGOL)
{
	World w;
	Set(1, 1, w);

	Set(0, 0, w);
	Set(0, 1, w);
	EXPECT_TRUE(DetermineNewState(1, 1, w));

	Set(0, 2, w);
	EXPECT_TRUE(DetermineNewState(1, 1, w));
}

TEST(DetermineNextState_works_for_overpopulation, TestGOL)
{
	World w;
	Set(1, 1, w);

	Set(0, 0, w);
	Set(0, 1, w);
	Set(0, 2, w);
	Set(1, 0, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
	Set(1, 2, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
	Set(2, 0, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
	Set(2, 1, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
	Set(2, 2, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
}

TEST(DetermineNextState_works_for_reproduction, TestGOL)
{
	World w;

	Set(0, 0, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(0, 1, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(0, 2, w);
	EXPECT_TRUE(DetermineNewState(1, 1, w));

	Set(1, 0, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(1, 2, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(2, 0, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(2, 1, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));

	Set(2, 2, w);
	EXPECT_FALSE(DetermineNewState(1, 1, w));
}
