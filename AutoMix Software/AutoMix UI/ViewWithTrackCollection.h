// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixUI {
	using namespace AutoMixDataManagement;

	public interface class ViewWithTrackCollection
	{
	public:
		virtual System::Void update(TrackCollection^) abstract;
	};
}