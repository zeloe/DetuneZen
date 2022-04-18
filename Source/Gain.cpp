/*
  ==============================================================================

    Gain.cpp
    Created: 17 Apr 2022 6:27:14pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#include "Gain.h"
Gain::Gain():
offset(0)
{
    for (int i = 0; i < 2; i++){
        gainParameter[i] = std::make_unique<juce::LinearSmoothedValue<float>> (0.0f) ;
    }
}
Gain::~Gain()
{
    
}

float Gain::gainprocess(float inputaudio, int chan)
{
    return inputaudio * gainParameter[chan]->getNextValue();
}

float Gain::offsetgianprocess(float inputaudio, int chan)
{
    offset = 1.f - gainParameter[chan]->getNextValue();
    return inputaudio * offset;
}

void Gain::savestage(float inputaudio, int numChans)
{
    audiotogiveback[numChans] = inputaudio;
}

float Gain::returnstage(int numChans)
{
    return audiotogiveback[numChans];
}

