#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class DataBaseExtraction : public IExtraction
	{
	public:
		DataBaseExtraction(DataBase^);
		void extractData(Track^ track) override;
		
	private:
		DataBase^ _dataBase;
	};

}