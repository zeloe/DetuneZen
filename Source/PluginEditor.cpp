/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DetuneZenAudioProcessorEditor::DetuneZenAudioProcessorEditor (DetuneZenAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
detuneSlider("Detune", 0, 1, 0.1, 0),
HzSlider("Hz", 0, 1, 0.1, 0),
drywetSlider("DryWet", 0, 1, 0.1, 0),
ampSlider("Amp",0,1,0.1,0),
delaySlider("Delay",0,1,0.1,0),
deviationSlider("Deviation",0,1,0.1,0),
detuneAttachment(audioProcessor.apvts, "Detune", detuneSlider),
voicesAttachment(audioProcessor.apvts, "Voices", HzSlider),
wetAttachment(audioProcessor.apvts, "Wet", drywetSlider),
ampAttachment(audioProcessor.apvts, "Amp", ampSlider),
delayAttachment(audioProcessor.apvts,"Range", delaySlider),
deviationAttachment(audioProcessor.apvts,"Offset Hz", deviationSlider)


{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 450);
    setResizeLimits(700, 450, 900, 650);
    setResizable(true, true);
    //getConstrainer()->setFixedAspectRatio(1.0);
    detuneSlider.setStyles(juce::Zen_Knob::ZenStyles::blueknob);
    detuneSlider.setTextValueSuffix(" Detune");
    detuneSlider.setRange(0.01f, 1.0f,0.01f);
    addAndMakeVisible(&detuneSlider);
    
    HzSlider.setStyles(juce::Zen_Knob::ZenStyles::redknob);
    HzSlider.setTextValueSuffix(" Voices");
    HzSlider.setRange(4,12,4);
    addAndMakeVisible(&HzSlider);
    
    drywetSlider.setStyles(juce::Zen_Knob::ZenStyles::greenknob);
    drywetSlider.setTextValueSuffix(" Wet");
    drywetSlider.setRange(0.00f, 1.f,0.001f);
    addAndMakeVisible(&drywetSlider);
    
    ampSlider.setStyles(juce::Zen_Knob::ZenStyles::whiteknob);
    ampSlider.setTextValueSuffix(" Amp");
    ampSlider.setRange(0.01f, 1.f,0.001f);
    addAndMakeVisible(&ampSlider);
    
    delaySlider.setStyles(juce::Zen_Knob::ZenStyles::brownknob);
    delaySlider.setTextValueSuffix(" Range");
    delaySlider.setRange(0.1f, 1.f,0.01f);
    addAndMakeVisible(&delaySlider);
    
    deviationSlider.setStyles(juce::Zen_Knob::ZenStyles::lightblueknob);
    deviationSlider.setTextValueSuffix(" Offset Hz");
    deviationSlider.setRange(0.f, 1.f,0.001f);
    addAndMakeVisible(&deviationSlider);
    
}

DetuneZenAudioProcessorEditor::~DetuneZenAudioProcessorEditor()
{
    
}

//==============================================================================
void DetuneZenAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);
   
}

void DetuneZenAudioProcessorEditor::resized()
{
    
    auto bounds = getLocalBounds();
    auto width = bounds.getWidth();
    auto height = bounds.getHeight();
       
    auto offset_x =  width / 10 - 10;
    auto offset_y = height / 10 ;
    
    
    detuneSlider.setBounds(offset_x, offset_y * 2, offset_x * 2, offset_x * 2);
    HzSlider.setBounds(offset_x * 7, offset_y * 2, offset_x * 2, offset_x * 2);
    ampSlider.setBounds(offset_x, offset_y * 6, offset_x * 2, offset_x * 2);
    drywetSlider.setBounds(offset_x * 7,offset_y * 6,offset_x * 2,offset_x * 2);
    delaySlider.setBounds(offset_x * 4,offset_y * 2,offset_x * 2,offset_x * 2);
    deviationSlider.setBounds(offset_x * 4,offset_y * 6,offset_x * 2,offset_x * 2);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
