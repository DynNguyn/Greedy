

#include "maxdefense.hh"
#include "timer.hh"

int main()
{
	//test the greedy and exhaustive 
	
	auto all_armors = load_armor_database("armor.csv");
	assert( all_armors );
	
	
	auto filtered_armors = filter_armor_vector(*all_armors, 1, 2500, 300);	
	auto filtered_armors2 = filter_armor_vector(*all_armors, 1, 2500, 20);
	std::unique_ptr<ArmorVector> greedResult;
	std::unique_ptr<ArmorVector> exhaustResult;
	
	std::cout<<"filter size: "<<filtered_armors->size()<<std::endl;
	

	//start and find time of greedy 
	Timer timer;
	
	greedResult=greedy_max_defense(*filtered_armors, 5000);
	double time_elapsed=timer.elapsed();

	std::cout<<"greedy time elapsed: "<<time_elapsed<<std::endl;
	//print_armor_vector(*greedResult);


	//start and find time of exhaustive
	std::cout<<"filter size2: "<<filtered_armors2->size()<<std::endl;
	Timer timer2;
	exhaustResult=exhaustive_max_defense(*filtered_armors2, 5000);
	double time_elapsed2=timer2.elapsed();

	std::cout<<"exhaust time elapsed2: "<<time_elapsed2<<std::endl;
	//print_armor_vector(*exhaustResult);
}


