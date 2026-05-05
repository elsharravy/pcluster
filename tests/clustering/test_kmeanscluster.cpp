#include <gtest/gtest.h>

#include <clustering/KMeansCluster.h>
#include <model/Location.h>

using namespace pcluster;

TEST(KMeansClusterTest, calculatingCenter) {

	KMeansCluster cluster(Location( 20,30));

	cluster.addLocation(Location(20, 30));
	cluster.addLocation(Location(40, 50));
	cluster.addLocation(Location(15, 25));
	cluster.addLocation(Location(12.5, 55));
	cluster.addLocation(Location(45, 20));
	cluster.addLocation(Location(25, 40));
	cluster.addLocation(Location(12.5, 10));
	
	cluster.recalculateCenter();
	cluster.clear();

	float latitude = cluster.getCenter().getLatitude();
	float longitude = cluster.getCenter().getLongitude();

	EXPECT_NEAR(24.2857f, longitude, 1e-4);
	EXPECT_NEAR(32.8571f, latitude, 1e-4);
}