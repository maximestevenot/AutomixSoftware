#pragma once

namespace AutoMixUI {
	using namespace AutoMixDataManagement;

	public interface class UsingCollectionView
	{
	public:
		virtual System::Void update(TrackCollection^) abstract;
	};
}