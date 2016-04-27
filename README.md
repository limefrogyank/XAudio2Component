# XAudio2Component
Audio playback for games using XAudio2 in C#

I'm creating a game using Win2D.  Instead of adding SharpDX just to get some audio functionality, I decided to 
write a Windows Runtime Component that uses XAudio2.  Most of the code is ripped directly from a sample on 
Microsoft's website called Basic Audio Sample.  (link below)

https://code.msdn.microsoft.com/windowsapps/Basic-Audio-Sample-9a5bb0b7

Currently, this component allows you to load multiple ADPCM sound files from your main app project folders into a buffer 
and play them (or stop them) at will.

To use:

```
// Assuming an XNA style code setup:
// in your static Game class

public static XAudio2Component.XAudio2SoundPlayer sound;

// in your static Game class's CreateResources method
// files are located in the Audio folder in the app package

sound = new XAudio2Component.XAudio2SoundPlayer(48000);
sound.LoadWav("Audio\\sound1-adpcm.wav"); //index 0
sound.LoadWav("Audio\\sound2-adpcm.wav"); //index 1
sound.LoadWav("Audio\\sound3-adpcm.wav"); //index 2


//anywhere you want to play the file

Game.sound.StopSound(0);  //stop the sound from index 0
Game.sound.PlaySound(1);  //play the sound in index 1
```

Only ADPCM files will play!  If you have PCM files, you can use the command line tool, adpcmencode3.exe,
which is located in c:\Program Files (x86)\Windows Kits\10\bin\x64\.

If you don't even have PCM files, download Audacity and convert them for free.
l
