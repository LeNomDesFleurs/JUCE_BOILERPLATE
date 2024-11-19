#pragma once
#include <JuceHeader.h>

class EmptyKnob : public juce::LookAndFeel_V4 {
 public:
  EmptyKnob() {};
  void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
                        float sliderPos, const float rotaryStartAngle,
                        const float rotaryEndAngle,
                        juce::Slider& slider) override {};
  void drawLinearSlider(Graphics&, int x, int y, int width, int height,
                        float sliderPos, float minSliderPos, float maxSliderPos,
                        Slider::SliderStyle, Slider&) override {};
};

class PlaceHolder : public juce::LookAndFeel_V4 {
 public:
  PlaceHolder() {};
  void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
                        float sliderPos, const float rotaryStartAngle,
                        const float rotaryEndAngle,
                        juce::Slider& slider) override {
    juce::Path p;
    p.addRectangle(x, y, width, height);
    g.setColour(juce::Colour::fromString("40800000"));
    g.fillPath(p);
  };
};