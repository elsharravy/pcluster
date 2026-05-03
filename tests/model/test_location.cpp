#include <gtest/gtest.h>

#include <cmath>

#include <model/Location.h>

TEST(LocationTest, calculatesDistanceOnAxis) {
	pcluster::Location loc1(-5, 0), loc2(10, 0);
	float distance = loc1.distance(loc2);
	EXPECT_NEAR(15.0, distance, 1e-5);
};

TEST(LocationTest, calculatesDistanceDiagonally) {
	pcluster::Location loc1(1, 1), loc2(-1, -1);
	float distance = loc1.distance(loc2);
	EXPECT_NEAR(2 * sqrt(2), distance, 1e-5);
};

TEST(LocationTest, calculatesDistanceWithItself) {
	pcluster::Location loc(-1, -1);
	float distance = loc.distance(loc);
	EXPECT_NEAR(0, distance, 1e-5);
};