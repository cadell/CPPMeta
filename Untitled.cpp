#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//using namespace std;
class RandData
{
	public:
		RandData (std::string _data)
		{
			hold.push_back(_data);
		}
		void display_data()
		{
			for(unsigned int i =0; i < hold.size(); i ++)
			{
				std::cout << hold[i] <<std::endl;
			}
		}

		void add_data(std::string thing)
		{
			hold.push_back(thing);
		}
		//Given an Object pass another object of the same type and append data to the Objects attribute 
		void add_object_data(RandData* data)
		{
			auto vect_data = data->ret_data();
			for(int i =0; i < data->ret_data().size(); i++)
			{
				hold.push_back(vect_data[i]);
			}
			
		}
		void set_meta_Data(RandData* data)
		{
			meta_data.push_back(data);
		}
		void print_meta_data()
		{
			for(unsigned int i =0; i < meta_data.size(); i++)
			{
				meta_data[i]->display_data();
			}
		}
	private:
		std::vector<std::string> ret_data()
		{
			return hold;
		}
		std::vector<std::string> hold;
		std::vector<RandData*> meta_data;
};
int main(int argc, char *argv[]) {
	RandData* DATA[3];
	//RandData* fullVectorArray;
	DATA[0] = new RandData("test5");
	DATA[1] = new RandData("Test4");
	DATA[2] = new RandData("Test3");
	
	DATA[0]->add_object_data(DATA[1]);
	DATA[0]->display_data();
	std::cout <<"\n";
	DATA[0]->add_object_data(DATA[2]);
	DATA[0]->display_data();
	std::cout << "\n";
	DATA[0]->add_data("Test2");
	DATA[0]->display_data();
	std::cout << "\n";
	
	DATA[0]->set_meta_Data(DATA[0]);
	DATA[0]->set_meta_Data(DATA[1]);
	DATA[0]->set_meta_Data(DATA[2]);
	std::cout << "Printing META_DATA AF " <<std::endl;
	DATA[0]->print_meta_data();
	
	delete DATA[0];
	delete DATA[1];
	delete DATA[2];
}