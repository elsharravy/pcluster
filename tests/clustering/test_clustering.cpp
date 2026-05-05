#include <gtest/gtest.h>

#include <clustering/KMeans.h>
#include <model/Location.h>
#include <model/ParcelLocker.h>
#include <model/Cluster.h>

using namespace pcluster;

TEST(ClusteringTest, lockersCountPreserved) {
	std::vector<pcluster::ParcelLocker> lockers;
	std::vector<pcluster::Location> clusterCenters;
	constexpr int lockersCount = 7;
	constexpr int clustersCount = 3;
	for (size_t i = 0; i < lockersCount; i++)
	{
		lockers.push_back(ParcelLocker("abc", Location(2, 2)));

	}

	for (size_t i = 0; i < clustersCount; i++)
	{
		clusterCenters.push_back(Location(Location(2, 2)));
	}

	std::vector < Cluster > clusters = clustering(clusterCenters, lockers);

	int lockersTotal = 0;

	for (auto& cluster : clusters) {
		lockersTotal += cluster.getLockers().size();
	}

	EXPECT_EQ(lockersCount, lockersTotal);
}

TEST(ClusteringTest, solveSimpleCase) {
	std::vector<pcluster::ParcelLocker> lockers;
	std::vector<pcluster::Location> clusterCenters;


	lockers.push_back(ParcelLocker("1", Location(0, 0)));
	lockers.push_back(ParcelLocker("2", Location(0.5, 3)));
	lockers.push_back(ParcelLocker("3", Location(2, 1)));
	lockers.push_back(ParcelLocker("4", Location(5, 6)));
	lockers.push_back(ParcelLocker("5", Location(-1, 0)));


	clusterCenters.push_back(Location(Location(-1, 2)));
	clusterCenters.push_back(Location(Location(3, 2)));
	clusterCenters.push_back(Location(Location(0, -2)));
	

	std::vector < Cluster > clusters = clustering(clusterCenters, lockers);

	std::vector<pcluster::ParcelLocker> lockers1 = clusters.at(0).getLockers();
	std::vector<pcluster::ParcelLocker> lockers2 = clusters.at(1).getLockers();
	std::vector<pcluster::ParcelLocker> lockers3 = clusters.at(2).getLockers();

	EXPECT_EQ("1", lockers3.at(0).getName());
	EXPECT_EQ("2", lockers1.at(0).getName());
	EXPECT_EQ("3", lockers2.at(0).getName());
	EXPECT_EQ("4", lockers2.at(1).getName());
	EXPECT_EQ("5", lockers1.at(1).getName());
}

TEST(ClusteringTest, throwsOnClusterCentersEmpty) {
	std::vector<pcluster::ParcelLocker> lockers;
	std::vector<pcluster::Location> clusterCenters;

	lockers.push_back(ParcelLocker("1", Location(0, 0)));
	lockers.push_back(ParcelLocker("2", Location(0.5, 3)));

	EXPECT_THROW(clustering(clusterCenters, lockers), std::invalid_argument);
}