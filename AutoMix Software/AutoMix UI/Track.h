#pragma once

#include <string>
#include "Utils.h"


namespace AMResources {

	public class Track
	{
	private:

		class Data
		{
		public:

			unsigned int _bpm;
			unsigned int _duration;

			Data()
			{
				_bpm = 0;
				_duration = 0;
			}
		};


		std::string _path;
		Data *_data;
		std::string _name;

		friend std::ostream & operator<<(std::ostream &, const Track &);

	public:

		Track(std::string path)
		{
			_path = path;
			_data = new Data();
			_name = nameFromPath(path);
		}

		std::string getName()
		{
			return _name;
		}

		int getBPM()
		{
			return _data->_bpm;
		}

		int getDuration() {
			return _data->_duration;
		}
	};

	std::ostream & operator<<(std::ostream & out, const Track & track) {
		out << track._name;
		return out;
	}
}
