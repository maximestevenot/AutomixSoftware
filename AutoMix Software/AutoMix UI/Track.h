#pragma once

#include <string>

namespace AMResources {

	public class Track
	{
	private:

		class Data
		{
		private:
			unsigned int _bpm;
			unsigned int _duration;
		};

		std::string _path;
		Data _data;
		std::string _name;

		friend std::ostream & operator<<(std::ostream &, const Track &);
	};

	std::ostream & operator<<(std::ostream & out, const Track & track) {
		out << track._name;
		return out;
	}
}
