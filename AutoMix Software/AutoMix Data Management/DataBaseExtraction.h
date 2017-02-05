#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class DataBaseExtraction : public IExtraction
	{
	public:
		DataBaseExtraction(DataBase^);
		void extractData(System::ComponentModel::BackgroundWorker^, System::Threading::CancellationTokenSource^, Track^ track) override;
		
	private:
		DataBase^ _dataBase;
	};

}