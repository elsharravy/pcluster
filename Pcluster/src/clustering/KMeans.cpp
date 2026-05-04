#include "KMeans.h"

#include <algorithm>

#include <clustering/KMeansCluster.h>
#include <model/Cluster.h>

size_t findMinimumIndex(const std::vector<float>& vec) {

	size_t min_element_index = min_element(vec.begin(), vec.end()) - vec.begin();
	return min_element_index;
}

std::vector<pcluster::Location> pcluster::kmeans(int clustersCount,const std::vector<ParcelLocker>& lockers, int n, float tolerance)
{
	// clusters random centers
	std::vector<KMeansCluster> clusters;
	clusters.reserve(clustersCount);
	for (size_t i = 0; i < clustersCount; i++)
	{
		Location center((i+1)*5, (i+1)*5);
		clusters.push_back(center);
	}

	// assign n lockers
	for (size_t i = 0; i < n; i++)
	{
		std::vector<float> distances;
		auto& locker = lockers.at(i);
		// calculate distance to every cluster
		for (auto& cluster : clusters) {
			float distance = locker.getLocation().distance(cluster.getCenter());
			distances.push_back(distance);
		}
		size_t minimumIndex = findMinimumIndex(distances);
		clusters.at(minimumIndex).addLocationUpdateCenter(locker.getLocation());
	}

	// return list of cluster centers
	std::vector<Location> centers;

	for (auto& cluster : clusters) {
		centers.push_back(cluster.getCenter());
	}

	return centers;
}

std::vector<pcluster::Cluster> pcluster::clustering(const std::vector<Location>& centroids, const std::vector<ParcelLocker>& lockers) {

	// initialize clusters
	std::vector<pcluster::Cluster> clusters;

	for (auto& centroid : centroids) {
		clusters.push_back(Cluster(centroid));
	}

	// assign each locker to cluster
	for (size_t i = 0; i < lockers.size(); i++)
	{
		std::vector<float> distances;
		auto& locker = lockers.at(i);
		// calculate distance to every cluster
		for (auto& centroid : centroids) {
			float distance = locker.getLocation().distance(centroid);
			distances.push_back(distance);
		}
		size_t minimumIndex = findMinimumIndex(distances);
		clusters.at(minimumIndex).addLocker(locker);
	}

	return clusters;

}