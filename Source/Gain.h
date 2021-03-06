/*
  ==============================================================================

    Gain.h
    Created: 17 Apr 2022 6:27:14pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
class Gain{
public:
    Gain();
    ~Gain();
    float gainprocess(float inputaudio, int chan);
    float offsetgianprocess(float inputaudio, int chan);
    std::unique_ptr<juce::LinearSmoothedValue<float>> gainParameter[2];
    void savestage(float inputaudio, int numChans);
    float returnstage(int numChans);
    void goto0(float inputaudio);
private :
    float offset;
    float audiotogiveback[2];
};
