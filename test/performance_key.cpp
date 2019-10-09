#include <random>
#include <iostream>
#include <vector>

#include "custom_list.hpp"
#include "timer.hpp"

int main() {
	int num_times = 1000;
	std::vector<long int> durations;


	for(int j = 0; j < num_times; ++j) {
		CustomList<int> list;
		std::vector<std::string> rand_vec; 
		int total = 100000;

		std::random_device rd; 
	    std::mt19937 gen(rd());
	    std::uniform_int_distribution<> dis(0, total - 1);

		for(int i = 0; i < total; ++i) {
			list.push_back(std::to_string(i), i);
			rand_vec.push_back(std::to_string(dis(gen)));
		}

		int sum = 0;
		std::cout << "Getting by random key - ";
		{
			Timer t;
			for(int i = 0; i < total; ++i) {
				sum += list.get_by_key(rand_vec[i]);
			}
			durations.push_back(t.stop());
		}
		std::cout << sum << std::endl;
	}

	long sum = std::accumulate(durations.begin(), durations.end(), 0, std::plus<int>());
	long mean = sum/num_times;

	long var = 0;
	for(int n = 0; n < num_times; ++n) {
	  	var += (durations[n] - mean) * (durations[n] - mean);
	}
	var /= num_times;
	double sd = sqrt(var);

	std::cout << "Mean time in microseconds for " << num_times << " times:" << std::endl;
	std::cout << "Mean - " << mean << ", Standard Deviation - " << sd << std::endl; 
	std::cout << "Coefficient of Deviation - " << sd/mean * 100 << std::endl; 
	return 0;
}