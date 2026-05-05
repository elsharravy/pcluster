#include <gtest/gtest.h>

#include <clustering/KMeans.h>
#include <model/Location.h>
#include <model/ParcelLocker.h>

using namespace pcluster;

TEST(KMeansTest, throwsWhenClusterCountIsZero) {
	std::vector<pcluster::ParcelLocker> lockers;
	lockers.push_back(ParcelLocker("abc", Location(2, 2)));

	EXPECT_THROW(kmeans(0, lockers), std::invalid_argument);
}

TEST(KMeansTest, throwsWhenLockersIsEmpty) {
	std::vector<pcluster::ParcelLocker> lockers;

	EXPECT_THROW(kmeans(4, lockers), std::invalid_argument);
}

TEST(KMeansTest, throwsWhenClusterCountIsGreaterThanLockersCount) {
	std::vector<pcluster::ParcelLocker> lockers;
	lockers.push_back(ParcelLocker("abc", Location(2, 2)));
	lockers.push_back(ParcelLocker("def", Location(1, 3)));
	lockers.push_back(ParcelLocker("ghi", Location(4, 5)));

	EXPECT_THROW(kmeans(4, lockers), std::invalid_argument);
}

TEST(KMeansTest, throwsWhenMaxIterationsIsLowerThanOne) {
	std::vector<pcluster::ParcelLocker> lockers;
	lockers.push_back(ParcelLocker("abc", Location(2, 2)));
	lockers.push_back(ParcelLocker("def", Location(1, 3)));
	lockers.push_back(ParcelLocker("ghi", Location(4, 5)));

	EXPECT_THROW(kmeans(2, lockers, 0), std::invalid_argument);
}

TEST(KMeansTest, correctClusterCount ) {
	std::vector<pcluster::ParcelLocker> lockers;
	constexpr int lockersCount = 7;
	constexpr int clustersCount = 3;
	for (size_t i = 0; i < lockersCount; i++)
	{
		lockers.push_back(ParcelLocker("abc", Location(2, 2)));

	}

	std::vector<Location> centers = kmeans(clustersCount, lockers);

	EXPECT_EQ(clustersCount, centers.size());
}

TEST(KMeansTest, solveSimpleCase) {
	std::vector<pcluster::ParcelLocker> lockers;

	constexpr int clustersCount = 2;

	lockers.push_back(ParcelLocker("abc", Location(-4, 2)));
	lockers.push_back(ParcelLocker("def", Location(-4, -2)));
	lockers.push_back(ParcelLocker("ghi", Location(4, 2)));
	lockers.push_back(ParcelLocker("jkl", Location(4, -2)));


	std::vector<Location> centers = kmeans(clustersCount, lockers);

	float center1Lat = centers.at(0).getLatitude();
	float center1Lon = centers.at(0).getLongitude();

	float center2Lat = centers.at(1).getLatitude();
	float center2Lon = centers.at(1).getLongitude();

	if (center1Lon == 4) {
		EXPECT_NEAR(0, center1Lat, 1e-4);
		EXPECT_NEAR(4, center1Lon, 1e-4);
		EXPECT_NEAR(0, center2Lat, 1e-4);
		EXPECT_NEAR(-4, center2Lon, 1e-4);
	}
	else {
		EXPECT_NEAR(0, center1Lat, 1e-4);
		EXPECT_NEAR(-4, center1Lon, 1e-4);
		EXPECT_NEAR(0, center2Lat, 1e-4);
		EXPECT_NEAR(4, center2Lon, 1e-4);
	}


}