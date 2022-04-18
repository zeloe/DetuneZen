/*
  ==============================================================================

    Zen_LookAndFeel.cpp
    Created: 22 Feb 2022 7:39:26pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#include "Zen_LookAndFeel.h"
namespace juce
{
Zen_GreenKnob::Zen_GreenKnob()
{
}

Zen_GreenKnob::~Zen_GreenKnob()
{
}
void Zen_GreenKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::green);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
  //  g.setColour (juce::Colours::green);
  //  g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}
Zen_RedKnob::Zen_RedKnob()
{
}

Zen_RedKnob::~Zen_RedKnob()
{
}
void Zen_RedKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::red);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
  //  g.setColour (juce::Colours::red);
  //  g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}
Zen_BlueKnob::Zen_BlueKnob()
{
}

Zen_BlueKnob::~Zen_BlueKnob()
{
}
void Zen_BlueKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::blue);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
   // g.setColour (juce::Colours::blue);
   // g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}

Zen_WhiteKnob::Zen_WhiteKnob()
{
}

Zen_WhiteKnob::~Zen_WhiteKnob()
{
}
void Zen_WhiteKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::white);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
   // g.setColour (juce::Colours::blue);
   // g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}


Zen_BrownKnob::Zen_BrownKnob()
{
}

Zen_BrownKnob::~Zen_BrownKnob()
{
}
void Zen_BrownKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::brown);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
   // g.setColour (juce::Colours::blue);
   // g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius ;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}


Zen_LightBlueKnob::Zen_LightBlueKnob()
{
}

Zen_LightBlueKnob::~Zen_LightBlueKnob()
{
}
void Zen_LightBlueKnob::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                   const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
        
    auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
    auto centreX = (float) x + (float) width  * 0.5f;
    auto centreY = (float) y + (float) height * 0.5f;
    auto rx = centreX - radius;
    auto ry = centreY - radius;
    auto rw = radius * 2.0f;
    auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
// fill
    g.setColour (juce::Colours::lightblue);
    g.fillEllipse (rx, ry, rw, rw);
             
// outline
    g.setColour (juce::Colours::black);
    g.drawEllipse (rx, ry, rw, rw, 2.0f);
            
// outline2 lines
   // g.setColour (juce::Colours::blue);
   // g.drawRect(g.getClipBounds());
//  body
    juce::Path p;
    auto pointerLength = radius;
    auto pointerThickness = 3.0f;
    p.addRectangle (-pointerThickness , -radius, pointerThickness, pointerLength / 2.f);
    p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            
    // pointer
    g.setColour (juce::Colours::black);
    g.fillPath (p);
}


}
