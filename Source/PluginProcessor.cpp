/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DetuneZenAudioProcessor::DetuneZenAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    initDsp();
}




DetuneZenAudioProcessor::~DetuneZenAudioProcessor()
{
}

//==============================================================================
const juce::String DetuneZenAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DetuneZenAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DetuneZenAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DetuneZenAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DetuneZenAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DetuneZenAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DetuneZenAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DetuneZenAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DetuneZenAudioProcessor::getProgramName (int index)
{
    return {};
}

void DetuneZenAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DetuneZenAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    detuneSmooth.reset(sampleRate, 0.001f);
    dryWetSmooth.reset(sampleRate, 0.001f);
    HzSmooth.reset(sampleRate, 0.001f);
    AmpSmooth.reset(sampleRate,0.001f);
    rangeSmooth.reset(sampleRate, 0.1f);
    offsetSmooth.reset(sampleRate, 0.001f);
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = 2;
   
    for(int i = 0; i < 2; i++){
        detunerOne[i]->delayLine1[i]->prepare(spec);
        detunerOne[i]->delayLine2[i]->prepare(spec);
        detunerOne[i]->getTheSampleRate(sampleRate);
        detunerOne[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        detunerTwo[i]->delayLine1[i]->prepare(spec);
        detunerTwo[i]->delayLine2[i]->prepare(spec);
        detunerTwo[i]->getTheSampleRate(sampleRate);
        detunerTwo[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        detunerThree[i]->delayLine1[i]->prepare(spec);
        detunerThree[i]->delayLine2[i]->prepare(spec);
        detunerThree[i]->getTheSampleRate(sampleRate);
        detunerThree[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        detunerFour[i]->delayLine1[i]->prepare(spec);
        detunerFour[i]->delayLine2[i]->prepare(spec);
        detunerFour[i]->getTheSampleRate(sampleRate);
        detunerFour[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        detunerFive[i]->delayLine1[i]->prepare(spec);
        detunerFive[i]->delayLine2[i]->prepare(spec);
        detunerFive[i]->getTheSampleRate(sampleRate);
        detunerFive[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        detunerSix[i]->delayLine1[i]->prepare(spec);
        detunerSix[i]->delayLine2[i]->prepare(spec);
        detunerSix[i]->getTheSampleRate(sampleRate);
        detunerSix[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
         
        detunerSeven[i]->delayLine1[i]->prepare(spec);
        detunerSeven[i]->delayLine2[i]->prepare(spec);
        detunerSeven[i]->getTheSampleRate(sampleRate);
        detunerSeven[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
         
        detunerEight[i]->delayLine1[i]->prepare(spec);
        detunerEight[i]->delayLine2[i]->prepare(spec);
        detunerEight[i]->getTheSampleRate(sampleRate);
        detunerEight[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
         
        detunerNine[i]->delayLine1[i]->prepare(spec);
        detunerNine[i]->delayLine2[i]->prepare(spec);
        detunerNine[i]->getTheSampleRate(sampleRate);
        detunerNine[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
         
        detunerTen[i]->delayLine1[i]->prepare(spec);
        detunerTen[i]->delayLine2[i]->prepare(spec);
        detunerTen[i]->getTheSampleRate(sampleRate);
        detunerTen[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
         
        detunerEleven[i]->delayLine1[i]->prepare(spec);
        detunerEleven[i]->delayLine2[i]->prepare(spec);
        detunerEleven[i]->getTheSampleRate(sampleRate);
        detunerEleven[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        detunerTwelve[i]->delayLine1[i]->prepare(spec);
        detunerTwelve[i]->delayLine2[i]->prepare(spec);
        detunerTwelve[i]->getTheSampleRate(sampleRate);
        detunerTwelve[i]->AtRe[i]->setReleaseRate(0.1 * sampleRate);
        
        gainAmp[i]->gainParameter[i]->reset(sampleRate, 0.001f);
        wetAmp[i]->gainParameter[i]->reset(sampleRate, 0.001f);
    }
}
void DetuneZenAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DetuneZenAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DetuneZenAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    
    
    
    
    for (int numChans = 0;  numChans < 2; numChans++) {
        auto* inputs = buffer.getWritePointer(numChans);
        auto* outputs = buffer.getWritePointer(numChans);
        
        detuneSmooth.setTargetValue(apvts.getRawParameterValue("Detune")->load());
        dryWetSmooth.setTargetValue(apvts.getRawParameterValue("Wet")->load());
        HzSmooth.setTargetValue(apvts.getRawParameterValue("Voices")->load());
        rangeSmooth.setTargetValue(apvts.getRawParameterValue("Range")->load());
        offsetSmooth.setTargetValue(apvts.getRawParameterValue("Offset Hz")->load());
        gainAmp[numChans]->gainParameter[numChans]->setTargetValue(apvts.getRawParameterValue("Amp")->load());
        wetAmp[numChans]->gainParameter[numChans]->setTargetValue(apvts.getRawParameterValue("Wet")->load());
        for(int i = 0; i < buffer.getNumSamples(); i++){
            double freq = pfreq(detuneSmooth.getNextValue() * 0.1f, 100.f);
           
            
            
            switch (static_cast<int>(apvts.getRawParameterValue("Voices")->load())) {
                case 12:
                    gainAmp[numChans]->savestage(
                    detunerOne[numChans]->detuneDelay(inputs[i], freq * rangeSmooth.getNextValue(),numChans,0) +
                    detunerTwo[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.001f,numChans,0)  +
                    detunerThree[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.002f,numChans,0) +
                    detunerFour[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.003f,numChans,0) +
                                                 
                    detunerFive[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.004f,numChans,0) +
                    detunerSix[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.005f,numChans,0) +
                    detunerSeven[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.006f,numChans,0) +
                    detunerEight[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.007f,numChans,0) +
                                                 
                    detunerNine[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.008f,numChans,0) +
                    detunerTen[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.009f,numChans,0) +
                    detunerEleven[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.010f,numChans,0) +
                    detunerTwelve[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.011f,numChans,0),numChans);
                    break;
                case 8:
                    gainAmp[numChans]->savestage(
                    detunerOne[numChans]->detuneDelay(inputs[i], freq * rangeSmooth.getNextValue(),numChans,0) +
                    detunerTwo[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.001f,numChans,0)  +
                    detunerThree[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.002f,numChans,0) +
                    detunerFour[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.003f,numChans,0) +
                    detunerFive[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.004f,numChans,0) +
                    detunerSix[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.005f,numChans,0) +
                    detunerSeven[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.006f,numChans,0) +
                    detunerEight[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.007f,numChans,0) 
                    ,numChans);
                    break;
                case 4:
                    gainAmp[numChans]->savestage(
                    detunerOne[numChans]->detuneDelay(inputs[i], freq * rangeSmooth.getNextValue(),numChans,0) +
                    detunerTwo[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.001f,numChans,0)  +
                    detunerThree[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.002f,numChans,0) +
                    detunerFour[numChans]->detuneDelay(inputs[i], (freq + offsetSmooth.getNextValue())  * rangeSmooth.getNextValue() + 0.003f,numChans,0),numChans);
                    break;
            }
            outputs[i] = wetAmp[numChans]->offsetgianprocess(inputs[i], numChans) + wetAmp[numChans]->gainprocess(gainAmp[numChans]->returnstage(numChans), numChans) * gainAmp[numChans]->gainParameter[numChans]->getNextValue();
            
        }
    }
}

//==============================================================================
bool DetuneZenAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DetuneZenAudioProcessor::createEditor()
{
    return new DetuneZenAudioProcessorEditor (*this);
}

//==============================================================================
void DetuneZenAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::MemoryOutputStream mos (destData, true);
          apvts.state.writeToStream(mos);
}

void DetuneZenAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
              if(tree.isValid() )
              {
                  apvts.replaceState(tree);
              }
}
juce::AudioProcessorValueTreeState::ParameterLayout
DetuneZenAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("Detune",
                                                          "Detune",0.01f,1.f,0.25f));
    layout.add(std::make_unique<juce::AudioParameterInt>("Voices",
                                                          "Voices",4,12,4));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Wet",
                                                          "Wet",0.001f,1.f,0.6f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Amp",
                                                          "Amp",0.001f,1.f,0.61f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Range",
                                                          "Range",0.1f,1.f,0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("Offset Hz",
                                                          "Offset Hz",0.001f,1.f,0.5f));
    
    return layout;
}


//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DetuneZenAudioProcessor();
}
