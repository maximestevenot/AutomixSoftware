// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AutoMix Tests.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace AutoMixTests
{
	[TestClass]
	public ref class TestClass
	{

	public:
		[TestMethod]
		void TestMethod()
		{
			// TODO: Add your test code here
			Assert::AreEqual("titi", "titi");
		}
	};
}


