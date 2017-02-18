/*
================================================================================
            S-Sampler

    Author: SwingCoder
    Email: SwingCoder2@gmail.com
    Github: https://github.com/SwingCoder

    License: MIT License, Copyright (c) 2012 by SwingCoder
================================================================================
*/

// sine wave audio source.

#ifndef __SINEWAVEVOICE_H_
#define __SINEWAVEVOICE_H_

//===================================================================================
class SineWaveSound : public SynthesiserSound
{
public:
    SineWaveSound()    { }
    bool appliesToNote (int /*midiNoteNumber*/)   { return true; }
    bool appliesToChannel (int /*midiChannel*/)   { return true; }
};

//==================================================================================
class SineWaveVoice : public SynthesiserVoice 
{
public:
    SineWaveVoice();
    bool canPlaySound (SynthesiserSound* sound);
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition);
    void stopNote (float velocity, bool allowTailOff);
    void pitchWheelMoved (int /*newValue*/)  { }
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) { }
    void renderNextBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

private:
    double currentAngle, angleDelta, level, tailOff;
};

#endif // __SINEWAVEVOICE_H_