/*
  ==============================================================================

    DetuneProcess.h
    Created: 15 Apr 2022 2:18:17pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "WaveShapes.h"
#include "AR.h"
class DetuneProcess
{
public:
    DetuneProcess();
    ~DetuneProcess();

    void getTheSampleRate(double sampleRate);
      
    void constructDelayLines(int counts);
    float phasor (float frequency);
    float outofphase (float frequency);
    
    float detuneDelay (float inputAudio,
                       float frequency,
                       int chans,
                       int flag);
    
    double processWaveShape(float frequency,
                            float index,
                            const double* buffer
                            );
    std::unique_ptr<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> delayLine1[2] ;
    std::unique_ptr<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> delayLine2[2] ;
    std::unique_ptr<AR> AtRe[2];
private:
   
    float phasor1;
    float phasor2;
    float phasein;
    float phaseout;
    float normal, offset;
    float output = 0;
    double mgetSampleRate;
};
