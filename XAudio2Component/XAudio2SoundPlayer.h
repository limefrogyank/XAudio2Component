#pragma once

#include "DirectXBase.h"

#include "mmreg.h"
#include <vector>
#include <memory>

struct ImplData;

namespace XAudio2Component
{
	public ref class XAudio2SoundPlayer sealed
	{

	public:
		XAudio2SoundPlayer(uint32 sampleRate);

		bool   PlaySound(size_t index);
		bool   StopSound(size_t index);

		bool   LoadWav(Platform::String^ appPackageRelativePath);

	internal:
		bool   IsSoundPlaying(size_t index) const;
		size_t GetSoundCount() const;
		size_t AddSound(_In_ WAVEFORMATEX* format, _In_ Platform::Array<byte>^ data);

		void Suspend();
		void Resume();

	private:
		~XAudio2SoundPlayer();

		interface IXAudio2*                     m_audioEngine;
		interface IXAudio2MasteringVoice*       m_masteringVoice;
		std::vector<std::shared_ptr<ImplData>>  m_soundList;
	};
}
