/*
  ==============================================================================

    DetuneProcess.cpp
    Created: 15 Apr 2022 2:18:17pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#include "DetuneProcess.h"

DetuneProcess::DetuneProcess():
phasor1(0),
phasor2(0.25),
normal(0),
offset(0),
mgetSampleRate(44100)
{
    for (int i = 0; i < 2; i++){
    delayLine1[i] = std::make_unique<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> (5000) ;
    delayLine2[i] = std::make_unique<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> (5000);
    AtRe[i] = std::make_unique<AR>();
    }
    
   
}

DetuneProcess::~DetuneProcess()
{
    
    
}

void DetuneProcess::constructDelayLines(int counts)
{
        delayLine1[counts] = std::make_unique<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> (5000) ;
        delayLine2[counts] = std::make_unique<juce::dsp::DelayLine<float, juce::dsp::DelayLineInterpolationTypes::Linear>> (5000);
    
}


void DetuneProcess::getTheSampleRate(double sampleRate)
{
    mgetSampleRate = sampleRate;
}



float DetuneProcess::phasor(float frequency)
{
    phasor1 += (1./(mgetSampleRate/(frequency)));
    if (phasor1 > 1.0) phasor1 = 0;
    return phasor1;
}

float DetuneProcess::outofphase(float frequency)
{
    phasor2 += (1./(mgetSampleRate/(frequency)));
    if (phasor2 > 1.0) phasor2 = 0;
    return phasor2;
}

double DetuneProcess::processWaveShape(float frequency,
                        float index,
                        const double* buffer
                        )
{
    double remainder;
    double a,b,c,d,a1,a2,a3;
    double output;
    index = index * 512.f;
    if ( index > 512 ) index -=512;
    remainder = index - floor(index);

    if (index==0) {
        a=buffer[(long) 512];
        b=buffer[(long) index];
        c=buffer[(long) index+1];
        d=buffer[(long) index+2];

    } else {
        a=buffer[(long) index-1];
        b=buffer[(long) index];
        c=buffer[(long) index+1];
        d=buffer[(long) index+2];

    }

    a1 = 0.5f * (c - a);
    a2 = a - 2.5 * b + 2.f * c - 0.5f * d;
    a3 = 0.5f * (d - a) + 1.5f * (b - c);
    output = double (((a3 * remainder + a2) * remainder + a1) * remainder + b);
    return(output);
}




float DetuneProcess::detuneDelay(float inputAudio,float frequency, int chans, int flag)
{
   
        phasein = this->phasor(frequency);
        delayLine1[chans]->pushSample(chans, inputAudio);
        delayLine1[chans]->setDelay(mgetSampleRate * 0.001f * phasein* 100.f);
        phaseout =  this->outofphase(frequency);
        delayLine2[chans]->pushSample(chans, inputAudio);
        delayLine2[chans]->setDelay(mgetSampleRate * 0.001f * phaseout* 100.f);
    
    output =  (delayLine1[chans]->popSample(chans) * this->processWaveShape(frequency, phasein, possineBuffer) + delayLine2[chans]->popSample(chans) * this->processWaveShape(frequency, phaseout, possineBuffer) * -1.f);
    /*
    * AtRe[chans]->process();
        
        if (flag == 0 || AtRe[chans]->getState() == 0)
        {
                AtRe[chans]->gate(true);
            if( AtRe[chans]->process() == 0.f)
            {
                    AtRe[chans]->reset();
            }
        }
    
        else
            {
                
                AtRe[chans]->gate(false);
               
            }
    
   */
    return output;
    
}
