#ifndef __OPENAL_OGGSAMPLE_H
#define __OPENAL_OGGSAMPLE_H

#include "Filesystem.h"
#include "openal_sample.h"
#include "ogg/ogg.h"
#include "vorbis/codec.h"
#include "vorbis/vorbisenc.h"
#include "vorbis/vorbisfile.h"

#define MAX_PATH_LENGTH 1024

class COpenALOggSample : public IOpenALSample
{
public:
	COpenALOggSample();
	~COpenALOggSample();

	virtual void Open(const char* filename);
	virtual void Close();

	bool CheckStream(ALuint buffer);
	void UpdateMetadata();

private:
	FileHandle_t oggFile;
	OggVorbis_File oggSample;
	vorbis_info* vorbisInfo;
	vorbis_comment* vorbisComment;
};

#endif
