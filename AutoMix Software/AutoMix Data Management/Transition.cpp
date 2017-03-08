#include "stdafx.h"
#include "Transition.h"

using namespace AutoMixDataManagement;
using namespace NAudio;
using namespace Wave;
using namespace SampleProviders;

Transition::Transition()
{
	_transition = gcnew FadeInOutSampleProvider(,true);
}

void AutoMixDataManagement::Transition::fadeIn(Track ^ track1, Track ^ track2)
{
	throw gcnew System::NotImplementedException();
}

void AutoMixDataManagement::Transition::fadeOut(Track ^ track1, Track ^ track2)
{
	throw gcnew System::NotImplementedException();
}
