#include <string>
#include <iostream>
#include "tree.hpp"
#include <fstream>

///Constructors and destructor:

tree::tree() : head_(new TreeElement), current_(head_)
{
	head_->left_ = 0;
	head_->right_ = 0;
	head_->parent_ = 0;
	head_->data_ = "";
}

tree::tree(std::string str) : head_(new TreeElement), current_(head_)
{
	head_->left_ = 0;
	head_->right_ = 0;
	head_->parent_ = 0;
	head_->data_ = str;
}

tree::~tree()
{
	delete_tree(head_);
}

///Methods:

void tree::delete_tree(TreeElement * first)
{
	if(first -> left_)
		delete_tree(first -> left_);
	if(first -> right_)
		delete_tree(first -> right_);
		
	first -> left_ = 0;
	first -> right_ = 0;
	
	delete first;
}

bool tree::go_left()
{
	if(!current_->left_)
		return 0;
	current_ = current_->left_;
	return 1;
}

bool tree::go_right()
{
	if(!current_->right_)
		return 0;
	current_ = current_->right_;
	return 1;
}

bool tree::go_back()
{
	if(!current_->parent_)
		return 0;
	current_ = current_->parent_;
	return 1;
}

void tree::go_head()
{
	current_ = head_;
}

bool tree::add_left(std::string str)
{
	if(current_ -> left_)
		return 0;
		
	current_ -> left_ = new TreeElement;
	current_ -> left_ -> data_ = str;
	current_ -> left_ -> left_ = 0;
	current_ -> left_ -> right_ = 0;
	current_ -> left_ -> parent_ = current_;
	
	return 1;
}

bool tree::add_right(std::string str)
{
	if(current_ -> right_)
		return 0;
		
	current_ -> right_ = new TreeElement;
	current_ -> right_ -> data_ = str;
	current_ -> right_ -> left_ = 0;
	current_ -> right_ -> right_ = 0;
	current_ -> right_ -> parent_ = current_;
	
	return 1;
}

bool tree::del_left()
{
	if(!current_ -> left_)
		return 0;
		
	delete_tree(current_ -> left_);
	current_ -> left_ = 0;
	
	return 1;
}

bool tree::del_right()
{
	if(!current_ -> right_)
		return 0;
		
	delete_tree(current_ -> right_);
	current_ -> right_ = 0;
	
	return 1;
}

std::string & tree::data()
{
	return current_->data_;
}

void tree::to_file(std::string filename)
{
	std::ofstream dumpfile(filename);
	
	this->dump(head_, dumpfile);
	
	dumpfile.close();
}

void tree::dump(TreeElement * first, std::ofstream & dumpfile)
{
	dumpfile << first -> data_;
	
	if(!(first->left_ || first->right_))
		return;
		
	dumpfile << " ( ";
	
	if(first->left_)
	{
		this->dump(first -> left_, dumpfile);
	}
	
	dumpfile << " , ";
	
	if(first->right_)
	{
		this->dump(first->right_, dumpfile);
	}
	
	dumpfile << " ) ";
}
