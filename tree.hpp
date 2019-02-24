#pragma once

#include <string>
#include <fstream>

struct TreeElement
{
	std::string data_;
	TreeElement * parent_;
	TreeElement * left_;
	TreeElement * right_;
	
};

class tree
{
public:
///Constructors and destructor:
	tree(); //done
	explicit tree(std::string str);//done
	~tree();//done

///Methods:
	/*move current pointer
	 * return 0 if your way is empty*/
	bool go_left();//done
	bool go_right();//done
	bool go_back();//done
	void go_head();//done
	
	/*add new element
	 * return 0 if you way is already exist*/
	bool add_left(std::string data);//done
	bool add_right(std::string data);//done
	
	/*delete element
	 * return 0 if your way is empty*/
	bool del_right();//done
	bool del_left();//done
	
	/*return link to a data of current element*/
	std::string & data(); //done
	
	void to_file(std::string filename);

private:
	/*delete tree starting from pointer*/
	void delete_tree(TreeElement * first); //done
	void dump(TreeElement * first, std::ofstream & dumpfile);

	TreeElement * head_;
	TreeElement * current_;
	
};
