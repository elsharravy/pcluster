#include "KMeans.h"

#include <algorithm>
#include <iostream>
#include <random>

#include <clustering/KMeansCluster.h>
#include <model/Cluster.h>

size_t findMinimumIndex(const std::vector<float>& vec) {

	size_t min_element_index = min_element(vec.begin(), vec.end()) - vec.begin();
	return min_element_index;
}

std::vector<pcluster::Location> pcluster::kmeans(int clustersCount,const std::vector<ParcelLocker>& lockers, int maxIterations, float tolerance)
{
	// special cases
	if (clustersCount == 0) {
		throw std::invalid_argument("clustersCount can't be equal zero");
	}
	if (clustersCount > lockers.size()) {
		throw std::invalid_argument("clustersCount can't be greater than lockers count");
	}
	if ( lockers.empty() ) {
		throw std::invalid_argument("lockers vector can't be empty");
	}
	if ( maxIterations < 1 ) {
		throw std::invalid_argument("max iterations must be higher than 0");
	}

	// clusters random centers
	std::vector<KMeansCluster> clusters;
	clusters.reserve(clustersCount);

	std::vector<size_t> indices;
	indices.reserve(lockers.size());
	for (size_t i = 0; i < lockers.size(); i++)
	{
		indices.push_back(i);
	}

	auto rng = std::default_random_engine{};
	std::ranges::shuffle(indices, rng);

	for (size_t i = 0; i < clustersCount; i++)
	{
		Location center = lockers.at( indices.at(i) ).getLocation();
		clusters.push_back(center);
	}
	
	for (size_t i = 0; i < maxIterations; i++)
	{
		// assignment step
		for ( auto& locker : lockers)
		{
			std::vector<float> distances;
			
			for (auto& cluster : clusters) {
				float distance = locker.getLocation().distance(cluster.getCenter());
				distances.push_back(distance);
			}
			size_t minimumIndex = findMinimumIndex(distances);
			clusters.at(minimumIndex).addLocation(locker.getLocation());
		}

		// update step
		float maxCenterChange = 0;
		for (auto& cluster : clusters) {
			float centerChange = cluster.recalculateCenter();
			if (centerChange > maxCenterChange) {
				maxCenterChange = centerChange;
			} 
			cluster.clear();
		}

		// stop if algorithm converged
		if (maxCenterChange < tolerance) {
			break;
		}

	}

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