#pragma once

//  decimationAndFilterConstants.h
//  28-Apr-2018 23:52:27

//  Made with:
//   decimation_pre_Kaiser_FIR_and_post_NOTCH_filters_vector_Double.m


namespace decimationAndFilterConstants
{

	// Legal sample frequencies
	const std::vector<int> legalSampleFrequencies {8000, 16000, 44100, 48000, 88200, 96000};

	// Filters at FS 8000 Hzconst int FSAtFS8000 = 8000;
	const int mForPreDecimationFIRFilterAtFS8000 = 196;
	const int noCoeffsForPreDecimationFIRFilterAtFS8000 = 197;

	// Decimation at FS 8000 Hz
	const int sampleSpaceAtDecimatedFsAtFS8000 = 10;
	const int decimatedFsAtFS8000 = 800;
	const int decimatedFnyqAtAtFS8000 = 400;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS8000 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS8000 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS8000 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS8000 = 7;


	// Filters at FS 16000 Hz
	const int FSAtFS16000 = 16000;
	const int mForPreDecimationFIRFilterAtFS16000 = 392;
	const int noCoeffsForPreDecimationFIRFilterAtFS16000 = 393;

	// Decimation at FS 16000 Hz
	const int sampleSpaceAtDecimatedFsAtFS16000 = 20;
	const int decimatedFsAtFS16000 = 800;
	const int decimatedFnyqAtAtFS16000 = 400;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS16000 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS16000 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS16000 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS16000 = 7;


	// Filters at FS 44100 Hz
	const int FSAtFS44100 = 44100;
	const int mForPreDecimationFIRFilterAtFS44100 = 1081;
	const int noCoeffsForPreDecimationFIRFilterAtFS44100 = 1082;

	// Decimation at FS 44100 Hz
	const int sampleSpaceAtDecimatedFsAtFS44100 = 50;
	const int decimatedFsAtFS44100 = 882;
	const int decimatedFnyqAtAtFS44100 = 441;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS44100 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS44100 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS44100 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS44100 = 7;


	// Filters at FS 48000 Hz
	const int FSAtFS48000 = 48000;
	const int mForPreDecimationFIRFilterAtFS48000 = 1176;
	const int noCoeffsForPreDecimationFIRFilterAtFS48000 = 1177;

	// Decimation at FS 48000 Hz
	const int sampleSpaceAtDecimatedFsAtFS48000 = 64;
	const int decimatedFsAtFS48000 = 750;
	const int decimatedFnyqAtAtFS48000 = 375;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS48000 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS48000 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS48000 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS48000 = 7;


	// Filters at FS 88200 Hz
	const int FSAtFS88200 = 88200;
	const int mForPreDecimationFIRFilterAtFS88200 = 1723;
	const int noCoeffsForPreDecimationFIRFilterAtFS88200 = 1724;

	// Decimation at FS 88200 Hz
	const int sampleSpaceAtDecimatedFsAtFS88200 = 105;
	const int decimatedFsAtFS88200 = 840;
	const int decimatedFnyqAtAtFS88200 = 420;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS88200 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS88200 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS88200 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS88200 = 7;


	// Filters at FS 96000 Hz
	const int FSAtFS96000 = 96000;
	const int mForPreDecimationFIRFilterAtFS96000 = 1875;
	const int noCoeffsForPreDecimationFIRFilterAtFS96000 = 1876;

	// Decimation at FS 96000 Hz
	const int sampleSpaceAtDecimatedFsAtFS96000 = 128;
	const int decimatedFsAtFS96000 = 750;
	const int decimatedFnyqAtAtFS96000 = 375;
	const int c50HzNotchNoOfCoeffsAtDecimatedFsAtFS96000 = 6;
	const int d50HzNotchNoOfCoeffsAtDecimatedFsAtFS96000 = 7;

	const int c60HzNotchNoOfCoeffsAtDecimatedFsAtFS96000 = 6;
	const int d60HzNotchNoOfCoeffsAtDecimatedFsAtFS96000 = 7;


	// Goertzel target frequencies
	const std::vector<std::vector<long double>> goertzelTargetFrequencies
	{
		  {
			  69.0L,  70.0L,  71.0L,
			  72.0L,  72.5L,  73.0L,  73.5L,  74.0L,  74.5L,  75.0L,  75.5L,  76.0L,  76.5L,
			  77.0L,  77.1L,  77.2L,  77.3L,  77.4L,  77.5L,  77.6L,  77.7L,  77.8L,  77.9L,  78.0L,  78.1L,  78.2L,  78.3L,  78.4L,  78.5L,  78.6L,  78.7L,  78.8L,  78.9L,  79.0L,  79.1L,  79.2L,  79.3L,  79.4L,  79.5L,  79.6L,  79.7L,  79.8L,  79.9L,  80.0L,  80.1L,  80.2L,  80.3L,  80.4L,  80.5L,  80.6L,  80.7L,  80.8L,  80.9L,  81.0L,  81.1L,  81.2L,  81.3L,  81.4L,  81.5L,  81.6L,  81.7L,  81.8L,  81.9L,
			  82.0L,  82.1L,  82.2L,  82.3L,  82.4L,  82.5L,  82.6L,  82.7L,  82.8L,  82.9L,  83.0L,  83.1L,  83.2L,  83.3L,  83.4L,  83.5L,  83.6L,  83.7L,  83.8L,  83.9L,  84.0L,  84.1L,  84.2L,  84.3L,  84.4L,  84.5L,  84.6L,  84.7L,  84.8L,  84.9L,  85.0L,  85.1L,  85.2L,  85.3L,  85.4L,  85.5L,  85.6L,  85.7L,  85.8L,  85.9L,  86.0L,  86.1L,  86.2L,  86.3L,  86.4L,  86.5L,  86.6L,  86.7L,  86.8L,  86.9L,
			  87.0L,  87.5L,  88.0L,  88.5L,  89.0L,  89.5L,  90.0L,  90.5L,  91.0L,  91.5L,
			  92.0L,  93.0L,  94.0L
		  }
		, {
			  97.0L,  98.0L,  99.0L,
			 100.0L, 100.5L, 101.0L, 101.5L, 102.0L, 102.5L, 103.0L, 103.5L, 104.0L, 104.5L,
			 105.0L, 105.1L, 105.2L, 105.3L, 105.4L, 105.5L, 105.6L, 105.7L, 105.8L, 105.9L, 106.0L, 106.1L, 106.2L, 106.3L, 106.4L, 106.5L, 106.6L, 106.7L, 106.8L, 106.9L, 107.0L, 107.1L, 107.2L, 107.3L, 107.4L, 107.5L, 107.6L, 107.7L, 107.8L, 107.9L, 108.0L, 108.1L, 108.2L, 108.3L, 108.4L, 108.5L, 108.6L, 108.7L, 108.8L, 108.9L, 109.0L, 109.1L, 109.2L, 109.3L, 109.4L, 109.5L, 109.6L, 109.7L, 109.8L, 109.9L,
			 110.0L, 110.1L, 110.2L, 110.3L, 110.4L, 110.5L, 110.6L, 110.7L, 110.8L, 110.9L, 111.0L, 111.1L, 111.2L, 111.3L, 111.4L, 111.5L, 111.6L, 111.7L, 111.8L, 111.9L, 112.0L, 112.1L, 112.2L, 112.3L, 112.4L, 112.5L, 112.6L, 112.7L, 112.8L, 112.9L, 113.0L, 113.1L, 113.2L, 113.3L, 113.4L, 113.5L, 113.6L, 113.7L, 113.8L, 113.9L, 114.0L, 114.1L, 114.2L, 114.3L, 114.4L, 114.5L, 114.6L, 114.7L, 114.8L, 114.9L,
			 115.0L, 115.5L, 116.0L, 116.5L, 117.0L, 117.5L, 118.0L, 118.5L, 119.0L, 119.5L,
			 120.0L, 121.0L, 122.0L
		  }
		, {
			 134.0L, 135.0L, 136.0L,
			 137.0L, 137.5L, 138.0L, 138.5L, 139.0L, 139.5L, 140.0L, 140.5L, 141.0L, 141.5L,
			 142.0L, 142.1L, 142.2L, 142.3L, 142.4L, 142.5L, 142.6L, 142.7L, 142.8L, 142.9L, 143.0L, 143.1L, 143.2L, 143.3L, 143.4L, 143.5L, 143.6L, 143.7L, 143.8L, 143.9L, 144.0L, 144.1L, 144.2L, 144.3L, 144.4L, 144.5L, 144.6L, 144.7L, 144.8L, 144.9L, 145.0L, 145.1L, 145.2L, 145.3L, 145.4L, 145.5L, 145.6L, 145.7L, 145.8L, 145.9L, 146.0L, 146.1L, 146.2L, 146.3L, 146.4L, 146.5L, 146.6L, 146.7L, 146.8L, 146.9L,
			 147.0L, 147.1L, 147.2L, 147.3L, 147.4L, 147.5L, 147.6L, 147.7L, 147.8L, 147.9L, 148.0L, 148.1L, 148.2L, 148.3L, 148.4L, 148.5L, 148.6L, 148.7L, 148.8L, 148.9L, 149.0L, 149.1L, 149.2L, 149.3L, 149.4L, 149.5L, 149.6L, 149.7L, 149.8L, 149.9L, 150.0L, 150.1L, 150.2L, 150.3L, 150.4L, 150.5L, 150.6L, 150.7L, 150.8L, 150.9L, 151.0L, 151.1L, 151.2L, 151.3L, 151.4L, 151.5L, 151.6L, 151.7L, 151.8L, 151.9L,
			 152.0L, 152.5L, 153.0L, 153.5L, 154.0L, 154.5L, 155.0L, 155.5L, 156.0L, 156.5L,
			 157.0L, 158.0L, 159.0L
		  }
		, {
			 183.0L, 184.0L, 185.0L,
			 186.0L, 186.5L, 187.0L, 187.5L, 188.0L, 188.5L, 189.0L, 189.5L, 190.0L, 190.5L,
			 191.0L, 191.1L, 191.2L, 191.3L, 191.4L, 191.5L, 191.6L, 191.7L, 191.8L, 191.9L, 192.0L, 192.1L, 192.2L, 192.3L, 192.4L, 192.5L, 192.6L, 192.7L, 192.8L, 192.9L, 193.0L, 193.1L, 193.2L, 193.3L, 193.4L, 193.5L, 193.6L, 193.7L, 193.8L, 193.9L, 194.0L, 194.1L, 194.2L, 194.3L, 194.4L, 194.5L, 194.6L, 194.7L, 194.8L, 194.9L, 195.0L, 195.1L, 195.2L, 195.3L, 195.4L, 195.5L, 195.6L, 195.7L, 195.8L, 195.9L,
			 196.0L, 196.1L, 196.2L, 196.3L, 196.4L, 196.5L, 196.6L, 196.7L, 196.8L, 196.9L, 197.0L, 197.1L, 197.2L, 197.3L, 197.4L, 197.5L, 197.6L, 197.7L, 197.8L, 197.9L, 198.0L, 198.1L, 198.2L, 198.3L, 198.4L, 198.5L, 198.6L, 198.7L, 198.8L, 198.9L, 199.0L, 199.1L, 199.2L, 199.3L, 199.4L, 199.5L, 199.6L, 199.7L, 199.8L, 199.9L, 200.0L, 200.1L, 200.2L, 200.3L, 200.4L, 200.5L, 200.6L, 200.7L, 200.8L, 200.9L,
			 201.0L, 201.5L, 202.0L, 202.5L, 203.0L, 203.5L, 204.0L, 204.5L, 205.0L, 205.5L,
			 206.0L, 207.0L, 208.0L
		  }
		, {
			 234.0L, 235.0L, 236.0L,
			 237.0L, 237.5L, 238.0L, 238.5L, 239.0L, 239.5L, 240.0L, 240.5L, 241.0L, 241.5L,
			 242.0L, 242.1L, 242.2L, 242.3L, 242.4L, 242.5L, 242.6L, 242.7L, 242.8L, 242.9L, 243.0L, 243.1L, 243.2L, 243.3L, 243.4L, 243.5L, 243.6L, 243.7L, 243.8L, 243.9L, 244.0L, 244.1L, 244.2L, 244.3L, 244.4L, 244.5L, 244.6L, 244.7L, 244.8L, 244.9L, 245.0L, 245.1L, 245.2L, 245.3L, 245.4L, 245.5L, 245.6L, 245.7L, 245.8L, 245.9L, 246.0L, 246.1L, 246.2L, 246.3L, 246.4L, 246.5L, 246.6L, 246.7L, 246.8L, 246.9L,
			 247.0L, 247.1L, 247.2L, 247.3L, 247.4L, 247.5L, 247.6L, 247.7L, 247.8L, 247.9L, 248.0L, 248.1L, 248.2L, 248.3L, 248.4L, 248.5L, 248.6L, 248.7L, 248.8L, 248.9L, 249.0L, 249.1L, 249.2L, 249.3L, 249.4L, 249.5L, 249.6L, 249.7L, 249.8L, 249.9L, 250.0L, 250.1L, 250.2L, 250.3L, 250.4L, 250.5L, 250.6L, 250.7L, 250.8L, 250.9L, 251.0L, 251.1L, 251.2L, 251.3L, 251.4L, 251.5L, 251.6L, 251.7L, 251.8L, 251.9L,
			 252.0L, 252.5L, 253.0L, 253.5L, 254.0L, 254.5L, 255.0L, 255.5L, 256.0L, 256.5L,
			 257.0L, 258.0L, 259.0L
		  }
		, {
			 317.0L, 318.0L, 319.0L,
			 320.0L, 320.5L, 321.0L, 321.5L, 322.0L, 322.5L, 323.0L, 323.5L, 324.0L, 324.5L,
			 325.0L, 325.1L, 325.2L, 325.3L, 325.4L, 325.5L, 325.6L, 325.7L, 325.8L, 325.9L, 326.0L, 326.1L, 326.2L, 326.3L, 326.4L, 326.5L, 326.6L, 326.7L, 326.8L, 326.9L, 327.0L, 327.1L, 327.2L, 327.3L, 327.4L, 327.5L, 327.6L, 327.7L, 327.8L, 327.9L, 328.0L, 328.1L, 328.2L, 328.3L, 328.4L, 328.5L, 328.6L, 328.7L, 328.8L, 328.9L, 329.0L, 329.1L, 329.2L, 329.3L, 329.4L, 329.5L, 329.6L, 329.7L, 329.8L, 329.9L,
			 330.0L, 330.1L, 330.2L, 330.3L, 330.4L, 330.5L, 330.6L, 330.7L, 330.8L, 330.9L, 331.0L, 331.1L, 331.2L, 331.3L, 331.4L, 331.5L, 331.6L, 331.7L, 331.8L, 331.9L, 332.0L, 332.1L, 332.2L, 332.3L, 332.4L, 332.5L, 332.6L, 332.7L, 332.8L, 332.9L, 333.0L, 333.1L, 333.2L, 333.3L, 333.4L, 333.5L, 333.6L, 333.7L, 333.8L, 333.9L, 334.0L, 334.1L, 334.2L, 334.3L, 334.4L, 334.5L, 334.6L, 334.7L, 334.8L, 334.9L,
			 335.0L, 335.5L, 336.0L, 336.5L, 337.0L, 337.5L, 338.0L, 338.5L, 339.0L, 339.5L,
			 340.0L, 341.0L, 342.0L
		  }
	};

	// Goertzel no frequencies per string
	const int goertzelNoFrequenciesPerString = 126;

	// Goertzel frequencies to avoid because
	// guitar strings have harmonics at same frequency
	const long double goertzelFrequencyToAvoid = 328.0L;

};
