#pragma once
#include <exception>

class File
{
public:
	virtual int get() = 0;
};

class io_error : public std::exception
{

};

class auto_dao
{
private:
	 File *file;
public:
	auto_dao(File* _file)
	{
		file = _file;
	}
	int read_auto()
		try
		{
			return file->get();
		}
		catch(const io_error &e)
		{
			return -1;
		}

};

