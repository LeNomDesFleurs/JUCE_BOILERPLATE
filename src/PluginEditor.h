/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"
#include "LookAndFeel.h"

//==============================================================================
/**
 */
class TestpluginAudioProcessorEditor : public juce::AudioProcessorEditor, public juce::Timer {
 public:
  TestpluginAudioProcessorEditor(TestpluginAudioProcessor &);
  ~TestpluginAudioProcessorEditor() override;
void timerCallback() override;
  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;
  std::vector<juce::Slider*> getComps();

 private:
  EmptyKnob empty_knob_lf;
  PlaceHolder place_holder_lf;
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  TestpluginAudioProcessor &audioProcessor;
  std::unique_ptr<juce::Drawable> svgimg;

  juce::Slider DryWetSlider;

  using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
  std::unique_ptr<Attachment> DryWetAttachment;


  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TestpluginAudioProcessorEditor)
};
