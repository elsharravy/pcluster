#include <iostream>

#include <stdexcept>

#include <CLI/CLI.hpp>

#include <clustering/KMeans.h>
#include <model/ParcelLocker.h>
#include <service/ClusterService.h>
#include <json/JsonFileSaver.h>


using namespace std;
using namespace pcluster;

int main(int argc, char** argv)
{

	CLI::App app{ "Pcluster App" };

	std::string outputFileName = "clusters.json";
	std::string province = "";
	std::string country = "";
	int clustersCount;
	int maxIterations = 100;
	int limit = 0;
	double tolerance = 0.000001;
	
	app.add_option("-c,--clusters", clustersCount, "Number of clusters")->required();
	app.add_option("-o,--output", outputFileName, "Output file path");
	app.add_option("-p,--province", province, "Province to filter by");
	app.add_option("-k,--country", country, "Country to filter by");
	app.add_option("-i,--iterations", maxIterations, "kMeans algorithm maximum iterations");
	app.add_option("-t,--tolerance", tolerance, "kMeans algorithm tolerance");
	app.add_option("-l,--limit", limit, "Limit parcel lockers retrieved");

	CLI11_PARSE(app, argc, argv);

	try {

		std::string endpointURL = "https://api-global-points.easypack24.net/v1/points";

		std::vector<pcluster::ParcelLocker> lockers;

		cout << "Retrieving data from: " << endpointURL << endl;

		pcluster::ClusterService cs;
		lockers = cs.getParcelLockersFromRestApi(limit);

		cout << "Starting kmeans algorithm" << endl;

		auto locations = kmeans(clustersCount, lockers, maxIterations, tolerance);

		vector<Cluster> clusters = clustering(locations, lockers);

		cout << "Saving clusters to file: " << outputFileName << endl;

		JsonFileSaver::saveClustersToFile(outputFileName, clusters);

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}



	return 0;
}