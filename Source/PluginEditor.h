/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Zen_Knob.h"

//==============================================================================
/**
*/
class DetuneZenAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DetuneZenAudioProcessorEditor (DetuneZenAudioProcessor&);
    ~DetuneZenAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DetuneZenAudioProcessor& audioProcessor;
    juce::Zen_Knob detuneSlider;
    juce::Zen_Knob HzSlider;
    juce::Zen_Knob drywetSlider;
    juce::Zen_Knob ampSlider;
    juce::Zen_Knob delaySlider;
    juce::Zen_Knob deviationSlider;
    using APVTS = juce::AudioProcessorValueTreeState;
        using Attachment = APVTS::SliderAttachment;
    Attachment detuneAttachment, voicesAttachment, wetAttachment, ampAttachment, delayAttachment, deviationAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetuneZenAudioProcessorEditor)
};
