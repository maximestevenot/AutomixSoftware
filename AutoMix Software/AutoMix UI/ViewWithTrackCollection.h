#pragma once

namespace AutoMixUI {
	using namespace AutoMixDataManagement;

	public interface class ViewWithTrackCollection
	{
	public:
		virtual System::Void update(TrackCollection^) abstract;
	};
}