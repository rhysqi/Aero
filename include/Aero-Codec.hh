#ifndef AERO_CODEC_HH
#define AERO_CODEC_HH

namespace Aero_Codec {
	namespace Audio {
		void Source(const char *FILENAME);
		void Stream(void *Source);
	}

	namespace Video {
		void Source(const char *FILENAME);
		void Stream(void *Source);
	}

	namespace Compressor {
		void Source(const char *FILENAME);
		void Stream(void *Source);
	}

	namespace Decompressor {
		void Source(const char *FILENAME);
		void Stream(void *Source);
	}
}

#endif /* AERO_CODEC_HH */