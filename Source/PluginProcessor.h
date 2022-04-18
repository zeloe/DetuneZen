/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "WaveShapes.h"
#include "DetuneProcess.h"
#include "Gain.h"
inline float factor (float pfreq, float dw)
{
    return (1.f - pfreq * dw/1000.f);
}
inline float pfreq (float factor, float dw)
{
    return(factor * 1000.f/dw + 1.f);
}



inline float linear_interp(float  v0, float  v1, float  t)
{
    return (1 - t) * v0 + t * v1;
};
//==============================================================================
/**
*/
const int MaxBufferDelaySize = 22000;
class DetuneZenAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    DetuneZenAudioProcessor();
    ~DetuneZenAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState apvts {*this, nullptr, "Parameters", createParameterLayout()};
    void initDsp()
    {
        for (int i = 0; i < 2; i++){
            detunerOne[i] = std::make_unique<DetuneProcess>();
            
            detunerTwo[i] = std::make_unique<DetuneProcess>();
            
            detunerThree[i] = std::make_unique<DetuneProcess>();
            
            detunerFour[i] = std::make_unique<DetuneProcess>();
            
            detunerFive[i] = std::make_unique<DetuneProcess>();
            
            detunerSix[i] = std::make_unique<DetuneProcess>();
            
            detunerSeven[i] = std::make_unique<DetuneProcess>();
            
            detunerEight[i] = std::make_unique<DetuneProcess>();
            
            detunerNine[i] = std::make_unique<DetuneProcess>();
           
            detunerTen[i] =std::make_unique<DetuneProcess> ();
            
            detunerEleven[i] = std::make_unique<DetuneProcess> ();
            
            detunerTwelve[i] = std::make_unique<DetuneProcess> ();
            
            
            gainAmp[i] = std::make_unique<Gain> ();
            
            wetAmp[i] = std::make_unique<Gain> ();
           
        }
        
        
        
    }
    
        
    
private:
    juce::LinearSmoothedValue<float> detuneSmooth {0.0f};
    juce::LinearSmoothedValue<float> dryWetSmooth {0.0f};
    juce::LinearSmoothedValue<float> HzSmooth {0.0f};
    juce::LinearSmoothedValue<float> AmpSmooth {0.0f};
    juce::LinearSmoothedValue<float> rangeSmooth {0.0f};
    juce::LinearSmoothedValue<float> offsetSmooth {0.0f};
    
    
    std::unique_ptr<DetuneProcess> detunerOne[2];
    std::unique_ptr<DetuneProcess> detunerTwo[2];
    std::unique_ptr<DetuneProcess> detunerThree[2];
    std::unique_ptr<DetuneProcess> detunerFour[2];
    std::unique_ptr<DetuneProcess> detunerFive[2];
    std::unique_ptr<DetuneProcess> detunerSix[2];
    std::unique_ptr<DetuneProcess> detunerSeven[2];
    std::unique_ptr<DetuneProcess> detunerEight[2];
    std::unique_ptr<DetuneProcess> detunerNine[2];
    std::unique_ptr<DetuneProcess> detunerTen[2];
    std::unique_ptr<DetuneProcess> detunerEleven[2];
    std::unique_ptr<DetuneProcess> detunerTwelve[2];
    
    std::unique_ptr<Gain> gainAmp[2];
    std::unique_ptr<Gain> wetAmp[2];
    
    float toout = 0.f;
    float toout2 = 0.f;
    float toout3 = 0.f;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetuneZenAudioProcessor)
};
